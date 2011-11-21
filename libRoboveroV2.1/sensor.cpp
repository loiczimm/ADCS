//Example application that outputs accelerometer, compass and gyro readings.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

#include "sensor.h"
#include "internals.h"
#include "extras.h"
#include "lpc_types.h"
#include "utils.h"

static int fd;
char* messageRead;

//struct of the sensors datas
sensor_State sensor_state;

int sensor_start(){
	char message[100];
        sprintf(message,"ADCS_Start\r\n");
        write(fd, message, strlen(message));
}

int sensor_init(){
//start to connect to serial port
	fd = connect();
	if(fd == -1)
		return 0;
	sleep(1);
	communicationInit();
	heartbeatOff();
//now start the automatic measurements for new lib
	sleep(1);
	sensor_start();
	return 1;
}

int sensor_step(){
	//Serial ask for new sting chain
	char message[100];
	char clr[100];

//	int gyroX, gyroY, gyroZ;
	sprintf(message,"ADCS_Sensor\r\n");
        write(fd, message, strlen(message));
	read(fd,sensor_state.InputStr,100);
	sscanf(sensor_state.InputStr, "ADCS:Acc:%d,%d,%d:Mag:%d,%d,%d:Gyr:%d,%d,%d:Cam:%d,%d,%d,%d,%d,%d,%d,%d:DS:%d\r\n",
		&sensor_state.accX, &sensor_state.accY, &sensor_state.accZ,
		&sensor_state.magX, &sensor_state.magY, &sensor_state.magZ,
//		&gyroX/*sensor_state.gyrX*/, &gyroY/*sensor_state.gyrY*/, &gyroZ/*sensor_state.gyrZ*/,
		&sensor_state.gyrX, &sensor_state.gyrY, &sensor_state.gyrZ,
		&sensor_state.camX1, &sensor_state.camY1,
		&sensor_state.camX2, &sensor_state.camY2,
		&sensor_state.camX3, &sensor_state.camY3,
		&sensor_state.camX4, &sensor_state.camY4,
		&sensor_state.debugState);
	 while(!read(fd,sensor_state.InputStr,100));

	//now convert
	sensor_state.accXf = (float)sensor_state.accX/16384;
        sensor_state.accYf = (float)sensor_state.accY/16384;
        sensor_state.accZf = (float)sensor_state.accZ/16384;

	//now mean gyro
//        sensor_state.gyrX = (int)((49.0*(float)sensor_state.gyrX + (float)gyroX)/50.0);
//        sensor_state.gyrY = (int)((49.0*(float)sensor_state.gyrY + (float)gyroY)/50.0);
//	sensor_state.gyrZ = (int)((49.0*(float)sensor_state.gyrZ + (float)gyroZ)/50.0);

	return 1;
}

int sensor_stop(){	
/*	gyro.release();
	compass.release();
	accelerometer.release();*/
	heartbeatOn();
	disconnect();
	return 0;
}

sensor_State * sensor_GetState(){
	return &sensor_state;
}

