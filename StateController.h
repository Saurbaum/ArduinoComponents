#ifndef STATE_CONTROLLER_H
#define STATE_CONTROLLER_H

#include <LinkedList.h>
#include "StateMachine.h"

class StateController
{
public:
  StateController() {};
  ~StateController() {};

  void Register(StateMachine* stateMachine);
  void Update(long updateInterval);
  void Reset();

private:
  LinkedList<StateMachine*> m_stateMachines;
};
#endif
