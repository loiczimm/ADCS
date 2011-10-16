#ifndef _SENSOR_H
#define _SENSOR_H

typedef struct{

	//accelerometer
	float accX;
	float accY;
	float accZ;

  //magnetometer
        float magX;
        float magY;
        float magZ;

  //gyroscope
        float gyrX;
        float gyrY;
        float gyrZ;

}sensor_State;

int sensor_init();

int sensor_step();

int sensor_stop();

//this function return a pointer to a sensor value
sensor_State * sensor_GetState();

#endif
