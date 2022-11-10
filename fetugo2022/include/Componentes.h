#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftA = motor(PORT17, ratio6_1, false);
motor LeftB = motor(PORT18, ratio6_1, true);
motor LeftC = motor(PORT19, ratio6_1, true);
motor LeftD = motor(PORT20, ratio6_1, false);
motor_group lefft= motor_group(LeftA, LeftB, LeftC, LeftD);
motor RightA = motor(PORT11, ratio6_1, true);
motor RightB = motor(PORT12, ratio6_1, false);
motor RightC = motor(PORT1, ratio6_1, false);
motor RightD = motor(PORT16, ratio6_1, true);
motor_group Right = motor_group(RightA, RightB, RightC, RightD);

motor banda = motor(PORT2, ratio6_1, false);

motor disparador = motor(PORT10, ratio6_1, false);
motor disparador2 = motor(PORT4, ratio6_1, false);
motor_group pistola = motor_group(disparador, disparador2);
inertial DrivetrainInertial = inertial(PORT21);

controller control = controller(primary);

motor gato = motor(PORT6, ratio6_1, true);

smartdrive Drivetrain = smartdrive(lefft , Right, DrivetrainInertial, 299.24, 320, 40, mm, 0.6666666666666666);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}