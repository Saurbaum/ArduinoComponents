#ifndef BUZZER_H
#define BUZZER_H

#include "DigitalOutput.h"

class Buzzer : public DigitalOutput
{
public:
  Buzzer(int pinId);  
  ~Buzzer() {};
  
  virtual void Update(long updateInterval);  
  virtual void Reset();

  void PlayTone(int frequency, float durationSeconds);
  bool IsPlaying();
  
private:
  int m_frequency;
  long m_duration;
  long m_stepTime;
  long m_delay;
  bool m_playing;
  int m_currentState;
};
#endif
