#include <Arduino.h>
#include <Servo.h>
#include "PS2X_lib.h"
#include "Potentiometer.h"
#include "Motor_Run.h"
#include "Controller.h"

int SwitchVal;
int MotorRightPin = 5;
int MotorLeftPin = 4;
int SwitchPin = 3;
int motorCount = 0;
Servo MotorRight;
Servo MotorLeft;

void MotorSetup()
{
  
  MotorRight.attach(MotorRightPin);
  MotorLeft.attach(MotorLeftPin);
  pinMode(SwitchPin,INPUT_PULLUP);
 
}
void MotorWithSwitch()
{
  
   SwitchVal=digitalRead(SwitchPin);
   if(SwitchVal == LOW)
   {
       MotorLeft.write(75);
   }
   else if (SwitchVal == HIGH)
   {
       
        MotorLeft.write(90);
   }
   else 
   {
 
      MotorLeft.write(90);
   }
}
void MotorWithPot()
{
  MotorLeft.write(PotLoop());
}
 
void MotorWithStick(void)
{
  int LY, DLY, RY, DRY;

  RY = ControllerGetRY();
  LY = ControllerGetLY();
  DRY = map(RY, 0, 255, 0, 180);
  DLY = map(LY, 0, 255, 0, 180);
  
  if (++motorCount == 500) {
    motorCount = 0;  
    Serial.print("Stick value = ");
    Serial.print(LY);
    Serial.print(" ");
    Serial.print(RY);
    Serial.print(" Motor value = ");
    Serial.print(DLY);
    Serial.print(" ");
    Serial.println(DRY);
  }
  MotorRight.write(DRY);
  MotorLeft.write(DLY);
}

