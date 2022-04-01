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

int autoSelect = 2;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  inert.calibrate();
  while(inert.isCalibrating());
  rotate.resetPosition();
  std::cout << "Done Calibrating" << std::endl;
  wait(500,msec);
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void autonomous(void) {
  matchAuto();
  //skills();
}


void usercontrol(void) {
  // User control code here, inside the loop
  int frontPos = 0;
  int backPos = 2;
  clawBack.open();
  clawFront.open();
  while (true) {
    float curvedY = (float)Controller1.Axis3.position(pct);
    float curvedX = (float)Controller1.Axis4.position(pct);
    if(fabs(Controller1.Axis2.position(pct))> 5) flip.spin(fwd, -Controller1.Axis2.position(pct), pct);
    else flip.stop(hold);
    if(fabs(curvedX) < 10) curvedX = 0;
    if(fabs(curvedY) < 10) curvedY = 0;
    leftDrive.spin(fwd, curvedY + (curvedX*0.3), pct);
    rightDrive.spin(fwd, curvedY - (curvedX*0.3), pct);
    if(Controller1.ButtonL1.pressing()){
      clawFront.set(!clawFront.value());
      while(Controller1.ButtonL1.pressing());
    }
    if(Controller1.ButtonR2.pressing()){
      if(frontPos == 0){
        clawLiftBackL.close();
        clawLiftBackR.close();
        frontPos = 1;
      }
      else if(frontPos == 1){
        clawLiftBackL.open();
        clawLiftBackR.open();
        frontPos = 2;
      }
      else{
        clawLiftBackL.open();
        clawLiftBackR.close();
        frontPos = 0;
      }
      while(Controller1.ButtonR2.pressing());
    }
    if(Controller1.ButtonR1.pressing()){
      clawBack.set(!clawBack.value());
      while(Controller1.ButtonR1.pressing());
    }
    if(Controller1.ButtonL2.pressing()){
      if(backPos == 0){
        clawLiftFrontL.close();
        clawLiftFrontR.open();
        backPos = 1;
      }
      else if(backPos == 1){
        clawLiftFrontL.open();
        clawLiftFrontR.close();
        backPos = 2;
      }
      else{
        clawLiftFrontL.open();
        clawLiftFrontR.open();
        backPos = 0;
      }
      while(Controller1.ButtonL2.pressing());
    }
    if(Controller2.ButtonR1.pressing()){
      intakeB.spin(fwd, 100, pct);
    }
    else if(Controller2.ButtonR2.pressing()){
      intakeB.spin(reverse, 100, pct);
    }
    else{
      intakeB.stop(coast);
    }
    if(Controller2.ButtonL1.pressing()){
      intakeF.spin(fwd, 100, pct);
    }
    else if(Controller2.ButtonL2.pressing()){
      intakeF.spin(reverse, 100, pct);
    }
    else{
      intakeF.stop(coast);
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
