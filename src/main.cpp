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
  inertR.calibrate();
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
  armF.setStopping(hold);
  armB.setStopping(hold);
  clampF.setStopping(hold);
  clampB.setStopping(hold);
  //task cc(clampControl);
  while (true) {
    armBP.close();
    armFP.open();
    float curvedY = (float)Controller1.Axis3.position(pct);
    float curvedX = (float)Controller1.Axis4.position(pct);
    if(fabs(curvedX) < 10) curvedX = 0;
    if(fabs(curvedY) < 10) curvedY = 0;
    leftDrive.spin(fwd, curvedY + (curvedX*0.3), pct);
    rightDrive.spin(fwd, curvedY - (curvedX*0.3), pct);
    intake.spin(fwd, Controller2.ButtonA.pressing() * 100 + Controller2.ButtonB.pressing() * -100, pct);
    if(abs(Controller1.Axis2.position(pct)) > 5){
      armF.spin(fwd, Controller1.Axis2.position(pct), pct);
    }
    else{
      armF.stop(hold);
    }
    if(abs(Controller2.Axis3.position(pct)) > 5){
      armB.spin(fwd, Controller2.Axis3.position(pct), pct);
    }
    else{
      armB.stop(hold);
    }
    if(Controller2.ButtonL2.pressing()){
      flip.set(!flip.value());
      while(Controller2.ButtonL2.pressing());
    }
    if(Controller1.ButtonR2.pressing()){
      clampF.spin(fwd, 100, pct);
    }
    else if(Controller1.ButtonR1.pressing()){
      clampF.spin(reverse, 100, pct);
    }
    else{
      clampF.stop(hold);
    }
    if(Controller2.ButtonR2.pressing()){
      clampB.spin(fwd, 100, pct);
    }
    else if(Controller2.ButtonR1.pressing()){
      clampB.spin(reverse, 100, pct);
    }
    else{
      clampB.stop(hold);
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
