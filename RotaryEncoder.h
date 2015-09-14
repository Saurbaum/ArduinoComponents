#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include "MicroSwitch.h"

class RotaryEncoder : public StateMachine
{
public:
  RotaryEncoder(int pinAId, int pinBId, int switchId);  
  ~RotaryEncoder();
  
  virtual void Update(long updateInterval);  
  virtual void Reset();

  int GetChange();
  bool GetPressed();
  
private:

  long m_lastUpdate;
	
  MicroSwitch* m_button;
  int m_clockA;
  int m_clockB;

  int m_Last_ClockB_Status;
	int m_Current_ClockB_Status;

  int m_currentChange;
};
#endif
