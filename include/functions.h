#pragma once
#include "vex.h"

void stopDrive(brakeType b);
int clampControl();
int armDeploy();
void driveIntoWall(int maxSpeed, int accel);
int gripperControl();