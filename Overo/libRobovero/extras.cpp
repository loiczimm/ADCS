/*Defines public functions and classes not part of the CMSIS driver library.*/
#include "extras.h"
#include "internals.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
//from internals import robocaller, cstruct, malloc, free, isr_list
/*
class Array(object):
  """Allocates and initializes an array in RoboVero RAM.
  """
  def __init__(self, length, size, values=[]):
    self.length = length
    self.size = size
    self.ptr = malloc(size * length)
    
    # assign the same value to all items
    if type(values) == int:
      for i in range(length):
        self[i] = values
    
    # copy a list of values
    elif type(values) == list:
      for i in range(min(length, len(values))):
        self[i] = values[i]
        
    # convert a string to a list of characters and copy
    elif type(values) == str:
      values = list(values)
      for i in range(min(length, len(values))):
        self[i] = ord(values[i])

  def __getitem__(self, key):
    if key >= self.length:
      raise IndexError
    return robocaller("deref", "int", self.ptr + self.size*key, self.size)

  def __setitem__(self, key, value):
    if key >= self.length:
      raise IndexError
    if type(value) != int:
      raise TypeError
    robocaller("deref", "void", self.ptr + self.size*key, self.size, value)
    
  def __del__(self):
    free(self.ptr)
*/
void communicationInit(void){
//	sleep(0.1);
	robocaller((char*)"",(char*)"void");
//	sleep(0.1);
        robocaller((char*)"promptOff",(char*)"void");
	sleep(0.1);
	flush();

}


int roboveroMalloc(int value){
 return robocaller((char*)"malloc",(char*)"hex",value);
}

int roboveroReturn(void){
 return robocaller((char*)"return",(char*)"hex");
}
int roboveroConfig(void){
/*Configure the microcontroller pin select registers according to the labels
  on the RoboVero board.*/
  return robocaller((char*)"roboveroConfig", (char*)"void");
}

int deref(int ptr, int value, int reg){
 return robocaller((char*)"deref",(char*)"void", ptr, value, reg);
}

int deref(int ptr, int value){
 return robocaller((char*)"deref", (char*)"hex", ptr, value);
}

int heartbeatOn(void){
  /*Flash the onboard LED.*/
  return robocaller((char*)"heartbeatOn", (char*)"void");
}
  
int heartbeatOff(void){
  /*Let user control the onboard LED.*/
  return robocaller((char*)"heartbeatOff", (char*)"void");
}

int initMatch(int ch, int count){
  /*Initialize a PWM match condition.*/
//  return robocaller((char*)"initMatch", (char*)"void", ch, count);
	return 0;
}

int registerCallback(int IRQn, int function){
  /*Register a RoboVero interrupt service routine.
  Pass the IRQ number and function to call when an interrupt occurs.*/
  //isr_list[IRQn] = function;
	return 0;
}
