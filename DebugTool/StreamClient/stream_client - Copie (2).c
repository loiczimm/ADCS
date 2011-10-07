/////////////////////

/**
 * stream_client.c:
 * OpenCV video streaming client
 *
 * Author  Nash <me_at_nashruddin.com>
 *
 * See the tutorial at
 * http://nashruddin.com/StrEAMinG_oPENcv_vIdEos_ovER_tHe_nEtWoRk
 */

#ifdef MINGW32
   //#include <winsock.h>
   #include <winsock2.h>
#else
  #include <netinet/in.h>
   #include <sys/socket.h>
   #include <arpa/inet.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "cv.h"
#include "highgui.h"

#include "def.h"

IplImage* img;
#ifdef _COLOR
    IplImage* imgCh1;
    IplImage* imgCh2;
    IplImage* imgCh3;
#endif
int       is_data_ready = 0;
int       sock;
char*     server_ip;
int       server_port;

int widthReceived, heightReceived;
int frameRecv = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* streamClient(void* arg);
void  quit(char* msg, int retval);

int main(int argc, char** argv)
{
    pthread_t thread_c;
    int width, height, key;
#ifdef _RESIZE
    if (argc != 7) {
        quit("Usage: stream_client <server_ip> <server_port> <width> <height> <widthReceived> <heightReceived>", 0);
    }
#else
    if (argc != 5) {
        quit("Usage: stream_client <server_ip> <server_port> <width> <height>", 0);
    }
#endif

    /* get the parameters */
    server_ip   = argv[1];
    server_port = atoi(argv[2]);
    width       = atoi(argv[3]);
    height      = atoi(argv[4]);
#ifdef _RESIZE
    widthReceived = atoi(argv[5]);
    heightReceived = atoi(argv[6]);
#endif
    /* create image */
#ifndef _COLOR
    img = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
#else
    img = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
    imgCh1 = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
    cvZero(imgCh1);
    imgCh2 = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
    cvZero(imgCh2);
    imgCh3 = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
    cvZero(imgCh3);
#endif
    cvZero(img);

    /* run the streaming client as a separate thread */
    if (pthread_create(&thread_c, NULL, streamClient, NULL)) {
        quit("pthread_create failed.", 1);
    }

    fprintf(stdout, "Press 'q' to quit.\n\n");
    cvNamedWindow("stream_client", CV_WINDOW_AUTOSIZE);

    while(key != 'q') {
        /**
         * Display the received image, make it thread safe
         * by enclosing it using pthread_mutex_lock
         */
        pthread_mutex_lock(&mutex);
        if (is_data_ready) {
            cvShowImage("stream_client", img);
            is_data_ready = 0;
        }
        pthread_mutex_unlock(&mutex);

        key = cvWaitKey(10);
    }

    /* user has pressed 'q', terminate the streaming client */
    if (pthread_cancel(thread_c)) {
        quit("pthread_cancel failed.", 1);
    }

    /* free memory */
    cvDestroyWindow("stream_client");
    quit(NULL, 0);
}

/**
 * This is the streaming client, run as separate thread
 */
void* streamClient(void* arg)
{
    struct  sockaddr_in server;

    /* make this thread cancellable using pthread_cancel() */
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

#ifdef MINGW32
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(1,1), &wsadata) == SOCKET_ERROR) {
    printf("Error creating socket.");
    return;
    }
#endif

    /* create socket */
    if ((sock = socket(PF_INET,SOCK_STREAM, 0)) < 0) {
        quit("socket() failed.", 1);
    }

    /* setup server parameters */
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_port = htons(server_port);

    /* connect to server */
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        quit("connect() failed.", 1);
    }


#ifndef _COLOR
    int  imgsize = img->imageSize;
    char sockdata[imgsize];
#else
    int  imgsize = imgCh1->imageSize;
    char sockdataCh1[imgsize];
    char sockdataCh3[imgsize];
    char sockdataCh2[imgsize];
    char sockdataTarget[4];
