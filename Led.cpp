#include "Led.h"

Led::Led(int pinId, int defaultState) : DigitalOutput(pinId), m_ledDefaultState(defaultState), m_pendingState(defaultState)
{
  Reset();
}

void Led::Update(long updateInterval)
{
  if (m_ledCurrentState != m_pendingState)
  {
    m_ledCurrentState = m_pendingState;
    DigitalOutput::SetState(m_ledCurrentState);
  }
};

void Led::Reset()
{
  m_pendingState = m_ledDefaultState;
};

void Led::SetState(int newState)
{
  if (m_pendingState != newState)
  {
    m_pendingState = newState;
  }
}

