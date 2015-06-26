#ifndef DIGITAL_INPUT_H
#define DIGITAL_INPUT_H

#include "Arduino.h"
#include "StateMachine.h"

class DigitalInput : public StateMachine
{
protected:
  DigitalInput(int pinId);
  ~DigitalInput() {};

  int GetState();
  
public:
  virtual void Update(long updateInterval) = 0;
  
  virtual void Reset() = 0;
    
private:
  int m_pinId;
};

#endif
