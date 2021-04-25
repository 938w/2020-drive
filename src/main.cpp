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
// FrontRoller          motor         1               
// BackRoller           motor         2               
// Controller1          controller                    
// LeftIntake           motor         3               
// RightIntake          motor         4               
// FrontLeft            motor         5               
// FrontRight           motor         6               
// BackRight            motor         12              
// BackLeft             motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

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
   // Initializing Robot Configuration. DO NOT REMOVE!
  FrontRoller.setVelocity(80.01,percent);
  BackRoller.setVelocity(100,percent);
  
  LeftIntake.setVelocity(100,percent);
  RightIntake.setVelocity(100,percent);
  
  FrontLeft.setVelocity(100,percent);
  FrontRight.setVelocity(100,percent);
  BackLeft.setVelocity(100,percent);
  BackRight.setVelocity(100,percent);

  //Intake flip out
  LeftIntake.spin(reverse);
  RightIntake.spin(reverse);
  wait (1, sec);
  LeftIntake.stop();
  RightIntake.stop();
  //Move forward to goal and intakes
  FrontLeft.spin(forward);
  FrontRight.spin(forward);
  BackLeft.spin(forward);
  BackRight.spin(forward);
  LeftIntake.spin(forward);
  RightIntake.spin(forward);
  wait (.7, sec);
  BackRoller.spin(reverse);
  FrontRoller.spin(forward);
  wait (.53, sec);
  FrontLeft.stop();
  FrontRight.stop();
  BackLeft.stop();
  BackRight.stop();
  BackRoller.spin(forward);
  FrontRoller.spin(reverse);
  wait(0.25, sec);
  BackRoller.spin(reverse);
  FrontRoller.spin(forward);
  wait (0.6, sec);
  LeftIntake.spin(reverse);
  RightIntake.spin(reverse);
  wait (0.05, sec);
  BackRoller.stop();
  FrontRoller.stop();
  LeftIntake.spin(reverse);
  RightIntake.spin(reverse);
  wait (.4, sec);
  LeftIntake.stop();
  RightIntake.stop();
  //Intakes ball out
  LeftIntake.spin(forward);
  RightIntake.spin(forward);
  wait (1, sec);
  LeftIntake.stop();
  RightIntake.stop();
  FrontRoller.spin(reverse);
  BackRoller.spin(forward);
  wait (.45, sec);
  FrontRoller.spin(forward);
  BackRoller.spin(reverse);
  wait (.6, sec);
  FrontRoller.stop();
  BackRoller.stop();
  //Back out
  LeftIntake.spin(reverse);
  RightIntake.spin(reverse);
  wait(0.2, sec);
  FrontLeft.spin(reverse);
  FrontRight.spin(reverse);
  BackLeft.spin(reverse);
  BackRight.spin(reverse);
  wait (0.85, sec);
  FrontLeft.stop();
  FrontRight.stop();
  BackLeft.stop();
  BackRight.stop();
  LeftIntake.stop();
  RightIntake.stop();
}
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................


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
  
    // Initializing Robot Configuration. DO NOT REMOVE!
  FrontRoller.setVelocity(80.000000000000001,percent);
  BackRoller.setVelocity(100,percent);
  
  LeftIntake.setVelocity(100,percent);
  RightIntake.setVelocity(100,percent);
  
  FrontLeft.setVelocity(100,percent);
  FrontRight.setVelocity(100,percent);
  BackLeft.setVelocity(100,percent);
  BackRight.setVelocity(100,percent);

  while (1){

    //strafe boolean to int
    int blj = 0;
    int brj = 0;
    int buj = 0;
    int bdj = 0;
    if (Controller1.ButtonLeft.pressing()) {
      blj = 100;
    }
    if (!Controller1.ButtonLeft.pressing()) {
      blj = 0;
    }
    if (Controller1.ButtonRight.pressing()) {
      brj = 100;
    }
    if (!Controller1.ButtonRight.pressing()) {
      brj = 0;
    }
    if (Controller1.ButtonUp.pressing()) {
      buj = 100;
    }
    if (!Controller1.ButtonUp.pressing()) {
      buj = 0;
    }
    if (Controller1.ButtonDown.pressing()) {
      bdj = 100;
    }
    if (!Controller1.ButtonDown.pressing()) {
      bdj = 0;
    }
    //LiftSystem coding:
    if (Controller1.ButtonL1.pressing()) {
      FrontRoller.spin(forward);
      BackRoller.spin(reverse);
    }

    if (Controller1.ButtonR1.pressing()) {
      FrontRoller.spin(reverse);
      BackRoller.spin(forward);

    }

    if (!Controller1.ButtonL1.pressing() && !Controller1.ButtonR1.pressing()) {
      FrontRoller.stop();
      BackRoller.stop();
    }

    //Intake Coding
    if (Controller1.ButtonL2.pressing()) {
      LeftIntake.spin(forward);
      RightIntake.spin(forward);
    }

    if (Controller1.ButtonR2.pressing()) {
      LeftIntake.spin(reverse);
      RightIntake.spin(reverse);
    }

    if (!Controller1.ButtonL2.pressing() && !Controller1.ButtonR2.pressing()) {
      LeftIntake.stop();
      RightIntake.stop();
    }

    //Drive Train Coding
    FrontLeft.spin(vex::directionType::rev, (Controller1.Axis3.position()+brj-blj+buj-bdj), vex::velocityUnits::pct);
    FrontRight.spin(vex::directionType::rev, (Controller1.Axis2.position()-brj+blj+buj-bdj)*0.9, vex::velocityUnits::pct);
    BackLeft.spin(vex::directionType::rev, (Controller1.Axis3.position()-brj+blj+buj-bdj), vex::velocityUnits::pct);
    BackRight.spin(vex::directionType::rev, (Controller1.Axis2.position()+brj-blj+buj-bdj)*0.9, vex::velocityUnits::pct);
    
    //FrontLeft.spin(vex::directionType::fwd, (Controller1.Axis3.position()+Controller1.Axis4.position())+Controller1.Axis1.position(), vex::velocityUnits::pct);
    //FrontRight.spin(vex::directionType::fwd, (Controller1.Axis3.position()-Controller1.Axis4.position())-Controller1.Axis1.position(), vex::velocityUnits::pct);
    //BackLeft.spin(vex::directionType::fwd, (Controller1.Axis3.position()+Controller1.Axis4.position())-Controller1.Axis1.position(), vex::velocityUnits::pct);
    //BackRight.spin(vex::directionType::fwd, (Controller1.Axis3.position()-Controller1.Axis4.position())+Controller1.Axis1.position(), vex::velocityUnits::pct);
    
    
    
    
    wait(8,msec);
  }
}
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

   


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
