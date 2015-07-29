#include <LinkedList.h>
#include "Led.h"
#include "MicroSwitch.h"
#include "StateController.h"
#include "Joystick.h"

#define MAX_TIME -1

Led defaultLed(17, HIGH);
MicroSwitch microSwitch(10);
Joystick joystick(0, 1, 9);

StateController stateController;

unsigned long lastUpdate;

void setup() { 
  stateController.Reset();
  
  stateController.Register(&defaultLed);
  stateController.Register(&microSwitch);
  stateController.Register(&joystick);
    
  lastUpdate = micros();
}

void loop()
{
  unsigned long now = micros();
  long updateTime = 0;
  
  if (now < lastUpdate)
  {
    updateTime = now + (MAX_TIME - lastUpdate);
  } else
  {
    updateTime = now - lastUpdate;
  }
  lastUpdate = now;
  
  stateController.Update(updateTime);
  
  defaultLed.SetState(joystick.GetSwitch());
}
