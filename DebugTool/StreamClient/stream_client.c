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

#include "def.h"

int       is_data_ready = 0;
int       sock;
char*     server_ip;
int       server_port;
int         num;
int pitch, roll, yaw;

int widthReceived, heightReceived;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* streamClient(void* arg);
void  quit(char* msg, int retval);

int main(int argc, char** argv)
{
    pthread_t thread_c;
    int width, height, key;
    num = 0;

    if (argc != 3) {
        quit("Usage: stream_client <server_ip> <server_port>", 0);
    }

    /* get the parameters */
    server_ip   = argv[1];
    server_port = atoi(argv[2]);

    /* run the streaming client as a separate thread */
    if (pthread_create(&thread_c, NULL, streamClient, NULL)) {
        quit("pthread_create failed.", 1);
    }

    fprintf(stdout, "Press 'q' to quit.\n\n");

    while(key != 'q') {
        /**
         * Display the received image, make it thread safe
         * by enclosing it using pthread_mutex_lock
         */
        pthread_mutex_lock(&mutex);
        if (is_data_ready) {
            num++;
            printf("pitch: %d, roll: %d, yaw: %d \n",pitch, roll,yaw);
            printf("number: %d\n\n",num);
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



    char attitude[3];

    int  i, j, k, bytes;

    /* start receiving images */
    while(1)
    {
        /* get raw data */
       // for (i = 0; i < imgsize; i += bytes) {
            if ((bytes = recv(sock, attitude, sizeof(attitude) , 0)) == -1) {
                quit("recv failed", 1);
            }

            //now send back the values to server


        //}
        /*extract the target coordinate*/

            pitch = attitude[0];
            roll = attitude[1];
            yaw = attitude[2];


            bytes = send(sock,attitude, sizeof(attitude), 0);
        //printf("\n\nbytes: %d\n\n",bytes);
        pthread_mutex_lock(&mutex);

       // is_data_ready = 1;
        if(bytes == sizeof(attitude))
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


    pthread_mutex_destroy(&mutex);

    exit(retval);
}
