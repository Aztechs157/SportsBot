#include <Servo.h>
#include "Motor_Run.h"
#include "Potentiometer.h"
#include "Timer.h"
#include "HeartBeat.h"
#include "PS2X_lib.h"
#include "Controller.h"
#include "Pitcher.h"

void setup() {
  Serial.begin(230400);
  ControllerSetup();
  MotorSetup();
  TimerSetup();
  HeartBeatSetup();
  PitcherSetup();
}

void loop() 
{
  static bool runController = true;
  static bool runRobot = false;
  
  if (TimerCheck) {
    if (runController) {
      ControllerLoop();
    }

    if (runRobot) {

      HeartBeatLoop();
      MotorWithStick();
      PitcherLoop();
    }

    // Alternate between getting data from the controller and updating the robot
    runController = !runController;
    runRobot = !runRobot;
  }
}
