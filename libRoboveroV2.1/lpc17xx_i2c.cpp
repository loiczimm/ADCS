/*I2C client library functions. See LPC17xx CMSIS-Compliant Standard 
Peripheral Firmware Driver Library documentation.*/

#include "lpc17xx_i2c.h"

#include "internals.h"
#include "lpc_types.h"
#include "extras.h"

#include <stdlib.h>
#include <stdio.h>
/*
int I2C_MonitorModeCmd(int I2Cx, int NewState){
	return robocaller("I2C_MonitorModeCmd", "void", I2Cx, NewState);
}

int I2C_IntCmd(int I2Cx, int NewState){
	return robocaller("I2C_IntCmd", "void", I2Cx, NewState);
}

int I2C_DeInit(int I2Cx){
	return robocaller("I2C_DeInit", "void", I2Cx);
}

int I2C_SlaveHandler(int I2Cx){
	return robocaller("I2C_SlaveHandler", "void", I2Cx);
}

int I2C_MonitorModeConfig(int I2Cx, int MonitorCfgType, int NewState){
	return robocaller("I2C_MonitorModeConfig", "void", I2Cx, MonitorCfgType, NewState);
}
*/
int I2C_MasterTransferData(int TransferCfg, int Opt){
	return robocaller((char*)"I2C_MasterTransferData 4001C000",(char*) "hex", TransferCfg, Opt);
}

int I2C_M_SETUP_Type_malloc(void){
	return robocaller((char*)"I2C_M_SETUP_Type_malloc",(char*)"hex");
}

int I2C_M_SETUP_Type_sl_addr7bit(int ptr, int address){
	robocaller((char*)"I2C_M_SETUP_Type_sl_addr7bit",(char*)"void", ptr, address);
	return roboveroReturn();
}

int I2C_M_SETUP_Type_tx_data(int ptr, int tx_ptr){
	robocaller((char*)"I2C_M_SETUP_Type_tx_data",(char*)"void", ptr, tx_ptr);
	return roboveroReturn();
}

int I2C_M_SETUP_Type_tx_length(int ptr, int value){
	robocaller((char*)"I2C_M_SETUP_Type_tx_length", (char*)"void", ptr, value);
	printf("txlength\n");
	return roboveroReturn();
}

int I2C_M_SETUP_Type_rx_data(int ptr, int rx_ptr){
        robocaller((char*)"I2C_M_SETUP_Type_rx_data",(char*)"void", ptr, rx_ptr);
        return roboveroReturn();
}

int I2C_M_SETUP_Type_rx_length(int ptr, int value){
        robocaller((char*)"I2C_M_SETUP_Type_rx_length", (char*)"void", ptr, value);
        return roboveroReturn();
}

int I2C_M_SETUP_Type_retransmissions_max(int ptr, int retransmissions_max){
	robocaller((char*)"I2C_M_SETUP_Type_retransmissions_max",(char*)"void", ptr, retransmissions_max);
	return roboveroReturn();
}

/*
int I2C_SlaveTransferComplete(int I2Cx){
	return robocaller("I2C_SlaveTransferComplete", "uint32_t", I2Cx);
}

int I2C_SlaveTransferData(int I2Cx, int TransferCfg, int Opt){
	return robocaller("I2C_SlaveTransferData", "Status", I2Cx, TransferCfg, Opt);
}

int I2C_SetOwnSlaveAddr(int I2Cx, int OwnSlaveAddrConfigStruct){
	return robocaller("I2C_SetOwnSlaveAddr", "void", I2Cx, OwnSlaveAddrConfigStruct);
}

int I2C_MasterTransferComplete(int I2Cx){
	return robocaller("I2C_MasterTransferComplete", "uint32_t", I2Cx);
}

int I2C_MasterHandler(int I2Cx){
	return robocaller("I2C_MasterHandler", "void", I2Cx);
}

int I2C_MonitorHandler(int I2Cx, int buffer, int size){
	return robocaller("I2C_MonitorHandler", "BOOL_8", I2Cx, buffer, size);
}

int I2C_Init(int I2Cx, int clockrate){
	return robocaller("I2C_Init", "void", I2Cx, clockrate);
}

int I2C_MonitorGetDatabuffer(int I2Cx){
	return robocaller("I2C_MonitorGetDatabuffer", "uint8_t", I2Cx);
}

int I2C_GetLastStatusCode(int I2Cx){
	return robocaller("I2C_GetLastStatusCode", "uint8_t", I2Cx);
}

int I2C_Cmd(int I2Cx, int NewState){
	return robocaller("I2C_Cmd", "void", I2Cx, NewState);
}
*/
