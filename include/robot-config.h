using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor MotorL1;
extern motor MotorL2;
extern motor MotorL3;
extern motor MotorR1;
extern motor MotorR2;
extern motor MotorR3;
extern controller Controller1;
extern inertial Inertial;
extern rotation Rotation11;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );