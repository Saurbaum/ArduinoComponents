#include <LinkedList.h>
#include "Led.h"
#include "MicroSwitch.h"
#include "StateController.h"

#define MAX_TIME -1

Led defaultLed(17, HIGH);
MicroSwitch microSwitch(10);
StateController stateController;

unsigned long lastUpdate;

void setup() {
  Serial.begin(9600);
  
  stateController.Reset();
  
  stateController.Register(&defaultLed);
  stateController.Register(&microSwitch);
  
  lastUpdate = millis();
}

void loop() {
  unsigned long now = millis();
  long updateTime = 0;
  
  if (now < lastUpdate){
    updateTime = now + (MAX_TIME - lastUpdate);
  } else {
    updateTime = now - lastUpdate;
  }
  lastUpdate = now;
  
  stateController.Update(updateTime);
  
  defaultLed.SetState(microSwitch.GetState());
}
