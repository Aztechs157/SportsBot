#include <PS2X_lib.h>
#include <Servo.h>
int ryv;
int lyv;
int Aryv;
int Alyv;
PS2X ps2x;
int error = 0;
byte type = 0;
byte vibrate = 0;
int MotorPin = 3;


Servo Motor;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  error = ps2x.config_gamepad(13,11,12,10,true, true);/// clock,command,attention,data
  type = ps2x.readType();
  Motor.attach(MotorPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  ps2x.read_gamepad();
  ryv = ps2x.Analog(PSS_RY);
  lyv = ps2x.Analog(PSS_LY);
  Serial.print("Raw Y Value");
  Serial.print(lyv);
  Serial.print("Mapped Left Y Value");
  Serial.print(Alyv);
  Alyv = map(lyv, 0, 255 , 0, 180);
  Serial.print("Right Y Value:");
  Serial.println(ryv);
///  controller raids 
   // high was 121
   int High = 90;
   int Low = 70;
   Motor.write(90); // puts motor in neutral before hand ;
   if(Alyv <= High &&  Alyv >= Low)
   {
         Motor.write(90); 
   }

   else 
   {
       Motor.write(Alyv);
   }
   
 
  
  
}

  
  

