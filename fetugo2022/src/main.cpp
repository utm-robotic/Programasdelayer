/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, 21        
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "F.h"


using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
int x=1;
void usercontrol(void) {
  lefft.setMaxTorque(100, percent);
  Right.setMaxTorque(100, percent);
  lefft.setVelocity(100, percent);
  Right.setVelocity(100, percent);
  banda.setVelocity(100,percent);
  disparador.setVelocity(100, percent);
  disparador2.setVelocity(100, percent);
  while (1) {
    if(control.Axis3.value()>50 || control.Axis3.value()<-50){
        lefft.spin(fwd, control. Axis3. value(), percent);
    }
    else {
  lefft.stop();
    }
    if(control.Axis2.value()>50 || control.Axis2.value()<-50){
    Right.spin(fwd, control. Axis2.value(),percent);
    }
    else{
      Right.stop();
    }
   
 
  if(control.ButtonR1/*R1*/.pressing()&& x==1){
    banda.spin(reverse);
    task::sleep(200);
    x=2;
  }
  else if (control.ButtonR1.pressing()&& x==2) {
  banda.spin(fwd);
  task::sleep(200);
  x=1;
  }

  control.ButtonB/*X*/.pressed(bandastop);
  control.ButtonX/*R2*/.pressed(impulso);

  if(control.ButtonL1.pressing()&& x==1){
    pistola.spin(fwd);
    task::sleep(200);
    x=2;
  }
  else if(control.ButtonUp.pressing()){
    pistola.spin(reverse);
   
  }

  else if (control.ButtonL1.pressing()&& x==2) {
  pistola.stop(hold);
  task::sleep(200);
  x=1;
  }



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
