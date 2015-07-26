#include "Buzzer.h"

Buzzer::Buzzer(int pinId) : DigitalOutput(pinId), m_frequency(0), m_delay(0), m_playing(false)
{
  Reset();
}

void Buzzer::Reset()
{
    m_playing = false;
    m_frequency = 0;
    m_delay = 0;
    m_duration = 0;
    m_stepTime = 0;
    m_currentState = LOW;
    DigitalOutput::SetState(m_currentState);
}

void Buzzer::Update(long updateInterval)
{
  m_duration += updateInterval;
  m_stepTime += updateInterval;
  
  if (m_duration >= m_delay)
  {
    Reset();
  }
  else 
  {
    if (m_stepTime >= m_frequency)
    {
      m_stepTime -= m_frequency;
      m_currentState =  !m_currentState;
      DigitalOutput::SetState(m_currentState);
    }
  }
}

void Buzzer::PlayTone(int frequency, float durationSeconds)
{
  m_playing = true;
  m_frequency = (int)((1 / frequency) * 1000000);
  m_delay = (int)(durationSeconds * 1000000);
  m_duration = 0;
  m_stepTime = 0;
  m_currentState = LOW;
}

bool Buzzer::IsPlaying()
{
  return m_playing;
}
