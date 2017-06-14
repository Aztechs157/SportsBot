#include <PS2X_lib.h>

#include <Servo.h>

int MotorPin = 5;
int SwitchPin = 4;
int SwitchVal; 
int error;
byte type=0;
Servo Motor;
PS2X ps2x;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(19200);
Motor.attach(MotorPin);
error = ps2x.config_gamepad(13,11,10,12, true, true);
  type = ps2x.readType();
pinMode(SwitchPin,INPUT_PULLUP);

}

void loop() {
   // put your main code here, to run repeatedly:
   SwitchVal=digitalRead(SwitchPin);
   Serial.print(SwitchVal);
   ps2x.read_gamepad();

   if(ps2x.Button(PSB_PAD_UP)==true )
   {
    
       Motor.write(75);
       if (ps2x.Button
   }
   else if (ps2x.Button(PSB_PAD_DOWN)==true)
   {
      Motor.write(105);
   }
   else 
   {
    Motor.write(90);
   }
    
   

}
