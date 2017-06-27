#include <Servo.h>
int MotorPin = 11;
int SwitchPin = 4;
int SwitchVal; 
int PotPin = A0;
int PotVal ;
int DPotVal;
Servo Motor;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(19200);
Motor.attach(MotorPin);
pinMode(SwitchPin,INPUT_PULLUP);

}

void loop() {
   // put your main code here, to run repeatedly:
   SwitchVal=digitalRead(SwitchPin);
   Serial.print(SwitchVal);
   PotVal = analogRead(PotPin);
   DPotVal = map(PotVal, 0, 1023, 0, 180);
   Serial.print("Pot value = ");
   Serial.print(PotVal);
   Serial.print("Digital pot value = ");
   Serial.println(DPotVal);
   if(SwitchVal == LOW)
   {
       Motor.write(DPotVal);
   }
   else if (SwitchVal == HIGH)
   {
       
        Motor.write(90);
   }
   else 
   {
 
      Motor.write(90);
   }
    
   

}
