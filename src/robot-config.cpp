#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontRoller = motor(PORT1, ratio6_1, false);
motor BackRoller = motor(PORT2, ratio6_1, true);
controller Controller1 = controller(primary);
motor LeftIntake = motor(PORT3, ratio18_1, false);
motor RightIntake = motor(PORT4, ratio18_1, true);
motor FrontLeft = motor(PORT5, ratio18_1, false);
motor FrontRight = motor(PORT6, ratio18_1, true);
motor BackRight = motor(PORT12, ratio18_1, true);
motor BackLeft = motor(PORT8, ratio18_1, false);

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