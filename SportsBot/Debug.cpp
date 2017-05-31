#include <Arduino.h>

void DebugSetup(void){

}


void DebugPrintChar(char chr) {
  static int count = 0;

  if (count == 50) {
    count = 0;
    Serial.println("+");
  } else {
    Serial.print(chr);
  }
 }

