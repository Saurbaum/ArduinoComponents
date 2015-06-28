#ifndef JOYSTICK_AXIS_H
#define JOYSTICK_AXIS_H

#include "AnalogInput.h"

class JoystickAxis : public AnalogInput
{
public:
  JoystickAxis(int pinId);  
  ~JoystickAxis() {};
  
  virtual void Update(long updateInterval);  
  virtual void Reset();

  int GetState();

private:
  int m_currentState;
};
#endif
