/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "spline.h"
#include "pid.h"
#include "functions.h"
#include "vex.h"
#include "auton.h"
#include "skills.h"
#include <iostream>
using namespace vex;

// A global instance of competition
competition Competition;

bool skillsB = false;
int autoSelect = 1;
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  clawBack.open();
  clawFront.open();
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  clawLiftBackL.close();
  clawLiftBackR.open();
  vexcodeInit();
  inert.calibrate();
  while(inert.isCalibrating());
  inert.calibrate();
  while(inert.isCalibrating());
  rotate.resetPosition();
  std::cout << "Done Calibrating" << std::endl;
  wait(500,msec);
  while(true){
    if(skillsB) Brain.Screen.printAt(20, 20, "Skills");
    else if(autoSelect == 1) Brain.Screen.printAt(20, 20, "Middle Goal");
    else Brain.Screen.printAt(20, 20, "Side Goal");
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing());
      (autoSelect%=1)++;
    }
  }
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void autonomous(void) {
  if(skillsB) skills();
  else if(autoSelect == 1) middleAuto();
  else sideAuto();
}


void usercontrol(void) {
  // User control code here, inside the loop
  bool holding = false;
  task grip(gripperControl);
  if(skillsB){
    clawLiftFrontL.close();
    clawLiftFrontR.open();
    clawLiftBackL.close();
    clawLiftBackR.close();
    clawBack.close();
    clawFront.close();
    forwardPID(150, 300);
    clawFront.open();
    clawLiftFrontL.open();
    clawLiftFrontR.close();
    stopDrive(coast);
  }
  else{
    clawLiftFrontL.open();
    clawLiftFrontR.close();
    clawFront.open();
    clawBack.open();
    clawLiftBackL.close();
    clawLiftBackR.close();
  }
  while (true) {
    float curvedY = (float)Controller1.Axis3.position(pct);
    float curvedX = (float)Controller1.Axis4.position(pct);
    if(abs(Controller1.Axis2.position(pct))> 5) flip.spin(fwd, Controller1.Axis2.position(pct), pct);
    else flip.stop(hold);
    if(fabs(curvedX) < 10) curvedX = 0;
    if(fabs(curvedY) < 10) curvedY = 0;
    leftDrive.spin(fwd, curvedY + (curvedX*0.3), pct);
    rightDrive.spin(fwd, curvedY - (curvedX*0.3), pct);
    if(Controller1.ButtonLeft.pressing()){
      if(!holding){
        leftDrive.setStopping(hold);
        rightDrive.setStopping(hold);
        holding = !holding;
      }
      else{
        leftDrive.setStopping(coast);
        rightDrive.setStopping(coast);
        holding = !holding;
      }
      while(Controller1.ButtonLeft.pressing());
    }
    if(Controller2.ButtonR1.pressing() || Controller1.ButtonR2.pressing()){
      intakeF.spin(fwd, 100, pct);
      intakeB.spin(fwd, 100, pct);
    }
    else if(Controller2.ButtonL1.pressing() || Controller1.ButtonL2.pressing()){
      intakeF.spin(reverse, 100, pct);
      intakeB.spin(reverse, 100, pct);
    }
    else{
      intakeF.stop(coast);
      intakeB.stop(coast);
    }
    wait(20, msec); // Sleep the task for a short amount of time to
  }
}


int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}