#include "AnalogInput.h"

AnalogInput::AnalogInput(int pinId) : StateMachine(),  m_pinId(pinId)
{
  pinMode(m_pinId, INPUT);
};

int AnalogInput::GetState()
{
  return analogRead(m_pinId);
};
