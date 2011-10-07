/**
 * stream_server.c:
 * OpenCV video streaming server
 *
 * Author  Nash <me_at_nashruddin.com>
 *
 * See the tutorial at 
 * http://nashruddin.com/StrEAMinG_oPENcv_vIdEos_ovER_tHe_nEtWoRk
 */

#ifdef WIN32
   #include <winsock.h>
   #include <winsock2.h>
#define SocketErrno (WSAGetLastError())
#define bcopy(src,dest,len) memmove(dest,src,len)
#else
   #include <sys/socket.h>
   #include <netinet/in.h>
   #include <arpa/inet.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "cv.h"
#include "highgui.h"

#define PORT 8888

CvCapture*	capture;
IplImage*	img0;
IplImage*	img1;
int			is_data_ready = 0;
int			serversock, clientsock;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* streamServer(void* arg);
void  quit(char* msg, int retval);

int main(int argc, char** argv)
{
	pthread_t 	thread_s;
	int			key;

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

	cvZero(img1);
	cvNamedWindow("stream_server", CV_WINDOW_AUTOSIZE);

	/* print the width and height of the frame, needed by the client */
	fprintf(stdout, "width:  %d\nheight: %d\n\n", img0->width, img0->height);
	fprintf(stdout, "Press 'q' to quit.\n\n");

	/* run the streaming server as a separate thread */
	if (pthread_create(&thread_s, NULL, streamServer, NULL)) {
		quit("pthread_create failed.", 1);
	}

	while(key != 'q') {
		/* get a frame from camera */
		img0 = cvQueryFrame(capture);
		if (!img0) break;

		img0->origin = 0;
		cvFlip(img0, img0, -1);

		/**
		 * convert to grayscale 
		 * note that the grayscaled image is the image to be sent to the client 
		 * so we enclose it with pthread_mutex_lock to make it thread safe 
		 */
		pthread_mutex_lock(&mutex);
		cvCvtColor(img0, img1, CV_BGR2GRAY);
		is_data_ready = 1;
		pthread_mutex_unlock(&mutex);

		/* also display the video here on server */
		cvShowImage("stream_server", img0);
		key = cvWaitKey(30);
	}

	/* user has pressed 'q', terminate the streaming server */
	if (pthread_cancel(thread_s)) {
		quit("pthread_cancel failed.", 1);
	}

	/* free memory */
	cvDestroyWindow("stream_server");
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
        if ((serversock = socket(PF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		quit("socket() failed", 1);
        }

	/* setup server's IP and port */
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;
	
	/* bind the socket */
	if (bind(serversock, (const void*)&server, sizeof(server)) == -1) {
		quit("bind() failed", 1);
	}

	/* wait for connection */
	if (listen(serversock, 10) == -1) {
		quit("listen() failed.", 1);
	}

	/* accept a client */
	if ((clientsock = accept(serversock, NULL, NULL)) == -1) {
		quit("accept() failed", 1);
	}

	/* the size of the data to be sent */
	int imgsize = img1->imageSize;
	int bytes, i;

	/* start sending images */
	while(1) 
	{
		/* send the grayscaled frame, thread safe */
		pthread_mutex_lock(&mutex);
		if (is_data_ready) {
			bytes = send(clientsock, img1->imageData, imgsize, 0);
			is_data_ready = 0;
		}
		pthread_mutex_unlock(&mutex);

		/* if something went wrong, restart the connection */
		if (bytes != imgsize) {
			fprintf(stderr, "Connection closed.\n");
			close(clientsock);

			if ((clientsock = accept(serversock, NULL, NULL)) == -1) {
				quit("accept() failed", 1);
			}
		}

		/* have we terminated yet? */
		pthread_testcancel();

		/* no, take a rest for a while */
		usleep(1000);
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

	pthread_mutex_destroy(&mutex);

	exit(retval);
}

