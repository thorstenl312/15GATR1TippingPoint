#include "auton.h"
#include  "spline.h"
#include "functions.h"
#include <iostream>

void matchAuto(){
  flip.spin(fwd, 40, pct);
  leftDrive.spin(fwd, 100, pct);
  rightDrive.spin(fwd, 100, pct);
  wait(670,msec);
  stopDrive(coast);
  wait(50,msec);
  flip.stop(hold);
  driveIntoWall(400, 60);
  flip.spin(reverse, 50, pct);
  wait(250,msec);
  flip.stop(hold);
}
 
void testSkills(){

}