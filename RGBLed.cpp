#include "RGBLed.h"

RGBLed::RGBLed(int redPinId, int greenPinId, int bluePinId) : StateMachine()
{
  m_redLed = new AnalogLed( redPinId, 0 );
  m_greenLed = new AnalogLed( greenPinId, 0 );
  m_blueLed = new AnalogLed( bluePinId, 0 );
  
  Reset();
}

RGBLed::~RGBLed()
{
  delete m_redLed;
  delete m_greenLed;
  delete m_blueLed;
}

void RGBLed::Update(long updateInterval)
{
  m_redLed->Update(updateInterval);
  m_greenLed->Update(updateInterval);
  m_blueLed->Update(updateInterval);
};

void RGBLed::Reset()
{
  m_redLed->SetState(0);
  m_greenLed->SetState(0);
  m_blueLed->SetState(0);
};

void RGBLed::SetColour(int red, int green, int blue)
{
  m_redLed->SetState(red);
  m_greenLed->SetState(green);
  m_blueLed->SetState(blue);
}

