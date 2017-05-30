  /*=======================================================================================
Original code by:                        Noah Stahl
                                          5/7/2011
                                       Arduino Mega 2560
Modified by: WCarr 2017-05-25  -  Convert to Uno, make interrupt fire every 10ms.

This program will blink an LED on Port 13 once a second using a Timer2 Overflow Interrupt.
The timer overflow interrupt fires every 10ms by setting the prescaler to 1028 and
preloading Timer2's counter with 99. Timer2 is 8-bits so the max number it can count to
is 255, this leaves 156 cycles left to count. The Arduino has a clock of 16MHz so:
(1/16E6) * 156 * 1024 = 9.984 ms (approx 10ms)
The interrupt flag will fire every 10ms. Once the interupt fires 100 times (i.e. one
second) the LED on pin 13 will toggle.
=======================================================================================*/
#include <Arduino.h>

#define START_COUNT 99

volatile bool fired;               //indicates if timer fired, and whether its been checked

#if defined(__AVR_ATmega32U4__)
//Timer4 Overflow Interrupt Vector, called when timer overflows (exceeds 255)
ISR(TIMER4_OVF_vect) {
  fired = true;
  TCNT4 = START_COUNT;   //Reset Timer
  TIFR4 = 0x00;          //Timer INT Flag Reg: Clear Timer Overflow Flag
}; 

void TimerSetup(void) {
  //Setup Timer4 to fire
  TCCR4B = 0x00;        //Disbale Timer while we set it up
  TCNT4 = START_COUNT;  //Reset Timer
  TIFR4  = 0x00;        //Timer INT Flag Reg: Clear Timer Overflow Flag
  TIMSK4 = 0x01;        //Timer INT Reg: Timer2 Overflow Interrupt Enable
  TCCR4A = 0x00;        //Timer Control Reg A: Wave Gen Mode normal
  TCCR4B = 0x07;        //Timer Control Reg B: Timer Prescaler set to 1024

  fired = false;
}
#else /* assume it supports TIMER2 */
//Timer2 Overflow Interrupt Vector, called when timer overflows (exceeds 255)
ISR(TIMER2_OVF_vect) {
  fired = true;
  TCNT2 = START_COUNT;   //Reset Timer
  TIFR2 = 0x00;          //Timer2 INT Flag Reg: Clear Timer Overflow Flag
}; 

void TimerSetup(void) {
  //Setup Timer2 to fire
  TCCR2B = 0x00;        //Disbale Timer2 while we set it up
  TCNT2 = START_COUNT;  //Reset Timer
  TIFR2  = 0x00;        //Timer2 INT Flag Reg: Clear Timer Overflow Flag
  TIMSK2 = 0x01;        //Timer2 INT Reg: Timer2 Overflow Interrupt Enable
  TCCR2A = 0x00;        //Timer2 Control Reg A: Wave Gen Mode normal
  TCCR2B = 0x07;        //Timer2 Control Reg B: Timer Prescaler set to 1024

  fired = false;
}
#endif  

void TimerLoop(void) {
}

bool TimerCheck(void)  {
  uint8_t old_sreg = SREG;        // **** save away the current state of interrupts
  bool prevFired;

  // turn off inteerupts so the state of fired doesn't chnage to avaoid conflict at timer reset
  noInterrupts();
  prevFired = fired;
  fired = false;
  SREG = old_sreg;  // return interrupts to previous state 
  return prevFired;
}

