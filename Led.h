#ifndef LED_H
#define LED_H

#include "DigitalOutput.h"

class Led : public DigitalOutput
{
public:
  Led(int pinId, int defaultState);  
  ~Led() {};
  
  virtual void Update(long updateInterval);  
  virtual void Reset();
  
private:
  int m_ledDefaultState;
};
#endif
