#include <Arduino.h>

#include "PS2X_lib.h"
#include "Debug.h"

PS2X ps2x;

void ControllerSetup(void) {
  int error;
  byte type;

  error = ps2x.config_gamepad(13,11,10,12, false, false);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
 
  if(error == 0){
    Serial.println("Found Controller, configured successful");
  }
  else if(error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
   
  else if(error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
   
  else if(error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
   
   //Serial.print(ps2x.Analog(1), HEX);
   
  type = ps2x.readType(); 
  switch(type) {
  case 0:
    Serial.println("Unknown Controller type");
    break;
  case 1:
    Serial.println("DualShock Controller Found");
    break;
  case 2:
    Serial.println("GuitarHero Controller Found");
    break;
  }
}

byte ControllerGetRY(void) {
  return ps2x.Analog(PSS_RY);
}

byte ControllerGetLY(void) {
  return ps2x.Analog(PSS_LY);
}

bool ControllerGetTriangle(void) {
  return(ps2x.ButtonPressed(PSB_TRIANGLE));
}

bool ControllerGetCircle(void) {
  return(ps2x.ButtonPressed(PSB_CIRCLE));
}
bool ControllerGetL1(void)
{
  return(ps2x.ButtonPressed(PSB_L1));
}
bool ControllerGetR2(void)
{
  return(ps2x.ButtonPressed(PSB_R2));
}

void ControllerLoop(void) {
  ps2x.read_gamepad();          //read controller 
}

