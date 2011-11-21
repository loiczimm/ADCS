#include "sensor.h"
#include "extras.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//include matlab files
#include "example.h"                   /* Model's header file */
#include "rtwtypes.h"                  /* MathWorks types */


struct sigaction old_action;

void sigint_handler(int sig_no)
{
	printf("release sensor\n");
	sensor_stop();
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
	int test, para1, para2;
	//main loop
	while(1){
		//ask to modify matlab parameters
/*		printf("new matlab parameter\n");
		printf("enter the first parameter:\n");	
		scanf("%d",&para1);
		printf("enter the second parameter:\n");
		scanf("%d",&para2);*/
		matlabSet(para1,para2);

		//read sensor
//		system("clear");
		sensor_step();
		i++;
		if(i==100){
			i = 0;
			j++;
		}
		system("clear");
//		printf("%s\n\n", sensor_GetState()->InputStr);
		printf("Freq control (updated at 1/100): %d\n\n",j);
		printf("accelerometer\n");
		printf("x:%d, y:%d, z:%d\n\n",sensor_GetState()->accX,
						sensor_GetState()->accY,
						sensor_GetState()->accZ);

		printf("magnetometer\n");
                printf("x:%d, y:%d, z:%d\n\n",sensor_GetState()->magX,
                                                sensor_GetState()->magY,
                                                sensor_GetState()->magZ);
		printf("gyroscope\n");
                printf("x:%d\n y:%d\n z:%d\n\n",sensor_GetState()->gyrX,
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
			
	}
//finish matlab file
 	/* Terminate model */
	example_terminate();

	return 0;
}
