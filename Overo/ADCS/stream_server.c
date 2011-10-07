/**
 * stream_server.c:
 * OpenCV video streaming server
 *
 * Author  Nash <me_at_nashruddin.com>
 *
 * See the tutorial at 
 * http://nashruddin.com/StrEAMinG_oPENcv_vIdEos_ovER_tHe_nEtWoRk
 */

#define _WIFI_CONFIG
#define _COLOR

#include "stream_server.h"

#include "callback.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <cv.h>
#include <highgui.h>

//include IP stage
#include "IP.h"

#ifdef _DEBUG
//now add stuff for measuring
//#include <time.h>
#include <sys/time.h>
#endif

//include SIPP
//#include "sipp/sipp.h"
//#include "sipp/protocols/VlProto.h"

//#include "comm.h"

clock_t start, finish;
double timeOut;

#define PORT 8888

CvCapture*	capture;
static IplImage*	img0;
static IplImage*	img1;
static IplImage*       imgReduced;
static int x;
static int y;
static int nbPix;
#ifndef _COLOR
static IplImage*       imgSend;
#else
static IplImage*	imgSendCh1;
static IplImage*       imgSendCh2;
static IplImage*       imgSendCh3;
#endif

int FrameTaken = 0;

int			is_data_ready = 0;
int			serversock, clientsock;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* streamServer(void* arg);
void  quit(char* msg, int retval);


int main(int argc, char** argv)
{
	cb_createConnection();
	pthread_t 	thread_s;
	int			key;
	CvCapture* capture = NULL;
	
	if (argc == 2) {
		capture = cvCaptureFromFile(argv[1]);
	} else {
		capture = cvCaptureFromCAM(0);
	}

	if (!capture) {
		quit("cvCapture failed", 1);
	}

	img0 = cvQueryFrame(capture);
	img1 = cvCreateImage(cvGetSize(img0), IPL_DEPTH_8U, 1);
#ifndef _COLOR
	imgSend = cvCreateImage(cvSize(img0->width/2,img0->height/2),IPL_DEPTH_8U,1);
#else
	imgSendCh1 = cvCreateImage(cvSize(img0->width/2,img0->height/2),IPL_DEPTH_8U,1);
	imgSendCh2 = cvCreateImage(cvSize(img0->width/2,img0->height/2),IPL_DEPTH_8U,1);
	imgSendCh3 = cvCreateImage(cvSize(img0->width/2,img0->height/2),IPL_DEPTH_8U,1);
#endif
	imgReduced = cvCreateImage(cvSize(img0->width/2,img0->height/2),IPL_DEPTH_8U,img0->nChannels);


	cvZero(img1);
#ifndef _COLOR
	cvZero(imgSend);
#else
	cvZero(imgSendCh1);
 	cvZero(imgSendCh2);
 	cvZero(imgSendCh3);
#endif
        cvZero(imgReduced);

//now init image for IP
	IP_init(imgReduced);

//create server
	//VlHub server;

//now init SIPP
        //sipp_Setup(&VL_Proto, &sendData, &flushData);

//	cvNamedWindow("stream_server", CV_WINDOW_AUTOSIZE);

	/* print the width and height of the frame, needed by the client */
	fprintf(stdout, "width:  %d\nheight: %d\n\n", img0->width, img0->height);
	fprintf(stdout, "Press 'q' to quit.\n\n");

	/* run the streaming server as a separate thread */
	if (pthread_create(&thread_s, NULL, streamServer, NULL)) {
		quit("pthread_create failed.", 1);
	}

	while(key != 'q') {
		/*send a trig signal*/
		cb_sendTrig();
		/* get a frame from camera */
		img0 = cvQueryFrame(capture);
		if (!img0) break;
		img0->origin = 0;
		cvFlip(img0, img0, -1);
		//beware, sent image is rotated of 90°
		/**
		 * convert to grayscale 
		 * note that the grayscaled image is the image to be sent to the client 
		 * so we enclose it with pthread_mutex_lock to make it thread safe 
		 */
		pthread_mutex_lock(&mutex);
		//now reduce size
		
		cvPyrDown( img0, imgReduced, CV_GAUSSIAN_5x5);
		
#ifndef _COLOR
		cvCvtColor(imgReduced, imgSend, CV_BGR2GRAY);
		
#endif
		IP_stage(imgReduced, &y, &x, &nbPix);
		y = -y;
		x = -x;
		//printf("nbPix: %d\n",nbPix);
		//now send result to aeropic via SIPP
		cb_sendData(x,y,nbPix);
		//printf("x: %d, y: %d, nb: %d\n",x,y,nbPix);
	
#ifdef _WIFI_CONFIG
		FrameTaken++;
		if(FrameTaken == 10) FrameTaken = 0;
		if(!FrameTaken){ 
#endif
			//do this only befor sending
		//	cvPyrDown( img0, imgReduced, CV_GAUSSIAN_5x5);
#ifndef _COLOR
			cvCvtColor(imgReduced, imgSend, CV_BGR2GRAY);
#else
			IP_split(imgReduced, imgSendCh1, imgSendCh2, imgSendCh3);
#endif

			is_data_ready = 1;
#ifdef _WIFI_CONFIG
		}
#endif
		pthread_mutex_unlock(&mutex);

		/* also display the video here on server */
//		cvShowImage("stream_server", img0);
		key = cvWaitKey(30);
		//printf("end of loop\n");
	}

	/* user has pressed 'q', terminate the streaming server */
	if (pthread_cancel(thread_s)) {
		quit("pthread_cancel failed.", 1);
	}

	/* free memory */
//	cvDestroyWindow("stream_server");
	quit(NULL, 0);
}

