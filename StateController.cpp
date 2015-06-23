#include "StateController.h"

void StateController::Register(StateMachine* stateMachine)
{
  m_stateMachines.add(stateMachine); 
}

void StateController::Update(long updateInterval)
{
  for (int i = 0; i < m_stateMachines.size(); ++i)
  {
    m_stateMachines.get(i)->Update(updateInterval);
  }
}

void StateController::Reset()
{
  m_stateMachines.clear();
}

