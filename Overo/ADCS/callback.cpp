//#ifdef __cplusplus
//extern "C"{
//#endif


#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <string.h>

#include "comm.h"


#include <sipp.h>
#include <protocols/VlProto.h>

//SIPP
unsigned char vl_mutex = 0;
VL_Proto vl_lastOutputPacket;
TRIG_Proto vl_lastTrigPacket;
VL_Proto vl_outputPacket;


void VL_HandleOutput(unsigned char id, VL_Proto* packet);
void VL_HandleTrig(unsigned char id, TRIG_Proto* packet);
void VL_HandleState(unsigned char id, STATE_Proto* packet);

// protocol declaration
SIPP_DECLARE(VlProto, sizeof(VL_Proto),
	SIPP_PACKET(STATE_ID, STATE_Proto, &VL_HandleState),
	SIPP_PACKET(STATE_AG_ID, STATE_Proto, &VL_HandleState),
        SIPP_PACKET(STATE_GA_ID, STATE_Proto, 0),
  	SIPP_PACKET(TRIG_ID, TRIG_Proto,0),// &VL_HandleTrig),
	SIPP_PACKET(VL_ID, VL_Proto, 0));//VL_HandleOutput));

void VL_HandleOutput(unsigned char id, VL_Proto* packet){
        if(id != VL_ID)
                return;
        while(vl_mutex)
                ;
        vl_mutex = 1;
  	printf("output\n");
	vl_lastOutputPacket = *packet;
        vl_mutex = 0;
}

void VL_HandleTrig(unsigned char id, TRIG_Proto* packet){
        if(id != VL_ID)
                return;
        while(vl_mutex)
                ;
        vl_mutex = 1;
        vl_lastTrigPacket = *packet;
        vl_mutex = 0;
}

void VL_HandleState(unsigned char id, STATE_Proto* packet){
	std::cout<<"handle\n"<<std::endl;
	if(id != STATE_AG_ID)
		return;
	while(vl_mutex)
		;
	vl_mutex = 1;
	//sipp_SendPacket(STATE_GA_ID, &packet);
	vl_mutex = 0;
	printf("value: %d\n",packet->value);
}


using namespace std;

std::string gTarget = "ser:device=/dev/ttyS0;115200";

#ifdef __cplusplus
extern "C"{
#endif

static VlHub server;

void myCallback(void){
	cout<<"I'm in a C++ function"<<endl;
}

void cb_createConnection(void){
//create server
//	VlHub server;

if(!gTarget.empty()){
	cout << "Connecting: "<< gTarget << endl;
	server.connect(gTarget);
	}

//initialize SIPP
	sipp_Setup(&VlProto, &sendData, &flushData);
}

void cb_sendTrig(void){
	//printf("trig\n");
	TRIG_Proto packet;
	packet.trig = 1;
	sipp_SendPacket(TRIG_ID, &packet);
}

void cb_sendData(int cb_x, int cb_y, int cb_nbPix){
	VL_Proto packet;
	packet.x = cb_x;
	packet.y = cb_y;
	packet.nbPix = cb_nbPix;
	sipp_SendPacket(VL_ID, &packet);
}

#ifdef __cplusplus
}
#endif
