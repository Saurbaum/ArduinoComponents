#include "JoystickAxis.h"

JoystickAxis::JoystickAxis(int pinId) : AnalogInput(pinId)
{
  Reset();
}

void JoystickAxis::Update(long updateInterval)
{
    m_currentState = AnalogInput::GetState();
}

void JoystickAxis::Reset()
{
  m_currentState = AnalogInput::GetState();
}

int JoystickAxis::GetState()
{
  return m_currentState;
}

