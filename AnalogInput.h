#ifndef ANALOG_INPUT_H
#define ANALOG_INPUT_H

#include "Arduino.h"
#include "StateMachine.h"

class AnalogInput : public StateMachine
{
protected:
  AnalogInput(int pinId);
  ~AnalogInput() {};

  int GetState();
  
public:
  virtual void Update(long updateInterval) = 0;
  
  virtual void Reset() = 0;
    
private:
  int m_pinId;
};

#endif
