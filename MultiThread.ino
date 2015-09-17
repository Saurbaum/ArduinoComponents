#include <LinkedList.h>
#include "Led.h"
#include "MicroSwitch.h"
#include "StateController.h"
#include "Joystick.h"
#include "RGBLed.h"
#include "RotaryEncoder.h"

#define MAX_TIME -1

Joystick joystick(0, 1, 15);
RGBLed rgbLed(3, 5, 6);
RotaryEncoder dial(8, 7, 9);

int rotorValue = 0;

StateController stateController;

unsigned long lastUpdate;

void setup()
{
	stateController.Reset();

	stateController.Register(&joystick);
	stateController.Register(&rgbLed);
	stateController.Register(&dial);

	lastUpdate = micros();
}

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

	rotorValue += dial.GetChange();

	if (rotorValue > 255) {
		rotorValue = 255;
	}

	if (rotorValue < 0) {
		rotorValue = 0;
	}

	int red = joystick.GetXAxis() / 4;
	int green = joystick.GetYAxis() / 4;
	int blue = rotorValue;

	rgbLed.SetColour(red, green, blue);
}
