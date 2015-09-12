#include "AnalogLed.h"

AnalogLed::AnalogLed(int pinId, int defaultState) : AnalogOutput(pinId), m_ledDefaultState(defaultState), m_pendingState(defaultState)
{
  Reset();
}

void AnalogLed::Update(long updateInterval)
{
  if (m_ledCurrentState != m_pendingState)
  {
    m_ledCurrentState = m_pendingState;
    AnalogOutput::SetState(m_ledCurrentState);
  }
};

void AnalogLed::Reset()
{
  m_pendingState = m_ledDefaultState;
};

void AnalogLed::SetState(int newState)
{
  if (m_pendingState != newState)
  {
    m_pendingState = newState;
  }
}

