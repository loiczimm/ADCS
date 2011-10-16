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
		sensor_step();
		system("clear");
		printf("accelerometer\n");
		printf("x:%f, y:%f, z:%f\n",sensor_GetState()->accX,
						sensor_GetState()->accY,
						sensor_GetState()->accZ);
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
