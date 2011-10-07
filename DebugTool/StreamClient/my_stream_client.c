#ifdef WIN32
  // #include <winsock.h>
   //#include <winsock2.h>
#else
   //#include <sys/socket.h>
   //#include <netinet/in.h>
   //#include <arpa/inet.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "cv.h"
#include "highgui.h"

int main(){

    CvCapture *stream=cvCaptureFromFile("rtsp://10.0.0.131:8554/test");

    char key = 'l';
    IplImage *img = 0;

    img=cvQueryFrame(stream);
    if(!img)
        {
             printf("Bad frame \n");
             exit(0);
        }

    while (key != 'q'){
                img=cvQueryFrame(stream);
        if(!img) break;

        cvShowImage("img",img);
        key = cvWaitKey(10);
         }
         cvDestroyWindow("img");
         cvReleaseCapture(&stream);
         return 0;
}
