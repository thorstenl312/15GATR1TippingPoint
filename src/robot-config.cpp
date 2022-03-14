#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

motor FrontR = motor(PORT14, ratio6_1, true); 
motor MiddleR = motor(PORT15, ratio6_1, false); 
motor BackR = motor(PORT16, ratio6_1, true); 
motor FrontL = motor(PORT11, ratio6_1, false); 
motor MiddleL = motor(PORT12, ratio6_1, true);
motor BackL = motor(PORT13, ratio6_1, false); 
motor armB = motor(PORT17, ratio36_1, false);
motor armF = motor(PORT19, ratio36_1, false); 

motor intake = motor(PORT18, ratio18_1, true);
motor clampB = motor(PORT7, ratio36_1, false);
motor clampF = motor(PORT2, ratio36_1, false);
motor_group leftDrive = motor_group(FrontL, MiddleL, BackL);
motor_group rightDrive = motor_group(FrontR, MiddleR, BackR);
controller Controller1 = controller(primary);
pneumatics armFP = pneumatics(Brain.ThreeWirePort.F);
pneumatics armBP = pneumatics(Brain.ThreeWirePort.G);
pneumatics flip = pneumatics(Brain.ThreeWirePort.H);
controller Controller2 = controller(partner);
rotation rotate = rotation(PORT9, true);
inertial inertR = inertial(PORT10);
inertial inert = inertial(PORT20);
void vexcodeInit(void) {
  // Nothing to initialize
}