#ifndef _INTERNALS_H
#define _INTERNALS_H

#include "lpc_types.h"
#include "lpc17xx_i2c.h"
/*Handles communications with the RoboVero.*/


int flush(void);
int connect(void);
void disconnect(void);
void listen(void);
void getReturn(void);
/*
def isr(IRQn):
	"""When an interrupt occurs, call the ISR then clear and reenable
	the interrupt.
	"""
	with robovero.lock:
		if IRQn in isr_list:
			isr_list[IRQn]()
		else:
			robovero.debug.write("[%f] INTERRUPT: unhandled!" % (time.time() - robovero.start_time))
			return
		robocaller("NVIC_ClearPendingIRQ", "void", IRQn)
		robocaller("NVIC_EnableIRQ", "void", IRQn)
*/	
int robocaller(char* function, char* ret_type);
int robocaller(char* function, char* ret_type, int arg1);
int robocaller(char* function, char* ret_type, int arg1, int arg2);
int robocaller(char* function, char* ret_type, int arg1, int arg2, int arg3);
Status robocaller(char* function, char* ret_type, LPC_I2C_TypeDef*, I2C_M_SETUP_Type*, I2C_TRANSFER_OPT_Type);
/*
########################################################################
# These functions are for internal use and not part of the NXP
# peripheral library
########################################################################
*/
//int getIndex(int fcn);
		
//int getStatus(void);

//int malloc(int size);
//int free(int ptr);
//int deref(int ptr, int size, int val=None);

//int resetConfig(void);
/*
class cstruct(object);
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
*/
/*
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
*/
/*
# These functions get called once when a peripheral driver module is 
# imported. A serial connection to the device is established.
robovero = Robovero()
robovero.startListening()
atexit.register(resetConfig)
*/

#endif
