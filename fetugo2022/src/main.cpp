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
  bum();
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
  banda.setVelocity(75,percent);
  disparador.setVelocity(70, percent);
  disparador2.setVelocity(70, percent);
  rodillo.setVelocity(100, percent);
  while (1) {
    /*
    double motor1 = LeftA.temperature(temperatureUnits::celsius),
        motor2 = LeftB.temperature(temperatureUnits::celsius),
        motor3 = LeftC.temperature(temperatureUnits::celsius),
        motor4 = LeftD.temperature(temperatureUnits::celsius),
        motor5 = RightA.temperature(temperatureUnits::celsius),
        motor6 = RightB.temperature(temperatureUnits::celsius),
        motor7 = RightC.temperature(temperatureUnits::celsius),
        motor8 = RightD.temperature(temperatureUnits::celsius),
        motor9 = disparador.temperature(temperatureUnits::celsius),
        motor10 = disparador2.temperature(temperatureUnits::celsius),
        motor11 =  banda.temperature(temperatureUnits::celsius),
        motor12 = gato.temperature(temperatureUnits::celsius);
      
      Brain.Screen.printAt(0, 15,"leftMotorA %f",motor1);
      Brain.Screen.printAt(0, 35,"leftMotorB %f",motor2);
      Brain.Screen.printAt(0, 55,"leftMotorC %f",motor3);
      Brain.Screen.printAt(0, 75,"rightMotorA %f",motor4);
      Brain.Screen.printAt(0, 95,"rightMotorB %f",motor5);
      Brain.Screen.printAt(0, 115,"rightMotorC %f",motor6);
      Brain.Screen.printAt(0, 135,"gun %f",motor7);
      Brain.Screen.printAt(0, 155,"banda %f",motor8);
      Brain.Screen.printAt(0, 175,"gato %f",motor9);
     

    double arreglo[13]={motor1,motor2,motor3,motor4,motor5,motor6,motor7,motor8,motor9,motor10,motor11,motor12};
    if((arreglo[0]>=50) || (arreglo[1]>=50) || (arreglo[2]>=50)|| (arreglo[3]>=50) || 
    (arreglo[4]>=50) ||(arreglo[5]>=50) ||(arreglo[6]>=50) || (arreglo[7]>=50) || (arreglo[8]>=50) || (arreglo[9]>=50) || (arreglo[10]>=50) || (arreglo[11]>=50) || (arreglo[12]>=50)){
      Drivetrain.stop();
      banda.stop();
      rodillo.stop();
      pistola.stop();
      }
*/
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

  if(control.ButtonL2.pressing() && x == 1){
    rodillo.spin(reverse);
    task::sleep(200);
    x = 2;
  }
  else if (control.ButtonL2.pressing() && x == 2) {
  rodillo.stop();
  task::sleep(200);
  x = 1;
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
//GG well played//