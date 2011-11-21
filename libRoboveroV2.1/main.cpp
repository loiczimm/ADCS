#include "sensor.h"
#include "extras.h"

#include <time.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//include matlab files
#include "example.h"                   /* Model's header file */
#include "rtwtypes.h"                  /* MathWorks types */

#define EXEC_SPEED 	70	// 50Hz
#define REFRESH_SPEED 	5 	// 5Hz
#define _DEBUG
FILE *out;

struct sigaction old_action;

void sigint_handler(int sig_no)
{
	printf("release sensor\n");
	sensor_stop();
	fclose(out);
	sigaction(SIGINT, &old_action, NULL);
	kill(0, SIGINT);
}

//matlab handler
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = 0;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(example_M, "Overrun");
    return;
  }

  OverrunFlag = TRUE;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  example_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = FALSE;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}


int main(){
 /* Initialize model */
//timer var
//struct timeval tv;
//struct timezone tz;
//struct tm *tm;
//time_t start,end;
clock_t exit;//start, end;
int loop_count = 0;
double dif;
	example_initialize();
	int i=0;
	int j=0;
	//configure for exit
        struct sigaction action, old_action;
        memset(&action, 0, sizeof(action));
        action.sa_handler = &sigint_handler;
        sigaction(SIGINT, &action, &old_action);

	//init sensor
	if(!sensor_init()){
		printf("LPC17 connection fails\n");
		return 0;
	}

	// init output file

	out = fopen("sensor_reading.txt", "w");
	if(out == NULL)
	{ printf("unable to create sensor_reading.txt\n");return 0;}
	fprintf(out, "Frequency: %d\n",  EXEC_SPEED);
	fprintf(out, "ax ay az mx my mz\n");

//	fclose(out);
	int test, para1, para2;
	//main loop
	int timeEnter, timeOut;
	while(1){
		//Compute time of exit
		exit = clock() + (1000/EXEC_SPEED) * CLOCKS_PER_SEC/1000;
		//ask to modify matlab parameters
/*		printf("new matlab parameter\n");
		printf("enter the first parameter:\n");
		scanf("%d",&para1);
		printf("enter the second parameter:\n");
		scanf("%d",&para2);*/
		matlabSet(para1,para2);

		//read sensor
		sensor_step();

		fprintf(out, "-----------------\n%d %s",loop_count, sensor_GetState()->InputStr);
	        fprintf(out, "%d %d %f %f %f %d %d %d\n", 
			sensor_GetState()->i,
			loop_count, 
			sensor_GetState()->accXf,
	                sensor_GetState()->accYf,
	               	sensor_GetState()->accZf,
	             	sensor_GetState()->magX,
	                sensor_GetState()->magY,
	                sensor_GetState()->magZ);

		i++;
		if(i==EXEC_SPEED){
			i = 0;
			j++;
		}
		//update log at REFRESH_SPEED
#ifdef _DEBUG
		if(loop_count >= EXEC_SPEED / REFRESH_SPEED){
			loop_count = 0;
			system("clear");
	//		printf("%s\n\n", sensor_GetState()->InputStr);
			printf("Configuration: Exec speed: %d Hz, Refresh speed: %d Hz\n", EXEC_SPEED, REFRESH_SPEED);
			printf("Freq control (updated at 1/%d): %d\n\n",EXEC_SPEED,j);
			printf("state\n");
			printf("%d\n\n", sensor_GetState()->debugState);
			printf("accelerometer\n");
			printf("x:%f, y:%f, z:%f\n\n",sensor_GetState()->accXf,
							sensor_GetState()->accYf,
							sensor_GetState()->accZf);

			printf("magnetometer\n");
       			printf("x:%d, y:%d, z:%d\n\n",sensor_GetState()->magX,
                        	                        sensor_GetState()->magY,
                                	                sensor_GetState()->magZ);
			printf("gyroscope\n");
        	        printf("x:%d, y:%d, z:%d\n\n",sensor_GetState()->gyrX,
                	                                sensor_GetState()->gyrY,
                        	                        sensor_GetState()->gyrZ);
	 		printf("camera\n");
        	        printf("x1:%d, y1:%d\nx2:%d, y2:%d\nx3:%d, y3:%d\nx4:%d, y4:%d\n",
							sensor_GetState()->camX1,
                        	                        sensor_GetState()->camY1,
                                	                sensor_GetState()->camX2,
							sensor_GetState()->camY2,
                                                	sensor_GetState()->camX3,
	                                                sensor_GetState()->camY3,
        	                                        sensor_GetState()->camX4,
							sensor_GetState()->camY4);

			printf("\n----------------------------------\n");


		}
#endif
		//make a matlab step
		example_step();

		//take back the matlab values
/*		test = matlabGet();
		printf("matlab value %d\n",test);
		if(test > 0){
			printf("you'll make me live\n");
			heartbeatOn();
		}
		else{
			printf("you'll kill me\n");
			heartbeatOff();
		}*/
		//regulate time
                while(clock() < exit);
		loop_count++;
	}
	//finish matlab file
 	/* Terminate model */
	example_terminate();

	return 0;
}
