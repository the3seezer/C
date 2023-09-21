/*
theBitRiddler
9/21/2023
2:57 AM
Mazes Of Any Size
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10
#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3

void mazeTraversal( char[][ COL ], const int, const int, int, int, int );
void mazeGenerator( char[][ COL ], int*, int* );
void printMaze( char[][ COL ]);
int validMove(char[][ COL ], int, int );
int coordsAreEdge( int, int );

int main(void) {
    int x = 0;
    int y = 0;
    int xStart = 0;
    int yStart = 0;
    char maze[ ROW ][ COL ] = { 0 };

    for ( size_t row = 0; row < ROW; row++ )
        for ( size_t col = 0; col < COL; col++ )
            maze[ row ][ col ] = '#';

    mazeGenerator( maze, &xStart, &yStart );

    x = xStart;
    y = yStart;
    
    mazeTraversal( maze, xStart, yStart, x, y, RIGHT );

    return 0;

} /* end main */

void mazeTraversal( char maze[][ COL ], const int xStart, const int yStart, int row, int col, int direction ) {
    static int flag = 0;
    maze[ row ][ col ] = 'X';
    printMaze(maze);

    if ( coordsAreEdge( row, col ) && row != xStart && col != yStart ) {
        printf_s( "%s", "You successfully exited the maze\n\n");
        return;
    } // end if
    else if ( row == xStart && col == yStart && flag == 1 ) {
        printf_s( "%s", "You arrived back to the starting point\n\n");
        return;
    } // end else if
    else {
        int move = 0;
        int count = 0;

        flag = 1;

        for ( move = direction, count = 0; count < 4; count++, move++, move %= 4 ) {
            switch(move) {
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

void mazeGenerator( char maze[][ COL ], int * xPos, int * yPos ) {
    int x = 0;
    int y = 0;
    int entry = 0;
    int exit = 0;
    int a = 0;

    do {
        entry = rand() % 4;
        exit = rand() % 4;
    }
    while ( entry == exit );

    // entry
    if ( entry == 0 ) {
        *xPos = 1 + rand() % ( ROW - 2 );
        *yPos = 0;
        maze[ *xPos ][ *yPos ] = '.';
    } // end if
    if ( entry == 1 ) {
        *xPos = 0;
        *yPos = 1 + rand() % ( COL - 2 );
        maze[ *xPos ][ *yPos ] = '.';
    } // end if
    if ( entry == 2 ) {
        *xPos = 1 + rand() % ( ROW - 2 );
        *yPos = ( COL - 1 );
        maze[ *xPos ][ *yPos ] = '.';
    } // end if
    if ( entry == 3 ) {
        *xPos = ( ROW - 1 );
        *yPos = 1 + rand() % ( COL - 2 );
        maze[ *xPos ][ *yPos ] = '.';
    } // end if

    // exit
    if ( exit == 0 ) {
        a = 1 + rand() % ( ROW - 2 );
        maze[ a ][ 0 ] = '.';
    } // end if
    if ( exit == 1 ) {
        a = 1 + rand() % ( COL - 2 );
        maze[ 0 ][ a ] = '.';
    } // end if
    if ( exit == 2 ) {
        a = 1 + rand() % ( ROW - 2 );
        maze[ a ][ COL - 1 ] = '.';
    } // end if
    if ( exit == 3 ) {
        a = 1 + rand() % ( COL - 2 );
        maze[ ROW - 1 ][ a ] = '.';
    } // end if

    for ( size_t count = 0; count < ( ROW - 2 ) * ( COL - 2 ); count++ ) {
        x = 1 + rand() % ( ROW - 2 );
        y = 1 + rand() % ( COL - 2 );
        maze[ x ][ y ] = '.';
    } // end for
} /* end function mazeGenerator */

int validMove( char maze[][ COL ], int r, int c ) {
    return ( r >= 0 && r <= ( ROW - 1 ) && c >= 0 && c <= ( COL - 1 ) && maze[ r ][ c ] == '.' );
} /* end function validMove */

int coordsAreEdge( int r, int c ) {
    if ( ( r == 0 || r == ( ROW - 1 ) ) && ( c >= 0 && c <= ( COL - 1 ) ) )
        return 1;
    else if ( ( c == 0 || c == ( COL - 1 ) ) && ( r >= 0 && r <= ( ROW - 1 ) ) )
        return 1;
    else 
        return 0;
} /* end function coordsAreEdge */

void printMaze( char maze[][ COL ]) {
    for ( size_t row = 0; row < ROW; row++ ) {
        for ( size_t col = 0; col < COL; col++ )
            printf_s( "%c%c", maze[ row ][ col ], col < COL - 1 ? ' ' : '\n' );
        puts("");
    } // end for 
    printf_s("%s", "Return to see another move\n");
    getchar();
} /* end function printMaze */