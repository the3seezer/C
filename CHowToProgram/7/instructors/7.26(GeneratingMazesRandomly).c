/*
theBitRiddler
9/20/2023
11:16 AM
(Generating Mazes Randomly )
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3

void mazeTraversal( char [][ 12 ], const int, const int, int, int, int );
void mazeGenerator( char[][ 12 ], int * , int *);
void printMaze( char[][ 12 ]);
int validMove( char [][ 12 ], int, int );
int coordsAreEdge( int, int );

int main(void) {
    char maze[ 12 ][ 12 ] = { 0 };
    int x = 0;
    int y = 0;
    int xStart = 0;
    int yStart = 0;

    for ( size_t row = 0; row < 12; row++ ) {
        for ( size_t col = 0; col < 12; col++ ) {
            maze[ row ][ col ] = '#';
        } // end for
    } // end for

    mazeGenerator( maze, &xStart, &yStart );

    x = xStart;
    y = yStart; 

    mazeTraversal( maze, xStart, yStart, x, y, RIGHT );

    return 0;

} /* end main */

void mazeTraversal( char maze[][ 12 ], const int xStart, const int yStart, int row, int col, int direction ) {
    static int flag = 0; // create start flag

    maze[ row ][ col ] = 'X';
    printMaze( maze );

    if ( coordsAreEdge( row, col ) && row != xStart && col != yStart ) {
        printf_s( "%s", "You successfully exited the maze\n\n" );
        return;
    } // end if
    else if ( row == xStart && col == yStart && flag == 1 ) {
        printf_s( "%s", "You returned to the starting point\n\n" );
        return;
    } // end else if
    else {
        int move = 0;
        int count = 0;

        flag = 1;

        for ( move = direction, count = 0; count < 4; count++, move++ , move %= 4 ) 

            switch( move ) {
                case DOWN: 
                    if ( validMove( maze, row + 1, col ) ) {
                        mazeTraversal( maze, xStart, yStart, row + 1, col, LEFT );
                    } // end if 
                    break;

                case RIGHT: 
                    if ( validMove( maze, row, col + 1 ) ) {
                        mazeTraversal( maze, xStart, yStart, row, col + 1, DOWN );
                    } // end if
                    break;

                case UP: 
                    if ( validMove( maze, row - 1, col ) ) {
                        mazeTraversal( maze, xStart, yStart, row - 1, col, RIGHT );
                    } // end if
                    break; 

                case LEFT: 
                    if ( validMove( maze, row, col - 1 ) ) {
                        mazeTraversal( maze, xStart, yStart, row, col - 1, UP );
                    } // end if
                    break;
            } // end switch

    } // end else
    
} /* end function mazeTraversal */

int validMove( char maze[][ 12 ], int row, int col ) {
    return ( row >= 0 && row <= 11 && col >= 0 && col <= 11 && maze[ row ][ col ] == '.' );
} /* end function validMove */

int coordsAreEdge( int row, int col ) {
    if ( (row == 0 || row == 11) && ( col >= 0 && col <= 11 ) ) {
        return 1;
    } // end if
    else if ( (col == 0 || col == 11 ) && ( row >= 0 && row <= 11 ) ) {
        return 1;
    } // end if
    else {
        return 0;
    } // end else
} /* end function coordsAreEdge */

void printMaze( char maze[][ 12 ]) {
    for ( size_t row = 0; row < 12; row++ ) {
        for ( size_t col = 0; col < 12; col++ ) {
            printf_s( "%c%c", maze[ row ][ col ], col < 11 ? ' ' : '\n' );
        } // end for
    } // end for

    printf_s( "%s", "Return to see another step\n" );
    getchar();
} /* end function printMaze */

void mazeGenerator( char maze[][ 12 ], int * xPos, int * yPos ) {
    int entry = 0;
    int exit = 0;
    int a = 0;
    int x = 0;
    int y = 0;

    srand( time( NULL ) );

    // create entry and exit points
    do {
        entry = rand() % 4;
        exit = rand() % 4;
    } 
    while ( entry == exit ); // LEFT == 0, up == 1, RIGHT = 2, BOTTOM = 3

    // create entry while avoiding the corners
    if ( entry == 0 ) { 
        *xPos = rand() % 10 + 1;
        *yPos = 0;
        maze[ *xPos ][ *yPos ] = '.';
    } // end if
    if ( entry == 1 ) {
        *xPos = 0;
        *yPos = 1 + rand() % 10;
        maze[ *xPos ][ *yPos ] = '.';
    } // end if
    if ( entry == 2 ) {
        *xPos = 1 + rand() % 10;
        *yPos = 0;
        maze[ *xPos ][ *yPos ] = '.';
    } // end if
    if ( entry == 3 ) {
        *xPos = 0;
        *yPos = 1 + rand() % 10;
        maze[ *xPos ][ *yPos ] = '.';
    } // end if

    // create exit while avoiding the corners
    if ( exit == 0 ) {
        a = rand() % 10 + 1;
        maze[ a ][ 0 ] = '.';
    } // end if
    if ( exit == 1 ) {
        a = rand() % 10 + 1;
        maze[ 0 ][ a ] = '.';
    } // end if
    if ( exit == 2 ) {
        a = rand() % 10 + 1;
        maze[ a ][ 0 ] = '.';
    } // end if
    if ( exit == 3 ) {
        a = rand() % 10 + 1;
        maze[ 0 ][ a ] = '.';
    } // end if

    for ( int count = 0; count < 100; count++ ) {
        x = 1 + rand() % 10;
        y = 1 + rand() % 10;
        maze[ x ][ y ] = '.';
    } // end for
} /* end function mazeGenerator */