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

#define TIME_STEP 64
#define MAX_SPEED 6.28
#define TORTOISE_MOTORS 2
#define RACE_DISTANCE 70
#define RAD_CONVERSION 4.985044865
#define RAD_RACE_DIST 348.9531406

void moveTortoise( int * snapperPtr );
void printCurrentPosition( int * snapperPtr );

int main( int argc, char ** argv ) {
    srand( time(NULL) );
    int tortoise = 1;
    int tor_pos_gained = 1; // get the max position gain by the tortoise
    int timer = 0;

    wb_robot_init();
    int i = 0;
    WbDeviceTag tortoise_motors[ TORTOISE_MOTORS ];
    char *tortoise_motor_names[ TORTOISE_MOTORS ] = {
        "right wheel motor", "left wheel motor"
    };
    for ( i = 0; i < TORTOISE_MOTORS; i++ ) {
        tortoise_motors[ i ] = wb_robot_get_device( tortoise_motor_names[ i ] );
    } // end for 
    wb_motor_set_position( tortoise_motors[ 0 ], tor_pos_gained * RAD_CONVERSION );
    wb_motor_set_position( tortoise_motors[ 1 ], tor_pos_gained * RAD_CONVERSION );

    while ( wb_robot_step( TIME_STEP ) != -1 && tortoise != RACE_DISTANCE ) {
        
        moveTortoise( &tortoise );
        printCurrentPosition( &tortoise );
        ++timer;
        
        if ( tortoise > tor_pos_gained )
            tor_pos_gained = tortoise;
        
        wb_motor_set_position( tortoise_motors[ 0 ], tor_pos_gained * RAD_CONVERSION );
        wb_motor_set_position( tortoise_motors[ 1 ], tor_pos_gained * RAD_CONVERSION );
    } // end while

    wb_robot_cleanup();

    printf_s( "\nTORTOISE TIME ELAPSED = %d seconds", timer );
    return 0;
} /* end main */

void moveTortoise( int * snapperPtr ) {
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
    if ( * snapperPtr < 1 )
        *snapperPtr = 1;
    if ( * snapperPtr > RACE_DISTANCE )
        * snapperPtr = RACE_DISTANCE;

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