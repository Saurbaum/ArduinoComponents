#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "StateMachine.h"
#include "JoystickAxis.h"
#include "MicroSwitch.h"

class Joystick : public StateMachine
{
public:
  Joystick(int xAxisPinId, int yAxisPinId, int microswitchPinId);  
  ~Joystick();
  
  virtual void Update(long updateInterval);  
  virtual void Reset();

  int GetXAxis();
  int GetYAxis();
  int GetSwitch();
  
private:
  JoystickAxis* m_xAxis;
  JoystickAxis* m_yAxis;
  MicroSwitch* m_microswitch;
};
#endif
