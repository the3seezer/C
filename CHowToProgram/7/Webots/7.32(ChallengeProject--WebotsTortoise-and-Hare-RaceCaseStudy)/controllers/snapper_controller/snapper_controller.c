/*
theBitRiddler
1/14/2024
9:54 AM
The Tortoise Controller
Tortoise
 Fast plod   50%   3 squares to the right
 Slip        30%   6 squares to the left
 Slow plod   20%   1 square to the right
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Webots/robot.h>
#include <Webots/motor.h>

#define MAX_SPEED 6.28
#define TORTOISE_MOTORS 2
#define RACE_DISTANCE 70
#define RAD_CONVERSION 4.985044865

static WbDeviceTag tortoise_motors[ TORTOISE_MOTORS ];
static const char *tortoise_motor_names[ TORTOISE_MOTORS ] = {
        "right wheel motor", "left wheel motor"
};

void moveTortoise( int * snapperPtr );
void printCurrentPosition( int * snapperPtr );

void step() {
  const double time_step = wb_robot_get_basic_time_step();
  if ( wb_robot_step( time_step ) == -1 ) {
    wb_robot_cleanup();
    exit(0);
  } // end if
} /* end function step */

void movement_decomposition( const double * target, double duration ) {
  const double time_step = wb_robot_get_basic_time_step();
  const int n_steps_to_achieve_target = duration * 1000 / time_step;
  double current_position[TORTOISE_MOTORS];
  double step_difference[TORTOISE_MOTORS];
  
  for ( int i = 0; i < TORTOISE_MOTORS; i++ ) {
    current_position[ i ] = wb_motor_get_target_position( tortoise_motors[ i ] );
    step_difference[ i ] = (target[ i ] - current_position[ i ] ) / n_steps_to_achieve_target;
  } // end for
  
  for ( int i = 0; i < n_steps_to_achieve_target; ++i ) {
    for ( int j = 0; j < TORTOISE_MOTORS; j++ ) {
      current_position[ j ] += step_difference[ j ];
      wb_motor_set_position( tortoise_motors[ j ], current_position[ j ] );
    } // end for
    step();
  } // end for
} /* end function movement_decomposition */

int main( int argc, char ** argv ) {
    srand( time(NULL) );
    int tortoise = 1;
    int timer = 0;

    wb_robot_init();
    int i = 0;
    
    for ( i = 0; i < TORTOISE_MOTORS; i++ ) {
        tortoise_motors[ i ] = wb_robot_get_device( tortoise_motor_names[ i ] );
    } // end for 

    while ( tortoise != RACE_DISTANCE ) {
        
        moveTortoise( &tortoise );
        printCurrentPosition( &tortoise );
        ++timer;
        
        // wb_motor_set_position( tortoise_motors[ 0 ], tor_step * RAD_CONVERSION );
        // wb_motor_set_position( tortoise_motors[ 1 ], tor_step * RAD_CONVERSION );
    } // end while

    wb_robot_cleanup();

    printf_s( "\nTORTOISE TIME ELAPSED = %d seconds", timer );
    return 0;
} /* end main */

void moveTortoise( int * snapperPtr ) {
    int x = 0;
    double duration = 0.1;
    double wheels_position[TORTOISE_MOTORS];
    x = rand() % 10 + 1;

    if ( x >= 1 && x <= 5 ) {
        * snapperPtr += 3;
    } // end if
    else if ( x == 6 || x == 7 ) {
        * snapperPtr -= 6;
    } // end else if
    else {
        ++( * snapperPtr );
    } // end else

    // check boundaries
    if ( * snapperPtr < 1 ) {
      *snapperPtr = 1;
    } // end if
        
    if ( * snapperPtr > RACE_DISTANCE )
        * snapperPtr = RACE_DISTANCE;
    
    for ( int i = 0; i < TORTOISE_MOTORS; ++i ) {
      wheels_position[ i ] = *snapperPtr * RAD_CONVERSION;
    } // end for   
    movement_decomposition( wheels_position, duration );

    return ;
} /* end function moveTortoise */

void printCurrentPosition( int * snapperPtr ) {

    for ( int count = 1; count <= 70; count++ )

    if ( * snapperPtr == count ) {
        printf_s( "%s", "T" );
    } // end if
    else {
        printf_s( "%s", " " );
    } // end else

    puts(""); 

} /* end function printCurrentPosition */