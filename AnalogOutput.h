#ifndef ANALOG_OUTPUT_H
#define ANALOG_OUTPUT_H

#include "Arduino.h"
#include "StateMachine.h"

class AnalogOutput : public StateMachine
{
protected:
  AnalogOutput(int pinId);
  ~AnalogOutput() {};

  void SetState(int newState);
  
public:
  virtual void Update(long updateInterval) = 0;
  
  virtual void Reset() = 0;
    
private:
  int m_pinId;
};

#endif
