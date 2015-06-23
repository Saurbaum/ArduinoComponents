#include "Led.h"

Led::Led(int pinId, int defaultState) : DigitalOutput(pinId), m_ledDefaultState(defaultState)
{
  Reset();
}

void Led::Update(long updateInterval)
{
  
};

void Led::Reset()
{
  SetState(m_ledDefaultState);
};
