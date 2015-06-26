#include "MicroSwitch.h"

#define DEBOUNCE_TIME 50

MicroSwitch::MicroSwitch(int pinId) : DigitalInput(pinId), m_debouncePending(false)
{
  Reset();
}

void MicroSwitch::Update(long updateInterval)
{
  int state = DigitalInput::GetState();

  if (state != m_currentState){
    if (!m_debouncePending){
      Serial.println("MicroSwitch::Update debounce start");
      m_debouncePending = true;
      m_lastUpdate = millis();
      m_pendingState = state;
    }
  } else {
    if (m_debouncePending){
      Serial.println("MicroSwitch::Update debounce test");
      if (millis() - m_lastUpdate > DEBOUNCE_TIME){
        Serial.println("MicroSwitch::Update debounce end");
        m_currentState = m_pendingState;
        m_debouncePending = false;
      }
    }
  }
};

void MicroSwitch::Reset()
{
  Serial.println("MicroSwitch::Reset");
  m_pendingState = DigitalInput::GetState();
};

int MicroSwitch::GetState()
{
  return m_currentState;
}