/**
 * This is the streaming server, run as a separate thread
 * This function waits for a client to connect, and send the grayscaled images
 */ 
void* streamServer(void* arg)
{
	struct sockaddr_in server;

	/* make this thread cancellable using pthread_cancel() */
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

	/* open socket */
        if ((serversock = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
		quit("socket() failed", 1);
        }

	/* setup server's IP and port */
	printf("family : %d\n",AF_INET);
	printf("PORT : %d\n",PORT);
	printf("addr : %d\n",INADDR_ANY);
	
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;
	
	/* bind the socket */
	if (bind(serversock, (const void*)&server, sizeof(server)) == -1) {
		quit("bind() failed", 1);
	}
	printf("wait for client\n");
	/* wait for connection */
	if (listen(serversock, 10) == -1) {
		quit("listen() failed.", 1);
	}
	
	printf("client accepted\n");
	/* accept a client */
	if ((clientsock = accept(serversock, NULL, NULL)) == -1) {
		quit("accept() failed", 1);
	}
	printf("after client accept\n");
	/* the size of the data to be sent */
#ifndef _COLOR
	int imgsize = imgSend->imageSize;
#else
	int imgsize = imgSendCh1->imageSize;
#endif

#ifdef _COLOR
	printf("color mode");
#else
	printf("mono mode");
#endif
#ifdef _WIFI_CONFIG
	printf(" with Wifi optimisation\n");
#else
	printf(" without Wifi optimisation\n");
#endif
	int bytes, i;
		
	/* start sending images */
	while(1) 
	{
		/* send the grayscaled frame, thread safe */
		pthread_mutex_lock(&mutex);
		if (is_data_ready) {
#ifndef _COLOR
			bytes = send(clientsock, imgSend->imageData,imgsize, 0);
#else
		char confirmation[6];
//		char* confirmation;
//		confirmation = (char*)malloc(sizeof(char));
		confirmation[0] = x/128;
		confirmation[1] = x - 128*confirmation[0];
		confirmation[2] = y/128;
		confirmation[3] = y - 128*confirmation[2];
		confirmation[4] = nbPix/128; //high
		confirmation[5] = nbPix-128*confirmation[4]; //low
		//printf("low: %d, high: %d\n", confirmation[3], confirmation[2]);
//		*confirmation = 5;
		//printf("sizeof %d\n",sizeof(confirmation[0]));		

		bytes = send(clientsock, confirmation, sizeof(confirmation), 0);	
			
//		free(confirmation);	
		
		bytes = send(clientsock, imgSendCh1->imageData,imgsize, 0);
		
		bytes = send(clientsock, imgSendCh2->imageData,imgsize, 0);
		
		bytes = send(clientsock, imgSendCh3->imageData,imgsize, 0);
#endif

			//bytes = 0;
			//int packet_size = imgsize/10;
			//for(;bytes<imgsize;){
				
			//	bytes += send(clientsock,imgSend->imageData + bytes, packet_size,0);
			//}		
	
			
			is_data_ready = 0;
		}
		pthread_mutex_unlock(&mutex);
				
		/* if something went wrong, restart the connection */
		if (bytes != imgsize) {
			//We arrive here if we try to use VLC
			fprintf(stderr, "Connection closed.\n");
			close(clientsock);

			if ((clientsock = accept(serversock, NULL, NULL)) == -1) {
				quit("accept() failed", 1);
			}
		}

		/* have we terminated yet? */
		pthread_testcancel();

		/* no, take a rest for a while */
		//usleep(1000);
	}
}

/**
 * this function provides a way to exit nicely from the system
 */
void quit(char* msg, int retval)
{
	if (retval == 0) {
		fprintf(stdout, (msg == NULL ? "" : msg));
		fprintf(stdout, "\n");
	} else {
		fprintf(stderr, (msg == NULL ? "" : msg));
		fprintf(stderr, "\n");
	}

	if (clientsock) close(clientsock);
	if (serversock) close(serversock);
	if (capture) cvReleaseCapture(&capture);
	if (img1) cvReleaseImage(&img1);
#ifndef _COLOR
	if (imgSend) cvReleaseImage(&imgSend);
#endif
	pthread_mutex_destroy(&mutex);

	exit(retval);
}

