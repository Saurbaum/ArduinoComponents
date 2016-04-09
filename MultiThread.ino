#include <LinkedList.h>
#include "Led.h"
#include "MicroSwitch.h"
#include "StateController.h"
#include "Joystick.h"
#include "RGBLed.h"
#include "RotaryEncoder.h"

#define MAX_TIME -1

MicroSwitch toggleSwitchA(2);
MicroSwitch toggleSwitchB(3);

StateController stateController;

unsigned long lastUpdate;

void setup()
{
	stateController.Reset();

	stateController.Register(&toggleSwitchA);
  stateController.Register(&toggleSwitchB);

	lastUpdate = micros();

  Serial.begin(9600);
}

int lastSwitchAState = -1;
int lastSwitchBState = -1;

void loop()
{
	unsigned long now = micros();
	long updateTime = 0;

	if (now < lastUpdate) {
		updateTime = now + (MAX_TIME - lastUpdate);
	}
	else {
		updateTime = now - lastUpdate;
	}
	lastUpdate = now;

	stateController.Update(updateTime);

  int switchState = toggleSwitchA.GetState();
  if (switchState != lastSwitchAState) {
    Serial.write("toggleSwitchA\n");
    Serial.write(switchState == LOW ? "Low\n" : "High\n");
    lastSwitchAState = switchState;
  }

  switchState = toggleSwitchB.GetState();
  if (switchState != lastSwitchBState) {
    Serial.write("toggleSwitchB\n");
    Serial.write(switchState == LOW ? "Low\n" : "High\n");
    lastSwitchBState = switchState;
  }
}
