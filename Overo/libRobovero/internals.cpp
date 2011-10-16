/*Handles communications with the RoboVero.*/

#include "internals.h"
#include "lpc_types.h"
#include "lpc17xx_i2c.h"

#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>


static int fd;

int connect(){
	char *inter;
	inter = (char*)malloc(100*sizeof(char));
	int i=0;
	for(i=0;i<100;i++){
		sprintf(inter,"/dev/ttyACM%d",i);
        	fd = open(inter, O_RDWR | O_NOCTTY | O_NDELAY);
        	if(fd != -1){
			printf("connected to %s\n",inter);
		        return fd;
		}
	}
	free(inter);
	printf("unable to find robovero\n");
	return -1;
}

void disconnect(void){
	close(fd);
}

void listen(void){

}


void getReturn(void){

}


int robocaller(char* function,char* ret_type){
	/*Serialize a function and it's arguments and send to device.*/
	char message[100];
	sprintf(message,"%s\r\n",function);
	write(fd, message, strlen(message));
	
	if(!strcmp(ret_type, "hex")){
		int ret;
		while(!read(fd,message,10));
//		printf("%s",message);
		sscanf(message, "%x", &ret);
		return ret;
	}
	return 1;
}

int flush(){
	char message[100];
//	while(!read(fd,message,100));
	printf("flush1\n");
	while(read(fd,message,100));
	printf("flush2\n");
	return 1;
}

int robocaller(char* function, char* ret_type, int arg1){
	char message[100];
	sprintf(message,"%s %x", function, arg1);
	return robocaller(message, ret_type);
}	

int robocaller(char* function, char* ret_type, int arg1, int arg2){
	char message[100];
	sprintf(message,"%s %x %x", function, arg1, arg2);
	return robocaller(message, ret_type);
}

int robocaller(char* function, char* ret_type, int arg1, int arg2, int arg3){
	char message[100];
	sprintf(message,"%s %x %x %x",function, arg1, arg2, arg3);
	return robocaller(message, ret_type);
}

Status robocaller(char* function, char* ret_type, LPC_I2C_TypeDef *I2Cx, I2C_M_SETUP_Type *TransfertCfg, I2C_TRANSFER_OPT_Type Opt){
	printf("entering robocaller\n");
	char message[100];
	int mode;
//now add the I2Cx variable
//	printf("values%d", I2Cx.
//now add the TransfertCfg variable

//now add the Opt  variable
	if(Opt == I2C_TRANSFER_POLLING)
		mode = 0;
	else 
		mode = 1;
//	sprintf(message, "%s %s %s %d\r\n", function, I2Cx, TransfertCfg, mode);
//	printf("%s",message);
	printf("leaving robocaller\n");
	write(fd, message, strlen(message));
	read(fd, &message,100);
	printf("message received%s\n", message);
	return SUCCESS;
} 
/*
########################################################################
# These functions are for internal use and not part of the NXP
# peripheral library
########################################################################
*/
int getIndex(int fcn){
	/*Get the table index of a function.*/
	return 0;	
//	return robocaller("search %s" (fcn), "int");
}
/*
		
def getStatus():
	"""Get the error status of the previous function call.
	"""
	return robocaller("return", "int")
	
def malloc(size):
	"""Allocate memory from the heap.
	"""
	return robocaller("malloc", "int", size)
	
def free(ptr):
	"""Free previously allocated memory.
	"""
	return robocaller("free", "void", ptr)

def deref(ptr, size, val=None):
	"""Dereference a pointer.
	"""
	if val:
		return robocaller("deref", "void", ptr, size, val)
	else:
		return robocaller("deref", "int", ptr, size)

def resetConfig():
	"""Simulate a reset condition without losing the usb connection."""
	return robocaller("resetConfig", "void")

class cstruct(object):
	"""A parent class for all structs used by the peripheral library.
	"""
	def __init__(self, **kwargs):
		"""Allocate some memory on the device for the struct.
		"""
		ptr = robocaller("%s_malloc" % self.__class__.__name__, "int")
		if ptr == 0:
			self.__del__()
			return
		self.__dict__["ptr"] = ptr
		for key in kwargs:
			self.__setattr__(key, kwargs[key])

	def __getattr__(self, member):
		"""Get the value of a struct member.
		"""
		ret = robocaller("%s_%s" % (self.__class__.__name__, member), "int",
											self.__dict__["ptr"])
		if getStatus():
			print "ERROR: %s not a member of %s" % (member, 
																								self.__class__.__name__)
		else:
			return ret

	def __setattr__(self, member, value):
		"""Set the value of a struct member.
		"""
		robocaller("%s_%s" % (self.__class__.__name__, member), "void",
								self.__dict__["ptr"], value)
		if getStatus():
			print "ERROR: %s not a member of %s" % (member, 
																								self.__class__.__name__)

	def __del__(self):
		"""Free the memory on the robovero when the struct object goes out
		of scope in Python.
		"""
		free((self.__dict__["ptr"]))


class Robovero(object):
	"""Store information about the USB connection to the device.
	"""	
	def __init__(self):
		"""Open a serial connection to the robovero hardware.
		"""
		
		# look for RoboVeros in /dev
		devices = [dev for dev in os.listdir("/dev/") if "ttyACM" in dev]
		devices.sort()
		num_devs = len(devices)
		idx = 0
		
		# determine which device to connect to
		if num_devs == 0:
			exit("No RoboVero hardware found.")
		elif num_devs > 1:
			for dev in devices:
				print "%d) %s" % (idx, devices[idx])
				idx += 1
			try:
				idx = int(raw_input("\r\nwhich device? "))
				if idx >= num_devs:
					raise ValueError
			except:
				exit("Invalid selection")

		# try to connect
		try:
			self.serial = serial.Serial('/dev/%s' % devices[idx])
		except:
			exit("Couldn't open device.")
		
		self.start_time = time.time()
		self.serial.timeout = 0
		# send line terminator, disable console echo and prompt
		self.serial.write("\r\n")
		self.serial.write("promptOff\r\n")
		# pause to let characters arrive on the serial port
		time.sleep(0.1)
		self.serial.flushInput()

		#	a lock for handling incoming serial data
		self.lock = threading.RLock()

		self.response = None
		self.debug = open("run.log", "w")
		
	def startListening(self):
		"""Spawn a new thread to listen for incoming messages.
		"""
		self.listener = threading.Thread(target=listen, name="listener")
		self.listener.daemon = True
		self.listener.start()
		
	def readline(self, delim):
		"""Get one character at a time until the specified delimiter is found.
		"""
		message = ""
		while delim not in message:
			if not robovero:
				exit()
			try:
				message += self.serial.read(1)
			except:
				self.debug.write("[%f] ERROR: USB connection lost\r\n"  % (time.time() - self.start_time))
				exit("error: USB connection lost")
		return message.strip(delim)
				
	def __del__(self):
		"""Send any remaining data and close the serial connection.
		"""
		self.serial.flush()
		self.serial.close()

# These functions get called once when a peripheral driver module is 
# imported. A serial connection to the device is established.
robovero = Robovero()
robovero.startListening()
atexit.register(resetConfig)
*/
