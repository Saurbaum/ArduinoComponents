#ifndef MICRO_SWITCH_H
#define MICRO_SWITCH_H

#include "DigitalInput.h"

class MicroSwitch : public DigitalInput
{
public:
  MicroSwitch(int pinId);  
  ~MicroSwitch() {};
  
  virtual void Update(long updateInterval);  
  virtual void Reset();

  int GetState();
  
private:
  int m_lastUpdate;
  int m_currentState;
  int m_pendingState;

  bool m_debouncePending;
};
#endif
