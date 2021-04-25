using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FrontRoller;
extern motor BackRoller;
extern controller Controller1;
extern motor LeftIntake;
extern motor RightIntake;
extern motor FrontLeft;
extern motor FrontRight;
extern motor BackRight;
extern motor BackLeft;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );