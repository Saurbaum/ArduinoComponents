#include "Joystick.h"

Joystick::Joystick(int xAxisPinId, int yAxisPinId, int microswitchPinId) : StateMachine()
{
  m_xAxis = new JoystickAxis(xAxisPinId);
  m_yAxis = new JoystickAxis(yAxisPinId);

  if (microswitchPinId > -1)
  {
    m_microswitch = new MicroSwitch(microswitchPinId);
  } 
  else 
  {
    m_microswitch = 0;
  }
}

Joystick::~Joystick()
{
  delete m_xAxis;
  delete m_yAxis;

  if (m_microswitch != 0)
  {
    delete m_microswitch;
  }
}

void Joystick::Update(long updateInterval)
{
  m_xAxis->Update(updateInterval);
  m_yAxis->Update(updateInterval);
  m_microswitch->Update(updateInterval);
};

void Joystick::Reset()
{
  m_xAxis->Reset();
  m_yAxis->Reset();
  m_microswitch->Reset();
};

int Joystick::GetXAxis()
{
  return m_xAxis->GetState();
}

int Joystick::GetYAxis()
{
  return m_yAxis->GetState();
}

int Joystick::GetSwitch()
{
  return m_microswitch->GetState();
}

