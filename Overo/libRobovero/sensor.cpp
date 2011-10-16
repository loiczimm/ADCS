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


#define ACCEL_CTRL_REG1 0x20
#define ACCEL_X_LOW 0x28
#define ACCEL_X_HIGH 0x29
#define ACCEL_Y_LOW 0x2A
#define ACCEL_Y_HIGH 0x2B
#define ACCEL_Z_LOW 0x2C
#define ACCEL_Z_HIGH 0x2D

#define COMPASS_MR_REG 0x02
#define COMPASS_X_HIGH 0x03
#define COMPASS_X_LOW 0x04
#define COMPASS_Y_HIGH 0x05
#define COMPASS_Y_LOW 0x06
#define COMPASS_Z_HIGH 0x07
#define COMPASS_Z_LOW 0x08

#define GYRO_CTRL_REG1 0x20
#define GYRO_CTRL_REG2 0x21
#define GYRO_CTRL_REG3 0x22
#define GYRO_CTRL_REG4 0x23
#define GYRO_CTRL_REG5 0x24
#define GYRO_CTRL_REG 0x27
#define GYRO_X_LOW 0x28
#define GYRO_X_HIGH 0x29
#define GYRO_Y_LOW 0x2A
#define GYRO_Y_HIGH 0x2B
#define GYRO_Z_LOW 0x2C
#define GYRO_Z_HIGH 0x2D
#define GYRO_FIFO_CTRL_REG 0x2E




static int fd;
char* messageRead;

//struct of the sensors datas
sensor_State sensor_state;

class I2CDevice{
	public:
		void init(int address){
			ptr = I2C_M_SETUP_Type_malloc();
			tx_ptr = roboveroMalloc(2);
			rx_ptr = roboveroMalloc(1);
			I2C_M_SETUP_Type_sl_addr7bit(ptr, address);
			I2C_M_SETUP_Type_tx_data(ptr, tx_ptr);
			I2C_M_SETUP_Type_retransmissions_max(ptr, 3);
		}

		int readReg(uint8_t reg, int conf){

			deref(tx_ptr, 1, reg);

			if(conf){
				I2C_M_SETUP_Type_tx_length(ptr, 1);

				I2C_M_SETUP_Type_rx_data(ptr, tx_ptr+16);

				I2C_M_SETUP_Type_rx_length(ptr, 1);
			}
			I2C_MasterTransferData(ptr, 0);

			int ret = deref(tx_ptr+16, 1);

			if(ret == 0)
                		return 0;
		        return ret;
		}

		int writeReg(uint8_t reg,uint8_t value){
			deref(tx_ptr, 1, reg);

			deref(tx_ptr + 1, 1, value);

			I2C_M_SETUP_Type_tx_length(ptr,2);	//fault

			I2C_M_SETUP_Type_rx_data(ptr, 0);

			I2C_M_SETUP_Type_rx_length(ptr, 0);

			I2C_MasterTransferData(ptr,0);

			int ret = readReg(reg,1);

	       		if(ret!= value){
                		printf("I2C Verification Error\n");
                		return 0;
		        }
		        return 0;
		}

		void release(void){
			printf("releasing memory\n");
			robocaller((char*)"free",(char*)"void", tx_ptr);
			robocaller((char*)"free",(char*)"void", rx_ptr);
			robocaller((char*)"free",(char*)"void", ptr);
		}


	private:
		I2C_M_SETUP_Type config;
		uint32_t ptr, tx_ptr, rx_ptr;
	        uint8_t tx_data[2];
        	uint8_t rx_data[1];
};


I2CDevice accelerometer;
I2CDevice compass;
I2CDevice gyro;


int twosComplement(char low_byte, char high_byte){
	return (((low_byte + (high_byte << 8))));
}


int sensor_init(){
//start to connect to serial port
	fd = connect();
	if(fd == -1)
		return 0;
	sleep(1);
	communicationInit();

	roboveroConfig();


//now create the device
	accelerometer.init(0x18);

	accelerometer.writeReg(ACCEL_CTRL_REG1, 0x27);


//now create tha magnetometers
	compass.init(0x1E);

	compass.writeReg(COMPASS_MR_REG, 0);

//now create the gyros
        gyro.init(0x68);
        gyro.writeReg(GYRO_CTRL_REG3, 0x08);
        gyro.writeReg(GYRO_CTRL_REG4, 0x80);
        gyro.writeReg(GYRO_CTRL_REG1, 0x09);
	
//stop heartbeat
	heartbeatOff();
	
	return 1;
}

int sensor_step(){
	sensor_state.accX = ((float)twosComplement(accelerometer.readReg(ACCEL_X_LOW,0),accelerometer.readReg(ACCEL_X_HIGH,0)))/16384;
	sensor_state.accY = ((float)twosComplement(accelerometer.readReg(ACCEL_Y_LOW,0),accelerometer.readReg(ACCEL_Y_HIGH,0)))/16384;
	sensor_state.accZ = ((float)twosComplement(accelerometer.readReg(ACCEL_Z_LOW,0),accelerometer.readReg(ACCEL_Z_HIGH,0)))/16384;

	sensor_state.magX = twosComplement(compass.readReg(COMPASS_X_LOW,0),compass.readReg(COMPASS_X_HIGH,0));
	sensor_state.magY = twosComplement(compass.readReg(COMPASS_Y_LOW,0),compass.readReg(COMPASS_Y_HIGH,0));
	sensor_state.magZ = twosComplement(compass.readReg(COMPASS_Z_LOW,0),compass.readReg(COMPASS_Z_HIGH,0));
/*
	sensor_state.gyrX = twosComplement(gyro.readReg(GYRO_X_LOW,0),gyro.readReg(GYRO_X_HIGH,0));
	sensor_state.gyrY = twosComplement(gyro.readReg(GYRO_Y_LOW,0),gyro.readReg(GYRO_Y_HIGH,0));
	sensor_state.gyrZ = twosComplement(gyro.readReg(GYRO_Z_LOW,0),gyro.readReg(GYRO_Z_HIGH,0));
*/
	return 1;
}

int sensor_stop(){	
	gyro.release();
	compass.release();
	accelerometer.release();
	disconnect();
	return 0;
}

sensor_State * sensor_GetState(){
	return &sensor_state;
}

