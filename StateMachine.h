#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "Arduino.h"

class StateMachine
{
public:
  StateMachine() {};
  ~StateMachine() {};

  virtual void Update(long updateInterval) = 0;
  virtual void Reset() = 0;  
};

#endif
