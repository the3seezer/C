/*
theBitRiddler
1/14/2024
9:54 AM
The Tortoise Controller
Tortoise
 Fast plod   50%   3 squares to the right
 Slip        30%   6 squares to the left
 Slow plod   20%   1 square to the right
 //RAD_CONVERSION Used 5 instead of 4.985044865 noise reasons
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Webots/robot.h>
#include <Webots/motor.h>

#define MAX_SPEED 6.28
#define TORTOISE_MOTORS 2
#define RAD_CONVERSION 5 
#define RACE_DISTANCE 70 

static WbDeviceTag tortoise_motors[ TORTOISE_MOTORS ];
static const char *tortoise_motor_names[ TORTOISE_MOTORS ] = {
        "right wheel motor", "left wheel motor"
};
      
void moveTortoise( double * snapperPtr );
void printCurrentPosition( double * snapperPtr );
void step();

int main( int argc, char ** argv ) {
    srand( time(NULL) );
    double tortoise = 0;

    wb_robot_init();
    for (int i = 0; i < TORTOISE_MOTORS; ++i ) {
      tortoise_motors[ i ] = wb_robot_get_device( tortoise_motor_names[ i ] );
    } // end for

    while ( tortoise != RACE_DISTANCE ) {
        moveTortoise( &tortoise );
        printCurrentPosition( &tortoise );
    } // end while
    
    
    for (int i = 0; i < TORTOISE_MOTORS; ++i ) {
      wb_motor_set_velocity( tortoise_motors[ i ], 0.25 * MAX_SPEED );
      wb_motor_set_position( tortoise_motors[ i ], tortoise * RAD_CONVERSION );
      step();
    } // end for
    
    wb_robot_cleanup();
    return 0;
} /* end main */

void moveTortoise( double * snapperPtr ) {
    int x = 0;
    
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
    if ( * snapperPtr < 0 ) 
        *snapperPtr = 0;   
    if ( * snapperPtr > RACE_DISTANCE )
        * snapperPtr = RACE_DISTANCE;
    
    return ;
} /* end function moveTortoise */

void printCurrentPosition( double * snapperPtr ) {

    for ( int count = 1; count <= RACE_DISTANCE; count++ )

    if ( * snapperPtr == count ) {
        printf_s( "%s", "T" );
    } // end if
    else {
        printf_s( "%s", " " );
    } // end else

    puts(""); 

} /* end function printCurrentPosition */

void step() {
  const double time_step = wb_robot_get_basic_time_step();
  if ( wb_robot_step( time_step ) == -1 ) {
    wb_robot_cleanup();
    exit(0);
  } // end if
} /* end function step */