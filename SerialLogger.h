#ifndef SERIAL_LOGGER_H
#define SERIAL_LOGGER_H

#include "StateMachine.h"
#include <LinkedList.h>

class SerialLogger : public StateMachine
{
protected:
  SerialLogger(long triggerInterval);
  ~SerialLogger(); 
public:
  virtual void Update(long updateInterval);
  
  virtual void Reset();
    
private:
  long m_lastUpdate;
  long m_triggerInterval;

  LinkedList<StateMachine*> m_stateMachines;
};

#endif
