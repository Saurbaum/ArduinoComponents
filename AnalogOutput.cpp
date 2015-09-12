#include "AnalogOutput.h"

AnalogOutput::AnalogOutput(int pinId) : StateMachine(),  m_pinId(pinId)
{
  pinMode(m_pinId, OUTPUT);
};

void AnalogOutput::SetState(int newState)
{
  if ( newState > 255 ){
    newState = 255;
  }

  if ( newState < 0 ){
    newState = 0;
  }

  analogWrite(m_pinId, newState);
};
