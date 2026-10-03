#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor MotorL1 = motor(PORT16, ratio6_1, true);
motor MotorL2 = motor(PORT17, ratio6_1, true);
motor MotorL3 = motor(PORT18, ratio6_1, true);
motor MotorR1 = motor(PORT13, ratio6_1, false);
motor MotorR2 = motor(PORT14, ratio6_1, false);
motor MotorR3 = motor(PORT15, ratio6_1, false);
controller Controller1 = controller(primary);
inertial Inertial = inertial(PORT19);
rotation Rotation11 = rotation(PORT11, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}