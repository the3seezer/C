/* 
theBitRiddler
1/15/2024
9:34 AM
boston dynamic spot moving forward
Hare
 Sleep       20%    No move at all
 Big hop     20%    9 squares to the right
 Big slip    10%    12 squares to the left
 Small hop   30%    1 square to the right
 Small slip  20%    2 squares to the left 
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <webots/motor.h>
#include <webots/robot.h>
#include <webots/device.h>

#define NUMBER_OF_JOINTS 16

static WbDeviceTag motors[ NUMBER_OF_JOINTS ];
static const char *motor_names[ NUMBER_OF_JOINTS ] = {
  "front left shoulder abduction motor",  "front left shoulder rotation motor", "front left piston motor", "front left elbow motor",
  "front right shoulder abduction motor", "front right shoulder rotation motor", "front right piston motor", "front right elbow motor",
  "rear left shoulder abduction motor",   "rear left shoulder rotation motor", "rear left piston motor", "rear left elbow motor",
  "rear right shoulder abduction motor",  "rear right shoulder rotation motor", "rear right piston motor", "rear right elbow motor"};

static void step(){
  const double time_step = wb_robot_get_basic_time_step();
  if (wb_robot_step( time_step ) == -1 ) {
    wb_robot_cleanup();
    exit(0);
  } // end if
} /* end function step */

static void movement_decomposition( const double *target, double duration ) {
  const double time_step = wb_robot_get_basic_time_step();
  const int n_steps_to_achieve_target = duration * 1000 / time_step;
  double current_position[NUMBER_OF_JOINTS];
  double step_difference[NUMBER_OF_JOINTS];
  
  for ( int i = 0; i < NUMBER_OF_JOINTS; ++i ) {
    current_position[ i ] = wb_motor_get_target_position( motors[ i ] );
    step_difference[ i ] = (target[ i ] - current_position[ i ] ) / n_steps_to_achieve_target;
  } // end for
  
  for ( int i = 0; i < n_steps_to_achieve_target; ++i ) {
    for ( int j = 0; j < NUMBER_OF_JOINTS; ++j ) {
      current_position[ j ] += step_difference[ j ];
      wb_motor_set_position( motors[ j ], current_position[ j ] );
    } // end for
    step();
  } // end for
} /* end function movement_decomposition */

static void sleep(double duration) {
  const double motors_target_pos[NUMBER_OF_JOINTS] = {-0.40, -0.99, 0.0, 1.59,   // Front left leg
                                                      0.40,  -0.99, 0.0, 1.59,   // Front right leg
                                                      -0.40, -0.99, 0.0, 1.59,   // Rear left leg
                                                      0.40,  -0.99, 0.0, 1.59};  // Rear right leg
  movement_decomposition(motors_target_pos, duration);
} /* end function sleep */

static void stand_up(double duration) {
  const double motors_target_pos[NUMBER_OF_JOINTS] = {-0.1, 0.0, 0.0, 0.0,   // Front left leg
                                                      0.1,  0.0, 0.0, 0.0,   // Front right leg
                                                      -0.1, 0.0, 0.0, 0.0,   // Rear left leg
                                                      0.1,  0.0, 0.0, 0.0};  // Rear right leg

  movement_decomposition(motors_target_pos, duration);
} /* end function stand_up */

static void sit_down(double duration) {
  const double motors_target_pos[NUMBER_OF_JOINTS] = {-0.20, -0.40, 0.0, -0.19,  // Front left leg
                                                      0.20,  -0.40, 0.0, -0.19,  // Front right leg
                                                      -0.40, -0.90, 0.0, 1.18,   // Rear left leg
                                                      0.40,  -0.90, 0.0, 1.18};  // Rear right leg

  movement_decomposition(motors_target_pos, duration);
} /* end function sit_down */

static void give_paw() {
  // Stabilize posture
  const double motors_target_pos_1[NUMBER_OF_JOINTS] = {-0.20, -0.30, 0.0, 0.05,   // Front left leg
                                                        0.20,  -0.40, 0.0, -0.19,  // Front right leg
                                                        -0.40, -0.90, 0.0, 1.18,   // Rear left leg
                                                        0.49,  -0.90, 0.0, 0.80};  // Rear right leg

  movement_decomposition(motors_target_pos_1, 4);

  const double initial_time = wb_robot_get_time();
  while (wb_robot_get_time() - initial_time < 8) {
    wb_motor_set_position(motors[4], 0.2 * sin(2 * wb_robot_get_time()) + 0.6);  // Upperarm movement
    wb_motor_set_position(motors[5], 0.4 * sin(2 * wb_robot_get_time()));        // Forearm movement
    step();
  }
  // Get back in sitting posture
  const double motors_target_pos_2[NUMBER_OF_JOINTS] = {-0.20, -0.40, 0.0, -0.19,  // Front left leg
                                                        0.20,  -0.40, 0.0, -0.19,  // Front right leg
                                                        -0.40, -0.90, 0.0, 1.18,   // Rear left leg
                                                        0.40,  -0.90, 0.0, 1.18};  // Rear right leg

  movement_decomposition(motors_target_pos_2, 4);
} /* end function give_paw */

static void splint( double duration ) {
  // first step
  const double motors_target_pos1[NUMBER_OF_JOINTS] = {-0.1,  0.2,  0.0, 0.1,   // Front left leg
                                                        0.1,  -0.2, 0.0, 0.1,   // Front right leg
                                                        -0.1, -0.2, 0.0, 0.1,   // Rear left leg
                                                        0.1,  0.2,  0.0, 0.1};  // Rear right leg
  movement_decomposition( motors_target_pos1, duration );
  
  // second step
  const double motors_target_pos2[NUMBER_OF_JOINTS] = {-0.1,  -0.2, 0.0, 0.1,   // Front left leg
                                                        0.1,  0.2,  0.0, 0.1,   // Front right leg
                                                        -0.1, 0.2,  0.0, 0.1,   // Rear left leg
                                                        0.1,  -0.2, 0.0, 0.1};  // Rear right leg
  movement_decomposition( motors_target_pos2, duration ); 
} /* end function splint */ 

int main( int argc, char ** argv ) {
  wb_robot_init();
  
  for ( int i = 0; i < NUMBER_OF_JOINTS; ++i )
    motors[ i ] = wb_robot_get_device( motor_names[ i ] );
  
  stand_up( 0.5 );  
  while(true) {
    splint( 0.2 );
  } // end while
  
  wb_robot_cleanup();
  return EXIT_FAILURE;
} /* end main */