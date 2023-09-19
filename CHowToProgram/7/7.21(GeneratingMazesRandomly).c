/*
theBitRiddler
9/19/2023
12:30 PM
 (Generating Mazes Randomly) 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 12
#define POSSIBLE_SPACES 100
#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3

int validMove( char [][ SIZE ], int row, int col );
void printMaze( char[][ SIZE ]);
int coodsEdge( int row, int col );
void mazeTraversal( char[][ SIZE ], int xStart, int yStart, int row, int col, int direction );
void mazeGenerator( char[][ SIZE ], int *xPtr, int *yPtr );
int main( void ) {
    srand( time( NULL ) );
    int x = 0;
    int y = 0;
    int xStart = 2;
    int yStart = 0;
    char maze[ SIZE ][ SIZE ] = { 0 }; 
    mazeGenerator( maze, &xStart, &yStart );
    printMaze( maze );
    x = xStart;
    y = yStart;
    mazeTraversal( maze, xStart, yStart, x, y, RIGHT );

} /* end main */

void mazeGenerator( char maze[][ SIZE ], int *xPtr, int *yPtr ) {
    for ( size_t row = 0; row < SIZE; row++ ) {
        for ( size_t col = 0; col < SIZE; col++ ) {
            maze[ row ][ col ] = '#';
        } // end for
    } // end for

    int x = 0;
    int y = 0;
    int a = 0;
    int ePos = 0; // entry position
    int xPos = 0; // exit position
    // create exit and entry position
    do {
        ePos = rand() % 4;
        xPos = rand() % 4;
    } 
    while ( ePos == xPos );

    // create entry while avoiding the corners
    if ( ePos == 0 ) { // LEFT
        *xPtr = rand() % 10 + 1; 
        *yPtr = 0;
        maze[ *xPtr ][ *yPtr ] = '.';
    } // end if
    if ( ePos == 1 ) { // UP
        *xPtr = 0;
        *yPtr = rand() % 10 + 1;
        maze[ *xPtr ][ *yPtr ] = '.';
    } // end if
    if ( ePos == 2 ) { // RIGHT
        *xPtr = rand() % 10 + 1;
        *yPtr = 11;
        maze[ *xPtr ][ *yPtr ] = '.';
    } // end if
    if ( ePos == 3 ) { // DOWN
        *xPtr = 11;
        *yPtr = rand() % 10 + 1;
        maze[ *xPtr ][ *yPtr ] = '.';
    } // end if

    // create exit while avoiding the corners
    if ( xPos == 0 ) { // LEFT
        a = rand() % 10 + 1;
        maze[ a ][ 0 ] = '.';
    } // end if
    if ( xPos == 1 ) { // UP
        a = rand() % 10 + 1;
        maze[ 0 ][ a ] = '.';
    } // end if
    if ( xPos == 2 ) { // RIGHT
        a = rand() % 10 + 1;
        maze[ a ][ 11 ] = '.';
    } // end if
    if ( xPos == 3 ) { // DOWN
        a = rand() % 10 + 1;
        maze[ 11 ][ a ] = '.';
    } // end if

    // create zeros randomly
    for ( size_t count = 1; count < POSSIBLE_SPACES; count++ ) {
        x = rand() % 10 + 1;
        y = rand() % 10 + 1;
        maze[ x ][ y ] = '.';
    } // end for 

} /* end function mazeGenerator */

void mazeTraversal( char maze[][ SIZE ], int xStart, int yStart, int row, int col, int direction ) {
    static int flag = 0; // start flag

    maze[ row ][ col ] = 'X';
    printMaze(maze);

    if ( coodsEdge( row, col ) && row != xStart && col != yStart ) {
        printf_s( "%s", "You successfully exited the maze\n" );
        return ;
    } // end if
    else if ( row == xStart && col == yStart && flag == 1 ) {
        printf_s( "%s", "Couldn't find an exit!" );
        return ;
    } // end else if
    else {
        int move = 0;
        int count = 0;

        flag = 1;

        for ( move = direction, count = 0; count < 4; count++, move++, move %= 4 ) {
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

        } // end for

    } // end else
} /* end function mazeTraversal */

void printMaze( char maze[][ SIZE ] ) {
    for ( size_t row = 0; row < SIZE; row++ ) {
        for ( size_t col = 0; col < SIZE; col++ ) {
            printf_s( "%c%c", maze[ row ][ col ], ( col < SIZE ) ? ' ' : '\n');
        } // end for
        puts("");
    } // end for
    puts("Return to see another move");
    getchar();
} /* end function printMaze */

int validMove( char maze[][ SIZE ], int row, int col ) {
    return ( row >= 0 && row <= 11 && col >= 0 && col <= 11 && maze[ row ][ col ] == '.' );
} /* end function validMove */

int coodsEdge( int row, int col ) {
    if ( ( row == 0 || row == 11 ) && ( col >= 0 && col <= 11 ) ) {
        return 1;
    } // end if
    else if ( ( col == 0 || col == 11 ) && ( row >= 0 && row <= 11 ) ) {
        return 1;
    } // end else if
    else {
        return 0; // valid move
    } /// end else
} /* end function coodsEdge */