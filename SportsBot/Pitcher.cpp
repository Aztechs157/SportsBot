#include <Arduino.h>
#include <Servo.h>
#include "Pitcher.h"
#include "Controller.h"
int GatePin = 9; 
int GateSpeed = 180;
int PitcherPinTop = 6;
int PitcherPinBottom =;
int Rest = 90;
int pitchSpeedTop = 180;
int pitchSpeedBottom = 0;
Servo PitcherMotorTop;
Servo PitcherMotorBottom;
Servo Gate;

void PitcherSetup()
{  
  Gate.attach(GatePin);
  Pitcher.attach(PitcherPin);
}

void PitcherLoop(void)
{
  
  if (ControllerGetL1()) {
    Serial.println("WindingUp");
    PitcherMotorTop.write(pitcherSpeedTop);
    PitcherMotorBottom.write(pitcherSpeedBottom):
    
  }
  if (ControllerGetCircle()) {
    Serial.println("Rest.");
    Pitcher.write(pitcherAtRest);
  }
  if (ControllerGetR2())
  {
    Gate.write(GateSpeed);
  }
}