#endif
    int  i, j, k, bytes;

    /* start receiving images */
    while(1)
    {
        /* get raw data */
#ifndef _COLOR
        for (i = 0; i < imgsize; i += bytes) {
            if ((bytes = recv(sock, sockdata + i, imgsize - i, 0)) == -1) {
                quit("recv failed", 1);
            }
        }
#else
        do{
            bytes = recv(sock, sockdataTarget, 4, 0);
          //  printf("bytes: %d\n",(int)bytes);
        }
        while(bytes > 4 );
        bytes = 0;
        for (i = 0; i < imgsize; i += bytes) {
            if ((bytes = recv(sock, sockdataCh1 + i, imgsize - i, 0)) == -1) {
                quit("recv failed", 1);
            }
        }
        for (i = 0; i < imgsize; i += bytes) {
            if ((bytes = recv(sock, sockdataCh2 + i, imgsize - i, 0)) == -1) {
                quit("recv failed", 1);
            }
        }
        for (i = 0; i < imgsize; i += bytes) {
            if ((bytes = recv(sock, sockdataCh3 + i, imgsize - i, 0)) == -1) {
                quit("recv failed", 1);
            }
        }
#endif
        /*extract the target coordinate*/

int x = sockdataTarget[0];
int y = sockdataTarget[1];
int nbPix = sockdataTarget[2]*256 + sockdataTarget[3];

printf("x: %d, y: %d, nbPix: %d\n",x,y,nbPix);
//printf("x: %d\n",x);
        /* convert the received data to OpenCV's IplImage format, thread safe */
        pthread_mutex_lock(&mutex);

#ifdef _RESIZE
#ifndef _COLOR
        for (i = 0, k = 0; i < heightReceived; i++) {
            for (j = 0; j < widthReceived; j++) {
                ((uchar*)(img->imageData + (2*i - 1) * img->widthStep))[2*j - 1] = sockdata[k];
                ((uchar*)(img->imageData + (2*i - 1) * img->widthStep))[2*j] = sockdata[k];
                ((uchar*)(img->imageData + (2*i) * img->widthStep))[2*j - 1] = sockdata[k];
                ((uchar*)(img->imageData + (2*i) * img->widthStep))[2*j] = sockdata[k];
                k++;
            }
        }
#else
        for (i = 1, k = 0; i < heightReceived; i++) {
            for (j = 1; j < widthReceived; j++) {
                printf("before\n");
                ((uchar*)(imgCh1->imageData + (2*i - 1) * imgCh1->widthStep))[2*j - 1] = sockdataCh1[k];
                ((uchar*)(imgCh1->imageData + (2*i - 1) * imgCh1->widthStep))[2*j] = sockdataCh1[k];
                ((uchar*)(imgCh1->imageData + (2*i) * imgCh1->widthStep))[2*j - 1] = sockdataCh1[k];
                ((uchar*)(imgCh1->imageData + (2*i) * imgCh1->widthStep))[2*j] = sockdataCh1[k];
                printf("1\n");
                ((uchar*)(imgCh2->imageData + (2*i - 1) * imgCh2->widthStep))[2*j - 1] = sockdataCh2[k];
                ((uchar*)(imgCh2->imageData + (2*i - 1) * imgCh2->widthStep))[2*j] = sockdataCh2[k];
                ((uchar*)(imgCh2->imageData + (2*i) * imgCh2->widthStep))[2*j - 1] = sockdataCh2[k];
                ((uchar*)(imgCh2->imageData + (2*i) * imgCh2->widthStep))[2*j] = sockdataCh2[k];
                printf("2\n");
                ((uchar*)(imgCh3->imageData + (2*i - 1) * imgCh3->widthStep))[2*j - 1] = sockdataCh3[k];
                ((uchar*)(imgCh3->imageData + (2*i - 1) * imgCh3->widthStep))[2*j] = sockdataCh3[k];
                ((uchar*)(imgCh3->imageData + (2*i) * imgCh3->widthStep))[2*j - 1] = sockdataCh3[k];
                ((uchar*)(imgCh3->imageData + (2*i) * imgCh3->widthStep))[2*j] = sockdataCh3[k];
                printf("3\n");
                k++;
            }
        }
        printf("pass\n");
#endif
#else
int sqHigh = y + sqrt(nbPix)/2 + imgCh1->height/2;
int sqLow = y - sqrt(nbPix)/2 + imgCh1->height/2;
int sqLeft = x - sqrt(nbPix)/2 + imgCh1->width/2;
int sqRight = x + sqrt(nbPix)/2 + imgCh1->width/2;

int Cy = y + imgCh1->height/2;
int Cx = x + imgCh1->width/2;


#ifndef _COLOR
        for (i = 0, k = 0; i < img->height; i++) {
            for (j = 0; j < img->width; j++) {
               // for(l = 0; l < 3; l++){
                ((uchar*)(img->imageData + i * img->widthStep))[j] = sockdata[k++];
#else
        for (i = 0, k = 0; i < imgCh1->height; i++) {
            for (j = 0; j < imgCh1->width; j++) {
                if((nbPix > 50) && (((i == sqHigh) || (i == sqLow)) && ((j >= sqLeft) && (j <= sqRight))) ||
                   (((i <= sqHigh) && (i >= sqLow)) && ((j == sqLeft) || (j == sqRight)))){
                    ((uchar*)(imgCh1->imageData + i * imgCh1->widthStep))[j] = 255;
                    ((uchar*)(imgCh2->imageData + i * imgCh2->widthStep))[j] = 0;
                    ((uchar*)(imgCh3->imageData + i * imgCh3->widthStep))[j] = 0;
                }
                else if((nbPix > 50) && ((i <= Cy + 3) && (i >= Cy-3)) && ((j <= Cx + 3) && (j >= Cx -3))){
                    ((uchar*)(imgCh1->imageData + i * imgCh1->widthStep))[j] = 0;
                    ((uchar*)(imgCh2->imageData + i * imgCh2->widthStep))[j] = 255;
                    ((uchar*)(imgCh3->imageData + i * imgCh3->widthStep))[j] = 0;
                }
                else{
                    ((uchar*)(imgCh1->imageData + i * imgCh1->widthStep))[j] = sockdataCh1[k];
                    ((uchar*)(imgCh2->imageData + i * imgCh2->widthStep))[j] = sockdataCh2[k];
                    ((uchar*)(imgCh3->imageData + i * imgCh3->widthStep))[j] = sockdataCh3[k];
                }
                k++;
#endif

            }
        }
#endif

#ifdef _COLOR
    cvMerge(imgCh1,imgCh2,imgCh3,0,img);
#endif

        is_data_ready = 1;
        pthread_mutex_unlock(&mutex);

        /* have we terminated yet? */
        pthread_testcancel();

        /* no, take a rest for a while */
        //usleep(1000);
    }
}

/**
 * This function provides a way to exit nicely from the system
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

    if (sock) close(sock);
    if (img) cvReleaseImage(&img);

    pthread_mutex_destroy(&mutex);

    exit(retval);
}
