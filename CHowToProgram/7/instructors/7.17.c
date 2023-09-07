#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void moveTortoise( int * tortoisePtr );
void moveHare( int *harePtr );
void printCurrentPosition( int * snapperPtr, int * bunnyPtr );

int main(void) {
    int tortoise = 1;
    int hare = 1;
    int timer = 0;

    srand( time( NULL ) );

    puts("ON YOUR MARK, GET SET\nBANG !!!!!\nAND THEY'RE OFF !!!!!");

    while ( tortoise != 70 && hare != 70 ) {
        moveTortoise( &tortoise );
        moveHare( &hare );
        printCurrentPosition( &tortoise, &hare );

        ++timer;
    } // end while

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
    if ( * tortoise > 70 )
        *tortoise = 70;

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
    if ( *hare > 70 )
        *hare = 70;
} /* end function moveHare */

void printCurrentPosition( int * snapperPtr, int * bunnyPtr ) {

    for ( int count = 1; count <= 70; count++ )


    if ( *snapperPtr == count && *bunnyPtr == count ) {
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