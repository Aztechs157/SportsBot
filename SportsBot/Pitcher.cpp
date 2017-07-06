#include <Arduino.h>
#include <Servo.h>
#include "Pitcher.h"
#include "Controller.h"
int GatePin = 3; 
int GateSpeed = 0;
int PitcherPinTop = 7;
int PitcherPinBottom = 6;
int Rest = 93;
int pitcherSpeedTop = 93;//180////////////////////////Warning !!!!!!!!!!!!!!!!!!!!!!!!!!//////////////////////////
int pitcherSpeedBottom =93;//0/////////////////////chnage after testing///////////////////////////////////////
int CurrentStep = 0; // keeps track of what speed the motors are at
int MinStep = 0;     // minimum speed of pitching motors
int MaxStep = 6;    // maximum speed of pitching motors
int LEDPort=2; 
Servo PitcherMotorTop;
Servo PitcherMotorBottom;


void PitcherSetup()
{  
  PitcherMotorTop.attach(PitcherPinTop); 
  PitcherMotorBottom.attach(PitcherPinBottom);
  pinMode(LEDPort,OUTPUT);
  pinMode(GatePin,OUTPUT);
  digitalWrite(GatePin,HIGH);
  
}

void PitcherLoop(void)
{
  // Serial.println(PitcherMotorTop.read());
  // Serial.println(PitcherMotorBottom.read());
  
   if (ControllerGetL1()) {
      Serial.println("iWindingUp");
      PitcherMotorTop.write(pitcherSpeedTop);
      PitcherMotorBottom.write(pitcherSpeedBottom);
    }
    if (ControllerGetL2()) {
      Serial.println("Rest.");
      PitcherMotorTop.write(Rest);
      PitcherMotorBottom.write(Rest);
    
    }
    if (ControllerGetR2())
    {
      Serial.print("Pitch:Gate Open");
      // digitalWrite(LEDPort,HIGH);
      digitalWrite(GatePin,LOW);
    }
    if (ControllerGetR2Released())
    {
      Serial.print("Pitch:Gate Closed");
      digitalWrite(GatePin,HIGH);
    }
    /// varing speed
    if(ControllerGetTriangle())
    {
      CurrentStep++;
      if(CurrentStep>MaxStep)
      {
        CurrentStep=MaxStep;
        PitcherMotorTop.write(pitcherSpeedTop);
        PitcherMotorBottom.write(pitcherSpeedBottom);
      }
      else
      {
        pitcherSpeedTop=pitcherSpeedTop+10;
        pitcherSpeedBottom=pitcherSpeedBottom-10;
        PitcherMotorTop.write(pitcherSpeedTop);
        PitcherMotorBottom.write(pitcherSpeedBottom);
        Serial.print("Increased Speed by 10");
      }
    }
    else
    {
      PitcherMotorTop.write(pitcherSpeedTop);
      PitcherMotorBottom.write(pitcherSpeedBottom);
    }

    
    if(ControllerGetCircle())
    {
      CurrentStep--;
      if(CurrentStep<MinStep) 
      {
        CurrentStep = MinStep;
        PitcherMotorTop.write(pitcherSpeedTop);
        PitcherMotorBottom.write(pitcherSpeedBottom);
      }
      else 
      {
        pitcherSpeedTop=pitcherSpeedTop-10;
        pitcherSpeedBottom=pitcherSpeedBottom+10;
        PitcherMotorTop.write(pitcherSpeedTop);
        PitcherMotorBottom.write(pitcherSpeedBottom);
        Serial.print("decreased Speed by 10");
      }
    }
    else
    {
     PitcherMotorTop.write(pitcherSpeedTop);
     PitcherMotorBottom.write(pitcherSpeedBottom);
    }
 }



