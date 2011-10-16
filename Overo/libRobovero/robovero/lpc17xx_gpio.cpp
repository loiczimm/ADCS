/*General purpose IO client library functions. See LPC17xx CMSIS-Compliant
Standard Peripheral Firmware Driver Library documentation.*/
#include "lpc17xx_gpio.h"

#include "internals.h"
//from internals import robocaller, cstruct

#include "LPC17xx.h"
//from LPC17xx import LPC_GPIO0_BASE, LPC_GPIO1_BASE, LPC_GPIO2_BASE, \ LPC_GPIO3_BASE, LPC_GPIO4_BASE
/*
#define GPIO0_Byte ((LPC_GPIO0_BASE))
#define GPIO1_Byte ((LPC_GPIO1_BASE))
#define GPIO2_Byte ((LPC_GPIO2_BASE))
#define GPIO3_Byte ((LPC_GPIO3_BASE))
#define GPIO4_Byte ((LPC_GPIO4_BASE))
#define GPIO0_HalfWord ((LPC_GPIO0_BASE))
#define GPIO1_HalfWord ((LPC_GPIO1_BASE))
#define GPIO2_HalfWord ((LPC_GPIO2_BASE))
#define GPIO3_HalfWord ((LPC_GPIO3_BASE))
#define GPIO4_HalfWord ((LPC_GPIO4_BASE))
*/
class GPIO_Byte_TypeDef(cstruct){
	public: int pass;
}

class GPIO_HalfWord_TypeDef(cstruct){
	public: int pass;
}

int FIO_IntCmd(int portNum,int bitValue,int edgeState){
	return robocaller("FIO_IntCmd", "void", portNum, bitValue, edgeState);
}

int GPIO_ClearInt(int portNum, int bitValue){
	return robocaller("GPIO_ClearInt", "void", portNum, bitValue);
}

int GPIO_GetIntStatus(int portNum, int pinNum, int edgeState){
	return robocaller("GPIO_GetIntStatus", "FunctionalState", portNum, pinNum, edgeState);
}

int FIO_HalfWordClearValue(int portNum, int halfwordNum, int bitValue):
	return robocaller("FIO_HalfWordClearValue", "void", portNum, halfwordNum, bitValue);
}

int GPIO_IntCmd(int portNum, int bitValue, int edgeState){
	return robocaller("GPIO_IntCmd", "void", portNum, bitValue, edgeState);
}

int FIO_ClearInt(int portNum, int pinNum){
	return robocaller("FIO_ClearInt", "void", portNum, pinNum);
}

int FIO_ByteSetValue(int portNum, int byteNum, int bitValue){
	return robocaller("FIO_ByteSetValue", "void", portNum, byteNum, bitValue);
}

int GPIO_ReadValue(int portNum){
	return robocaller("GPIO_ReadValue", "uint32_t", portNum);
}

int FIO_ByteSetDir(int portNum, int byteNum, int bitValue, int dir){
	return robocaller("FIO_ByteSetDir", "void", portNum, byteNum, bitValue, dir);
}

int FIO_HalfWordSetDir(int portNum, int halfwordNum, int bitValue, int dir){
	return robocaller("FIO_HalfWordSetDir", "void", portNum, halfwordNum, bitValue, dir);
}

int FIO_SetValue(int portNum, int bitValue){
	return robocaller("FIO_SetValue", "void", portNum, bitValue);
}

int FIO_GetIntStatus(int portNum, int pinNum, int edgeState){
	return robocaller("FIO_GetIntStatus", "FunctionalState", portNum, pinNum, edgeState);
}

int FIO_HalfWordSetValue(int portNum, int halfwordNum, int bitValue){
	return robocaller("FIO_HalfWordSetValue", "void", portNum, halfwordNum, bitValue);
}

int FIO_ByteClearValue(int portNum, int byteNum, int bitValue){
	return robocaller("FIO_ByteClearValue", "void", portNum, byteNum, bitValue);
}

int FIO_ByteReadValue(int portNum, int byteNum){
	return robocaller("FIO_ByteReadValue", "uint8_t", portNum, byteNum);
}

int GPIO_ClearValue(int portNum, int bitValue){
	return robocaller("GPIO_ClearValue", "void", portNum, bitValue);
}

int FIO_ClearValue(int portNum, int bitValue){
	return robocaller("FIO_ClearValue", "void", portNum, bitValue);
}

int FIO_SetDir(int portNum, int bitValue, int dir){
	return robocaller("FIO_SetDir", "void", portNum, bitValue, dir);
}

int FIO_SetMask(int portNum, int bitValue, int maskValue){
	return robocaller("FIO_SetMask", "void", portNum, bitValue, maskValue);
}

int FIO_HalfWordReadValue(int portNum, int halfwordNum){
	return robocaller("FIO_HalfWordReadValue", "uint16_t", portNum, halfwordNum);
}

int FIO_ByteSetMask(int portNum, int byteNum, int bitValue, int maskValue){
	return robocaller("FIO_ByteSetMask", "void", portNum, byteNum, bitValue, maskValue);
}

int FIO_ReadValue(int portNum){
	return robocaller("FIO_ReadValue", "uint32_t", portNum);
}

int GPIO_SetValue(int portNum, int bitValue){
	return robocaller("GPIO_SetValue", "void", portNum, bitValue);
}

int FIO_HalfWordSetMask(int portNum, int halfwordNum, int bitValue, int maskValue){
	return robocaller("FIO_HalfWordSetMask", "void", portNum, halfwordNum, bitValue, maskValue);
}

int GPIO_SetDir(int portNum, int bitValue, int dir){
	return robocaller("GPIO_SetDir", "void", portNum, bitValue, dir);
}
