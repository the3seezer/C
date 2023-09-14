/*
theBitRiddler
9/14/2023
11:13 AM
Maze TRaversal
*/
#include <stdio.h>

#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3
#define X_START 2
#define Y_START 0

void mazeTraversal( char maze[][ 12 ], int xCoord, int yCoord, int direction );
void printMaze( char maze[][ 12 ] );
int validMove( char maze[][ 12 ], int r, int c );
int coordAtEdge( int x, int y );

int main( void ) {
    char maze[ 12 ][ 12 ] = { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
                              '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',
                              '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#',
                              '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#',
                              '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '#',
                              '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                              '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                              '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                              '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#',
                              '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#',
                              '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#',
                              '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' };
    
    mazeTraversal( maze, X_START, Y_START, RIGHT );
    return 0;

} /* end main */

void printMaze( char maze[][ 12 ] ) {
    for ( size_t i = 0; i < 12; i++ ) {
        for (size_t j = 0; j < 12; j++ ) {
            printf("%c ", maze[i][j]);
        } // end for
        printf("\n");
    }// end for 
    puts("Hit return to see another move");
    getchar();
} /* end function printMaze */

void mazeTraversal( char maze[][ 12 ], int xCoord, int yCoord, int direction ) {
    static int flag = 0; // start flag

    maze[ xCoord ][ yCoord ] = 'X';
    printMaze( maze );

    if ( coordAtEdge( xCoord, yCoord ) && xCoord != X_START && yCoord != Y_START ) {
        printf_s( "%s", "\nMaze successfully exited!\n\n" );
        return;
    } // end if
    else if ( xCoord == X_START && yCoord == Y_START && flag == 1 ) {
        printf_s( "%s", "You arrived back at the starting position\n\n" );
        return;
    } // end if
    else {
        int move = 0; 
        int count = 0;

        flag = 1;

        for ( move = direction, count = 0; count < 4; count++, move++, move %= 4 ) {

            switch( move ) {
                case DOWN: 
                    if ( validMove( maze, xCoord + 1, yCoord ) ) {
                        mazeTraversal( maze, xCoord + 1, yCoord, LEFT );
                    } // end if
                    break;
                case RIGHT: 
                    if ( validMove( maze, xCoord, yCoord + 1 ) ) {
                        mazeTraversal( maze, xCoord, yCoord + 1, DOWN );
                    } // end if
                    break;
                case UP: 
                    if ( validMove( maze, xCoord - 1, yCoord ) ) {
                        mazeTraversal( maze, xCoord - 1, yCoord, RIGHT );
                    } // end if
                    break;
                case LEFT: 
                    if ( validMove( maze, xCoord, yCoord - 1 ) ) {
                        mazeTraversal( maze, xCoord, yCoord - 1, UP );
                    } // end if
            } // end switch
        } // end for
    } // end else

} /* end function mazeTraversal */

int validMove( char maze[][ 12 ], int r, int c ) {
    return ( r >= 0 && r <= 11, c >= 0 && c <= 11 && maze[ r ][ c ] == '.' );
} /* end function validMove */

int coordAtEdge( int x, int y ) {

    if ( ( x < 0 || x > 11 ) && ( y >= 0 && y <= 11 ) ) {
        return 1;
    } // end if
    else if ( ( y < 0 || y > 11 ) && ( x >= 0 && x <= 11 ) ) {
        return 1;
    } // end else if
    else {
        return 0; // valid move
    } // end else 
} /* end functio coordAtEdge */