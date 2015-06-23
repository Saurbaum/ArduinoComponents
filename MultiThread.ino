#include <LinkedList.h>
#include "Led.h"
#include "StateController.h"

Led defaultLed(17, HIGH);
StateController stateController;

long lastUpdate;

void setup() {
  // put your setup code here, to run once:
  stateController.Reset();
  
  stateController.Register(&defaultLed);
  lastUpdate = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  long now = millis();
  long updateTime = now - lastUpdate;
  lastUpdate = now;
  
  defaultLed.Update(updateTime);
}
