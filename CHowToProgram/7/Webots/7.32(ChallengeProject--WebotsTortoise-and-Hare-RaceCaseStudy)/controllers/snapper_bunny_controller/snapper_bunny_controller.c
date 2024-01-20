#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <webots/motor.h>
#include <webots/robot.h>
#include <webots/device.h>

#define NUMBER_OF_JOINTS 16 
#define RACE_DISTANCE 70 
#define MAX_SPEED 6.28
#define TORTOISE_MOTORS 2
#define RAD_CONVERSION 5 
#define RACE_DISTANCE 70 

void moveTortoise( int * tortoisePtr );
void moveHare( int *harePtr );
void printCurrentPosition( int * snapperPtr, int * bunnyPtr );

// Hare
static WbDeviceTag motors[ NUMBER_OF_JOINTS ];
static const char *motor_names[ NUMBER_OF_JOINTS ] = {
  "front left shoulder abduction motor",  "front left shoulder rotation motor", "front left piston motor", "front left elbow motor",
  "front right shoulder abduction motor", "front right shoulder rotation motor", "front right piston motor", "front right elbow motor",
  "rear left shoulder abduction motor",   "rear left shoulder rotation motor", "rear left piston motor", "rear left elbow motor",
  "rear right shoulder abduction motor",  "rear right shoulder rotation motor", "rear right piston motor", "rear right elbow motor"};
// Tortoise
WbDeviceTag tortoise_motors[ TORTOISE_MOTORS ];
static const char *tortoise_motor_names[ TORTOISE_MOTORS ] = {
        "right wheel motor", "left wheel motor"
};

static void step();
// Hare
static void movement_decomposition( const double *target, double duration );
static void stand_up(double duration);
static void splint( double duration );
static void sleep(double duration);

int main(void) {
    int tortoise = 1;
    int hare = 1;
    int counter = 0; // race counter
    int timer = 0;
    
    wb_robot_init();
  
    for ( int i = 0; i < NUMBER_OF_JOINTS; ++i )
      motors[ i ] = wb_robot_get_device( motor_names[ i ] );
    
    for (int i = 0; i < TORTOISE_MOTORS; ++i ) {
      tortoise_motors[ i ] = wb_robot_get_device( tortoise_motor_names[ i ] );
    } // end for

    srand( time( NULL ) );

    puts("ON YOUR MARK, GET SET\nBANG !!!!!\nAND THEY'RE OFF !!!!!");

    while ( tortoise != RACE_DISTANCE && hare != RACE_DISTANCE ) {
        moveTortoise( &tortoise );
        moveHare( &hare );
        printCurrentPosition( &tortoise, &hare );

        ++timer;
    } // end while
    
    // Set tortoise position
    for (int i = 0; i < TORTOISE_MOTORS; ++i ) {
      wb_motor_set_velocity( tortoise_motors[ i ], 0.0 * MAX_SPEED );
      wb_motor_set_position( tortoise_motors[ i ], tortoise * RAD_CONVERSION );
    } // end for
    
    stand_up( 0.5 );  
    while ( counter != RACE_DISTANCE ) {
      // Hare running
      if ( counter <= hare )
        splint( 0.2 );
      else
        sleep( 0.9 );
      
      // Tortoise moving
      for (int i = 0; i < TORTOISE_MOTORS; ++i ) {
        wb_motor_set_velocity( tortoise_motors[ i ], 0.25 * MAX_SPEED );
        step();
      }
      
      ++counter;
    } // end while
 
    wb_robot_cleanup();

    if ( tortoise >= hare ) {
        printf_s( "%s", "TORTOISE WINS!!! YAY!!!" );
    } // end if
    else if ( tortoise < hare ) {
        printf_s( "%s", "Hare wins. Yuch." );
    } // end else if

    printf_s( "\nTIME ELAPSED = %d seconds", timer );

    return 0;
} /* end main */

void moveTortoise( int * tortoise ) {
    int x = 0;

    x = rand() % 10 + 1;

    if ( x >= 1 && x <= 5 ) { // fast plod
        *tortoise += 3;
    } // end if
    else if ( x == 6 || x == 7 ) { // slip
        *tortoise -= 6;
    } // end if
    else { // slow plod
        ++( * tortoise );
    } // end else

    // check boundaries
    if ( * tortoise < 1 )
        *tortoise = 1;
    if ( * tortoise > RACE_DISTANCE )
        *tortoise = RACE_DISTANCE;

} /* end function moveTortoise */

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

void printCurrentPosition( int * snapperPtr, int * bunnyPtr ) {

    for ( int count = 1; count <= RACE_DISTANCE; count++ )


    if ( * snapperPtr == count && * bunnyPtr == count ) {
        printf_s( "%s", "OUCH!!!");
    } // end if
    else if ( * snapperPtr == count ) {
        printf_s( "%s", "T" );
    } // end else if
    else if ( * bunnyPtr == count ) {
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

// Hare
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

static void sleep(double duration) {
  const double motors_target_pos[NUMBER_OF_JOINTS] = {-0.40, -0.99, 0.0, 1.59,   // Front left leg
                                                      0.40,  -0.99, 0.0, 1.59,   // Front right leg
                                                      -0.40, -0.99, 0.0, 1.59,   // Rear left leg
                                                      0.40,  -0.99, 0.0, 1.59};  // Rear right leg
  movement_decomposition(motors_target_pos, duration);
} /* end function sleep */