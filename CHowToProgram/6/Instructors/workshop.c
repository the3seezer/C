/* theBitRiddler
   6/3/2023
   4:22 PM
   turtleGraphics
*/
#include <stdio.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

void getCommands( int commands[][ 2 ] );
int turnRight( int d );
int turnLeft( int d );
void movePen( int down, int a[][ 50 ], int dir, int dist );
void printArray( const int b[][ 50 ] );

int main( void ) {
    int floor[ 50 ][ 50 ] = { 0 };
    int penDown = 0;
    int command = 0;
    int distance = 0;
    int commandArray[ MAX ][ 2 ] = { 0 };
    int direction = 0;
    int count = 0;

    getCommands( commandArray );
    command = commandArray[ count ][ 0 ];

    while ( command != 9 ) {

        switch ( command ) {
            case 1: 
                penDown = FALSE;
                break;

            case 2: 
                penDown = TRUE;
                break;

            case 3:
                direction = turnRight( direction );
                break;

            case 4: 
                direction = turnLeft( direction );
                break;

            case 5: 
                distance = commandArray[ count ][ 1 ];
                movePen( penDown, floor, direction, distance );
                break;

            case 6: 
                printf_s( "%s", "The drawing is \n" );
                printArray( floor );
                break;
            
        } /* end switch */

        command = commandArray[ ++count ][ 0 ];

    } /* end while */

    return 0;

} /* end main */

void getCommands( int commands[][ 2 ] ) {
    int m = 0;
    int tempCommand = 0;

    printf_s( "%s", "Enter command ( 9 to end ): " );
    scanf_s( "%d", &tempCommand );

    for ( m = 0; m < MAX && tempCommand != 9; m++ ) {
        commands[ m ][ 0 ] = tempCommand;

        if ( tempCommand == 5 ) {
            scanf_s( ",%d", &commands[ m ][ 1 ] );
        }

        printf_s( "%s", "Enter command ( 9 to end ): " );
        scanf_s( "%d", &tempCommand );
    }

    commands[ m ][ 0 ] = 9;

} /* end function getCommands */

int turnRight( int d ) {
    return ++d > 3 ? 0 : d;
} /* end function turnRight */

int turnLeft( int d ) {
    return --d < 0 ? 3 : d;
} /* end function turnLeft */

void movePen( int down, int a[][ 50 ], int dir, int dist ) {
    int i = 0;
    int j = 0;
    static int xPos = 0;
    static int yPos = 0;

    switch ( dir ) {

        /* move right */
        case 0: 
            for ( j = 1; j <= dist && yPos + j < 50; j++ ) {
                if ( down ) {
                    a[ xPos ][ yPos + j ] = 1;
                } /* end if */
                
            } /* end for*/
            yPos += j - 1;
            break;

        /* move down */
        case 1:
            for ( i = 1; i <= dist && xPos + i < 50; i++ ) {
                if ( down ) {
                    a[ xPos + i ][ yPos ] = 1;
                } /* end if */

            } /* end for */
            xPos += i - 1;
            break;

        /* move left */
        case 2: 
            for ( j = 1; j <= dist && yPos - 1 >= 0; j++ ) {
                if ( down ) {
                    a[ xPos ][ yPos - j ] = 1;
                } /* end if */

            } /* end for */
            yPos -= j - 1;
            break;

        /* move up */
        case 3: 
            for ( i = 1; i <= dist && xPos >= 0; i++ ) {
                if ( down ) {
                    a[ xPos - i ][ yPos ] = 1;
                } /* end if */

            } /* end for */
            xPos -= i - 1;
            break;
    } /* end switch */

} /* end function movePen */

void printArray(const int b[][ 50 ] ) {
    for ( size_t i = 0; i < 50; i++ ) {

        for ( size_t j = 0; j < 50; j++ ) {
            putchar( b[ i ][ j ] ? '*' : ' ' );
        } /* end for */

        putchar( '\n' );

    } /* end for */
} /* end printArray */