#include <Arduino.h>
#include <Servo.h>
#include "PS2X_lib.h"
#include "Potentiometer.h"
#include "Drive.h"
#include "Controller.h"

int SwitchVal;
int DriveRightPin = 5;
int DriveLeftPin = 4;
/*int SwitchPin = 3;*/
int driveCount = 0;
Servo DriveRight;
Servo DriveLeft;

void DriveSetup()
{
  
  DriveRight.attach(DriveRightPin);
  DriveLeft.attach(DriveLeftPin);
  /*pinMode(SwitchPin,INPUT_PULLUP);*/
 
}
void DriveWithSwitch()
{
  
   /*SwitchVal=digitalRead(SwitchPin);*/
   if(SwitchVal == LOW)
   {
       DriveLeft.write(75);
   }
   else if (SwitchVal == HIGH)
   {
       
        DriveLeft.write(90);
   }
   else 
   {
 
      DriveLeft.write(90);
   }
}
void DriveWithPot()
{
  DriveLeft.write(PotLoop());
}
 
void DriveWithStick(void)
{
  int LY, DLY, RY, DRY;

  RY = ControllerGetRY();
  LY = ControllerGetLY();
  DRY = map(RY, 0, 255, 180,0);
  DLY = map(LY, 0, 255, 0, 180);// input value , scale to zeroe , negate and resccale. f(x)= (-(x-90))+90 or f(x)= 180-x
  
  if (++driveCount == 50) {
    driveCount = 0;  
    Serial.print("Stick value = ");
    Serial.print(LY);
    Serial.print(" ");
    Serial.print(RY);
    Serial.print(" Drive value = ");
    Serial.print(DLY);
    Serial.print(" ");
    Serial.println(DRY);
  }
  DriveRight.write(DRY);
  DriveLeft.write(DLY);
}

