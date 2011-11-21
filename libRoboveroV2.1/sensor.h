#ifndef _SENSOR_H
#define _SENSOR_H

typedef struct{
  //debug state
	int debugState;

  //debug stuffs
	int i;

  //accelerometer
	int accX;
	int accY;
	int accZ;

	float accXf;
	float accYf;
	float accZf;
  //magnetometer
        int magX;
        int magY;
        int magZ;

  //gyroscope
        int gyrX;
        int gyrY;
        int gyrZ;

 //camera
	int camX1;
        int camY1;
        int camX2;
        int camY2;
        int camX3;
        int camY3;
        int camX4;
        int camY4;

//the received string
	char InputStr[100];
}sensor_State;

int sensor_init();

int sensor_step();

int sensor_stop();

//this function return a pointer to a sensor value
sensor_State * sensor_GetState();

#endif
