#include <Arduino.h>
#include <Servo.h>
#include "Pitcher.h"
#include "Controller.h"
int GatePin = 9; 
int GateSpeed = 180;
int PitcherPinTop = 7;
int PitcherPinBottom = 6;
int Rest = 90;
int pitcherSpeedTop = 180;
int pitcherSpeedBottom = 0;
Servo PitcherMotorTop;
Servo PitcherMotorBottom;
Servo Gate;

void PitcherSetup()
{  
  Gate.attach(GatePin);
  PitcherMotorTop.attach(PitcherPinTop);
  PitcherMotorBottom.attach(PitcherPinBottom);
}

void PitcherLoop(void)
{
  
  if (ControllerGetL1()) {
    Serial.println("WindingUp");
    PitcherMotorTop.write(pitcherSpeedTop);
    PitcherMotorBottom.write(pitcherSpeedBottom);
    
  }
  if (ControllerGetCircle()) {
    Serial.println("Rest.");
    PitcherMotorTop.write(Rest);
    PitcherMotorBottom.write(Rest);
    
  }
  if (ControllerGetR2())
  {
    Gate.write(GateSpeed);
  }
}

