#ifndef ANALOG_LED_H
#define ANALOG_LED_H

#include "AnalogOutput.h"

class AnalogLed : public AnalogOutput
{
public:
  AnalogLed(int pinId, int defaultState);  
  ~AnalogLed() {};
  
  virtual void Update(long updateInterval);  
  virtual void Reset();

  void SetState(int newState);
  
private:
  int m_ledDefaultState;
  int m_ledCurrentState;
  int m_pendingState;
};
#endif
