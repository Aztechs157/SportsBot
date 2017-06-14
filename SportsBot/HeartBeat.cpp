#include <Arduino.h>

#include "HeartBeat.h"
#include "Controller.h"
unsigned int LEDPin =2 ;

volatile unsigned int toggle = 0;  //used to keep the state of the LED
volatile unsigned int count = 0;   //used to keep count of how many interrupts were fired

void HeartBeatSetup(void) {
  pinMode(LEDPin, OUTPUT);
}


void HeartBeatLoop(void) {
  count++;               //Increments the interrupt counter
  if(count > 24){
    toggle = !toggle;    //toggles the LED state
    count = 0;           //Resets the interrupt counter
  }
  digitalWrite(LEDPin,toggle);
  
}
boolean ESTOP(void)
{ 
  return (ControllerGetCircleReleased());
}














