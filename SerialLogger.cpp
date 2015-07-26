#include "SerialLogger.h"

SerialLogger::SerialLogger(long triggerInterval) : StateMachine(), m_lastUpdate(0), m_triggerInterval(triggerInterval)
{
  Serial.begin(9600);
}

SerialLogger::~SerialLogger()
{
  Serial.end();
}

void SerialLogger::Update(long updateInterval)
{
  m_lastUpdate += updateInterval;

  if ( m_lastUpdate >= m_triggerInterval )
  {
    int i = 7;
    unsigned char buf[sizeof(int)];
    memcpy(buf, &i, sizeof(int));
    Serial.write(buf, sizeof(buf));
  }
}

void SerialLogger::Reset()
{
  m_lastUpdate = 0;
}
