#include "DigitalOutput.h"

DigitalOutput::DigitalOutput(int pinId) : StateMachine(),  m_pinId(pinId)
{
  pinMode(m_pinId, OUTPUT);
};

void DigitalOutput::SetState(int newState)
{
  digitalWrite(m_pinId, newState);
};
