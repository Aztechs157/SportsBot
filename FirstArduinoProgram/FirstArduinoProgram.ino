#include <PS2X_lib.h>
#include <Servo.h>
int MotorPin = 11;
int PotPin = A0;
int PotVal ;
int DPotVal;
int SwitchPin=;
int SwitchVal; 
Servo Motor;
// 90= neutral tolerance = 5 full FOrward = 180 Full reverse = 180
void setup() {
  // put your setup code here, to run once:
Serial.begin(19200);
Motor.attach(MotorPin);
pinMode(SwitchPin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  SwitchVal=digitalRead(SwitchPin);
  PotVal = analogRead(PotPin);
  DPotVal = map(PotVal, 0, 1023, 0, 180);
  Serial.print("Pot value = ");
  Serial.print(PotVal);
  Serial.print("Digital pot value = ");
  Serial.println(DPotVal);
   //SwitchVal=digitalRead(SwitchPin);
   Motor.write(DPotVal);
   if(SwitchVal == LOW)
   {
      Motor.write();
   }
   else if (switchVal == HIGH)
   {
     Motor.write(90);
   }
   else 
   {
    Motor.write(90);
   }
   
   }

