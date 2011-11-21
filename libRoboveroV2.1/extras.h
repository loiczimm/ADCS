#ifndef _EXTRAS_H
#define _EXTRAS_H

//#ifdef __cplusplus
//extern "C"
//{
//#endif


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
void communicationInit(void);
int deref(int, int, int);
int deref(int, int);
int roboveroMalloc(int);
int roboveroReturn(void);
int roboveroConfig(void);
int heartbeatOn(void);  
int heartbeatOff(void);
int initMatch(int ch, int count);
int registerCallback(int IRQn, int function);

//#ifdef __cplusplus
//}
//#endif

#endif
