#include <Arduino.h>
#include <Servo.h>
#include "Pitcher.h"
#include "Controller.h"
int GatePin = 3; 
int GateSpeed = 0;
int PitcherPinTop = 7;
int PitcherPinBottom = 6;
int Rest = 90;
int pitcherSpeedTop = 180;
int pitcherSpeedBottom = 0;
int LEDPort=2; 
Servo PitcherMotorTop;
Servo PitcherMotorBottom;


void PitcherSetup()
{  
  PitcherMotorTop.attach(PitcherPinTop);
  PitcherMotorBottom.attach(PitcherPinBottom);
  pinMode(LEDPort,OUTPUT);
  pinMode(GatePin,OUTPUT);
  digitalWrite(GatePin,LOW);
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
    Serial.print("pitch");
     // digitalWrite(LEDPort,HIGH);
    digitalWrite(GatePin,HIGH);
  }
    
}


