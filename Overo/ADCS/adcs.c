/**
 * stream_server.c:
 * OpenCV video streaming server
 *
 * Author  Nash <me_at_nashruddin.com>
 *
 * See the tutorial at 
 * http://nashruddin.com/StrEAMinG_oPENcv_vIdEos_ovER_tHe_nEtWoRk
 */


#include "adcs.h"



#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#ifdef _DEBUG
//now add stuff for measuring
//#include <time.h>
#include <sys/time.h>
#endif


clock_t start, finish;
double timeOut;

#define PORT 8888

int			is_data_ready = 0;
int			serversock, clientsock;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* streamServer(void* arg);
void  quit(char* msg, int retval);

char attitude[3];
char attitudeBack[3];

int main(int argc, char** argv)
{
	pthread_t 	thread_s;
	int			key;

	fprintf(stdout, "Press 'q' to quit.\n\n");

	/* run the streaming server as a separate thread */
	if (pthread_create(&thread_s, NULL, streamServer, NULL)) {
		quit("pthread_create failed.", 1);
	}

	 char buf[100];
	int pitch = 0;
	int roll = 0;
	int yaw = 0;

	//main loop
	while(1) {
		

//		pthread_mutex_lock(&mutex);
				
		printf("pitch:");
                rewind(stdin);
                fgets(buf,10,stdin);
                sscanf(buf,"%d",&pitch);
 		printf("roll:");
                rewind(stdin);
                fgets(buf,10,stdin);
                sscanf(buf,"%d",&roll);
		 printf("yaw:");
                rewind(stdin);
                fgets(buf,10,stdin);
                sscanf(buf,"%d",&yaw);


		attitude[0] = (char)pitch;
		attitude[1] = (char)roll;
		attitude[2] = (char)yaw;
		is_data_ready = 1;
//		pthread_mutex_unlock(&mutex);

		printf("values received:\n\n");
		printf("%d, %d, %d\n",attitudeBack[0], attitudeBack[1], attitudeBack[2]);
		
		//key = cvWaitKey(30);
		//printf("end of loop\n");
	}

	/* user has pressed 'q', terminate the streaming server */
	if (pthread_cancel(thread_s)) {
		quit("pthread_cancel failed.", 1);
	}

	/* free memory */

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

	int bytes, i;
	//char pitch;	
	

	while(1) 
	{
	
		
		pthread_mutex_lock(&mutex);
		if (is_data_ready) {
			
			bytes = send(clientsock, attitude , sizeof(attitude), 0);
			
			recv(clientsock, attitudeBack, sizeof(attitudeBack), 0);
			is_data_ready = 0;
		}
		pthread_mutex_unlock(&mutex);
				
		/* if something went wrong, restart the connection */
		if (bytes != sizeof(attitude)) {
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
	
	pthread_mutex_destroy(&mutex);

	exit(retval);
}

