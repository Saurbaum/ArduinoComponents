#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(int pinAId, int pinBId, int switchId) : StateMachine(), m_clockA(pinAId), m_clockB(pinBId), m_Last_ClockB_Status(0),  m_Current_ClockB_Status(0)
{
  m_button = new MicroSwitch(switchId);
  pinMode(m_clockA, INPUT);
  pinMode(m_clockB, INPUT);
}

RotaryEncoder::~RotaryEncoder()
{
  delete m_button;
}

void RotaryEncoder::Update(long updateInterval)
{
  int flag = 0;
  
  m_button->Update(updateInterval);

  if (m_button->GetState())
  {
    Reset();
  }

  m_Last_ClockB_Status = digitalRead(m_clockB);

  while(!digitalRead(m_clockA)){
    m_Current_ClockB_Status = digitalRead(m_clockB);
    flag = 1;
  }

  if(flag == 1){
    flag = 0;
    if((m_Last_ClockB_Status == 0)&&(m_Current_ClockB_Status == 1)){
      m_currentChange++; 
    }
    if((m_Last_ClockB_Status == 1)&&(m_Current_ClockB_Status == 0)){
      m_currentChange--;
    }
  }
};

void RotaryEncoder::Reset()
{
  m_currentChange = 0;
};

int RotaryEncoder::GetChange()
{
  int change = m_currentChange;
  Reset();
  return change;
}

bool RotaryEncoder::GetPressed()
{
  return m_button->JustPressed();
}

