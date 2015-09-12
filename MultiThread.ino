#include <LinkedList.h>
#include "Led.h"
#include "MicroSwitch.h"
#include "StateController.h"
#include "Joystick.h"
#include "RGBLed.h"

#define MAX_TIME -1

Led defaultLed(17, HIGH);
Joystick joystick(0, 1, 15);
RGBLed rgbLed(3, 5, 6);


StateController stateController;

unsigned long lastUpdate;

void setup()
{ 
  stateController.Reset();
  
  stateController.Register(&defaultLed);
  stateController.Register(&joystick);
  stateController.Register(&rgbLed);

  lastUpdate = micros();
}

void loop()
{
  unsigned long now = micros();
  long updateTime = 0;
  
  if (now < lastUpdate) {
    updateTime = now + (MAX_TIME - lastUpdate);
  } else {
    updateTime = now - lastUpdate;
  }
  lastUpdate = now;
  
  stateController.Update(updateTime);
  
  defaultLed.SetState(joystick.GetSwitch());

  int red = joystick.GetXAxis() / 4;
  int green = joystick.GetYAxis() / 4;

  rgbLed.SetColour(red,green,0);
}
