#include <LinkedList.h>
#include "Led.h"
#include "MicroSwitch.h"
#include "StateController.h"

Led defaultLed(17, HIGH);
MicroSwitch microSwitch(10);
StateController stateController;


long lastUpdate;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  stateController.Reset();
  
  stateController.Register(&defaultLed);
  stateController.Register(&microSwitch);
  
  lastUpdate = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  long now = millis();
  long updateTime = now - lastUpdate;
  lastUpdate = now;
  
  stateController.Update(updateTime);
  
  defaultLed.SetState(!microSwitch.GetState());
}
