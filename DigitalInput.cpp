#include "DigitalInput.h"

DigitalInput::DigitalInput(int pinId) : StateMachine(),  m_pinId(pinId)
{
  pinMode(m_pinId, INPUT_PULLUP);
};

int DigitalInput::GetState()
{
  return digitalRead(m_pinId);
};
