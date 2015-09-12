#ifndef RGB_LED_H
#define RGB_LED_H

#include "AnalogLed.h"

class RGBLed : public StateMachine
{
public:
  RGBLed(int redPinId, int greenPinId, int bluePinId);
  ~RGBLed();
  
  virtual void Update(long updateInterval);  
  virtual void Reset();

  void SetColour(int red, int green, int blue);
  
private:
  AnalogLed* m_redLed;
  AnalogLed* m_greenLed;
  AnalogLed* m_blueLed;
};
#endif
