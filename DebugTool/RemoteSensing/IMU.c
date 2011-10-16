//Example application that outputs accelerometer, compass and gyro readings.

#include "include/extra.h"
//from robovero.extras import Array, roboveroConfig
#include "include/drivers/lpc17xx_i2c.h"
//from robovero.lpc17xx_i2c import I2C_M_SETUP_Type, I2C_MasterTransferData, \ I2C_TRANSFERT_OPT_Type

#include "include/drivers/lpc17xx_gpio.h"
//from robovero.lpc17xx_gpio import GPIO_ReadValue
#include "include/core/lpc17XX.h"
//from robovero.LPC17xx import LPC_I2C0
#include "include/drivers/lpc_types.h"
//from robovero.lpc_types import Status
#include <time.h>
//import time

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

class I2CDevice{
	public:
		void init(int address){
			tx_data = [2, 1];
			rx_data = [1, 1];
			config.sl_addr7bit = address;
			config.tx_data = *tx_data;
			config.retransmission_max = 3;
		}
		
		int readReg(uint8_t reg){
			tx_data[0] = reg;
			config.tx_length = 1;
			config.rx_data = *rx_data;
			config.rx_length = 1;
			Status ret = I2C_MasterTransferData(LPC_I2C0, *config, I2C_TRANSFERT_OPT_Type.I2C_TRANSFERT_POLLING);
			if(ret == ERROR)
				return 0;
			return self.rx_data[0];
		}
		
		void writeReg(uint8_t reg,uint8_t value){
			tx_data[0] = reg;
			tx_data[1] = value;
			config.tx_length = 2;
			config.rx_data = 0;
			config.rx_length = 0;
			Status ret = I2C_MasterTransferData(LPC_I2C0, *config, I2C_TRANSFER_OPT_Type.I2C_TRASNFERT_POLLING);
			if(ret == ERROR){
				printf("i2c transfert error\n");
				return 0;
			}
			if(readReg(reg) != value){
				printf("I2C Verification Error\n");
				return 0;
			}
			return 0;
		}
	private:
	I2C_M_SETUP_Type config;
	uint8_t tx_data[2];
	uint8_t rx_data[2];

		
};

int twosComplement(char low_byte, char high_byte){
	return (((low_byte + (high_byte << 8)) );
}

int main(){
	//# Initialize pin select registers
	_roboveroConfig()

	//# configure accelerometer
	I2CDevice accelerometer;
	accelerometer.init(0x18);
	accelerometer.writeReg(ACCEL_CTRL_REG1, 0x27);

	//# configure compass
	I2CDevice compass;
	compass.init(0x1E);
	compass.writeReg(COMPASS_NR_REG, 0)//	# continuous measurement mode

	//# configure the gyro
	//# see L3G4200D Application Note for initialization procedure
	I2CDevice gyro;
	gyro.init(0x68);
	gyro.writeReg(GYRO_CTRL_REG3, 0x08)// # enable DRDY
	gyro.writeReg(GYRO_CTRL_REG4, 0x80)// # enable block data read mode
	gyro.writeReg(GYRO_CTRL_REG1, 0x09)//	# normal mode, enable x-axis

	//main loop
	while(1){
		printf("a [x, y, z]:%d, %d, %d\n",
		twosComplement(accelerometer.readReg(ACCEL_X_LOW), accelerometer.readReg(ACCEL_X_HIGH)),
		twosComplement(accelerometer.readReg(ACCEL_Y_LOW), accelerometer.readReg(ACCEL_Y_HIGH)),
		twosComplement(accelerometer.readReg(ACCEL_Z_LOW), accelerometer.readReg(ACCEL_Z_HIGH)));

		printf("c [x, y, z]:%d, %d, %d\n ",
		twosComplement(compass.readReg(COMPASS_X_LOW), compass.readReg(COMPASS_X_HIGH)),
		twosComplement(compass.readReg(COMPASS_Y_LOW), compass.readReg(COMPASS_Y_HIGH)),
		twosComplement(compass.readReg(COMPASS_Z_LOW), compass.readReg(COMPASS_Z_HIGH)));
		
		printf("g [x, y, z]:%d, %d, %d\n ",
		twosComplement(gyro.readReg(GYRO_X_LOW), gyro.readReg(GYRO_X:HIGH)),
		twosComplement(gyro.readReg(GYRO_Y_LOW), gyro.readReg(GYRO_Y_HIGH)),
		twosComplement(gyro.readReg(GYRO_Z_LOW), gyro.readReg(GYRO_Z_HIGH)));
	
		printf("------------------------------------\n");
}
//	time.sleep(1)


