// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
   
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
TANK_ONE_FORWARD_ROTATION,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(MotorL1,MotorL2,MotorL3),

//Right Motors:
motor_group(MotorR1,MotorR2,MotorR3),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT19,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.75,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
PORT11,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
0.125,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 0;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  
}
#define drive chassis.drive_distance
#define turn chassis.turn_to_angle
#define sleep vex::task::sleep
/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */
void autonomous(void) {
float v=12;
chassis.drive_max_voltage=v;
chassis.turn_max_voltage=v;
chassis.heading_max_voltage=v;
chassis.swing_max_voltage=v;

chassis.set_coordinates(0, 0, 0);

//chassis.drive_to_pose(float X_position, float Y_position, float angle)

//Black
/*
chassis.drive_to_pose(-14,10,140);
drive(-10);
chassis.drive_to_pose(20,140,-140);   
drive(14);
chassis.drive_distance(14, 90);
chassis.drive_distance(20, 45);
*/
//chassis.drive_to_pose(float X_position, float Y_position, float angle)
//chassis.drive_to_pose(float X_position, float Y_position, float angle)
//chassis.drive_to_pose(60,30,-180);
drive(8);
chassis.drive_distance(-9, 45);
chassis.drive_distance(-8,-45);

chassis.drive_timeout=400;

drive(-8);
drive(8);
drive(-8);
Inertial.resetHeading();
chassis.set_coordinates(0, 0, 0);
chassis.drive_timeout=2000;
chassis.turn_to_angle(33);
//add an intake
chassis.drive_distance(36);
sleep(300);
chassis.turn_timeout = 1500;
chassis.turn_to_angle(170);

chassis.drive_timeout=700;

drive(11);
//chassis.drive_to_point(24, 31);
//drive(14);
chassis.drive_stop(brake);
drive(-8);
turn(120);

chassis.drive_timeout=1600;

drive(23);
turn(-100);


drive(12);

/*
chassis.drive_to_point(7,-14);
drive(-6);
drive(8);
drive(-14);
drive(32);
drive(30);
chassis.turn_to_angle(174);
*/

//chassis.drive_distance(-8);
//chassis.drive_distance(35, -90,100,100);
//chassis.drive_distance(float distance, float heading, float drive_max_voltage, float heading_max_voltage)

//chassis.drive_with_voltage(float leftVoltage, float rightVoltage)
//chassis.drive_distance(float distance, float heading, float drive_max_voltage, float heading_max_voltage)
}

  /*
  auto_started = true; // Alerts pre_auton that autonomous has begun

  // 1. Reset your heading before starting the curve
  chassis.set_heading(0);

  // 2. Execute the 90-degree curve turn (Right turn example)
  // We want to loop until the absolute heading is past 90 degrees.
  while(chassis.get_absolute_heading() < 90.0) {
    
    // Give Left (outside) motors 10 Volts and Right (inside) motors 2 Volts.
    // Adjust these numbers to change your curve speed/radius!
    chassis.drive_with_voltage(10.0, 2.0); 
    
    task::sleep(10); // Small pause to prevent CPU hogging
  }

  // 3. IMMEDIATELY transition into driving straight without a single stutter
  // We feed both sides 9 Volts right away so it keeps rolling fluidly.
  chassis.drive_with_voltage(9.0, 9.0);
  task::sleep(1000); // Drive straight for 1 second

  // 4. Finally, stop the drivetrain completely at the very end of your path
  chassis.drive_with_voltage(0, 0);*/


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    chassis.control_arcade();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
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
