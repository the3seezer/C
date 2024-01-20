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
#define RACE_DISTANCE 70 

void moveHare( int * bunnyPtr );
void printCurrentPosition( int * bunnyPtr );

static WbDeviceTag motors[ NUMBER_OF_JOINTS ];
static const char *motor_names[ NUMBER_OF_JOINTS ] = {
  "front left shoulder abduction motor",  "front left shoulder rotation motor", "front left piston motor", "front left elbow motor",
  "front right shoulder abduction motor", "front right shoulder rotation motor", "front right piston motor", "front right elbow motor",
  "rear left shoulder abduction motor",   "rear left shoulder rotation motor", "rear left piston motor", "rear left elbow motor",
  "rear right shoulder abduction motor",  "rear right shoulder rotation motor", "rear right piston motor", "rear right elbow motor"};

static void step();
static void movement_decomposition( const double *target, double duration );
static void stand_up(double duration);
static void splint( double duration );

int main( int argc, char ** argv ) {
  int hare = 1;
  
  wb_robot_init();
  
  for ( int i = 0; i < NUMBER_OF_JOINTS; ++i )
    motors[ i ] = wb_robot_get_device( motor_names[ i ] );
    
  while ( hare != RACE_DISTANCE ) {
    moveHare( &hare );
    printCurrentPosition( &hare );
  } // end while
  
  stand_up( 0.5 );
  while ( hare ) {
    splint( 0.2 );
    hare--;
  } // end while
 
  wb_robot_cleanup();
  return EXIT_FAILURE;
} /* end main */

void moveHare( int * hare ) {
    int y = 0;

    y = rand() % 10 + 1;

    // sleep for 1 and 2( Do nothing)

    if ( y == 3 || y == 4 ) { // Big hop
        *hare += 9;
    } // end if
    else if ( y == 5 ) { // Big slip
        *hare -= 12;
    } // end else if
    else if ( y >= 6 && y <= 8 ) { // small hop
        ++( *hare );
    } // end else if
    else if ( y == 9 || y == 10 ) { // small slip
        *hare -= 2;
    } // end else if

    // check boundaries
    if ( *hare < 1 )
        *hare = 1;
    if ( *hare > RACE_DISTANCE )
        *hare = RACE_DISTANCE;
} /* end function moveHare */

void printCurrentPosition( int * bunnyPtr ) {

    for ( int count = 1; count <= RACE_DISTANCE; count++ )

    if ( * bunnyPtr == count ) {
        printf_s( "%s", "H" );
    } // end else if
    else {
        printf_s( "%s", " " );
    } // end else

    puts(""); 

} /* end function printCurrentPosition */

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

static void splint( double duration ) {
  // first step
  const double motors_target_pos1[NUMBER_OF_JOINTS] = { -0.1, 0.2,  0.0, 0.1,   // Front left leg
                                                        0.1,  -0.2, 0.0, 0.1,   // Front right leg
                                                        -0.1, -0.2, 0.0, 0.1,   // Rear left leg
                                                        0.1,  0.2,  0.0, 0.1};  // Rear right leg
  movement_decomposition( motors_target_pos1, duration );
  
  // second step
  const double motors_target_pos2[NUMBER_OF_JOINTS] = { -0.1, -0.2, 0.0, 0.1,   // Front left leg
                                                        0.1,  0.2,  0.0, 0.1,   // Front right leg
                                                        -0.1, 0.2,  0.0, 0.1,   // Rear left leg
                                                        0.1,  -0.2, 0.0, 0.1};  // Rear right leg
  movement_decomposition( motors_target_pos2, duration ); 
} /* end function splint */ 

static void stand_up(double duration) {
  const double motors_target_pos[NUMBER_OF_JOINTS] = {-0.1, 0.0, 0.0, 0.0,   // Front left leg
                                                      0.1,  0.0, 0.0, 0.0,   // Front right leg
                                                      -0.1, 0.0, 0.0, 0.0,   // Rear left leg
                                                      0.1,  0.0, 0.0, 0.0};  // Rear right leg

  movement_decomposition(motors_target_pos, duration);
} /* end function stand_up */