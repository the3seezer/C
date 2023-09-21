/*
theBitRiddler
9/20/2023
12:46 PM
(Mazes of Any Size)
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
#define POSSIBLE_DOTS (int) ROW * COL * 2 / 3

void mazeGenerator( char[][ COL ], int *, int * );
void mazeTraversal( char[][ COL ], const int, const int, int, int, int );
void printMaze( char[][ COL ]);
int coordsAreEdge( int, int );
int validMove( char[][ COL ], int, int );

int main(void) { 
    int xStart = 0;
    int yStart = 0;
    int x = 0;
    int y = 0;
    
    char maze[ ROW ][ COL ];

    // initialize the Maze
    for ( size_t row = 0; row < ROW; row++ ) {
        for ( size_t col = 0; col < COL; col++ ) {
            maze[ row ][ col ] = '#';
        } // end for
    } // end for
    printMaze(maze);

    mazeGenerator( maze, &xStart, &yStart );
    printMaze(maze);

    x = xStart;
    y = yStart;

    mazeTraversal( maze, xStart, yStart, x, y, RIGHT );

    return 0;
    
} /* end main */

void mazeTraversal( char maze[][ COL ], const int xCoord, const int yCoord, int row, int col, int direction ) {
    static int flag = 0;
    maze[ row ][ col ] = 'X';
    printMaze( maze );

    if ( coordsAreEdge( row, col ) && row != xCoord && col != yCoord ) {
        printf_s( "%s", "You successfully exited the maze\n" );
        return;
    } // end if
    else if ( row == xCoord && col == yCoord && flag == 1 ) {
        printf_s( "%s", "You returned to the starting point\n" );
        return;
    } // end else if
    else {
        int move = 0;
        int count = 0;

        flag = 1;

        for ( move = direction, count = 0; count < 4; count++, move++, move %= 4 )

            switch( move ) {
                case DOWN: 
                    if ( validMove( maze, row + 1, col ) ) {
                        mazeTraversal( maze, xCoord, yCoord, row + 1, col, LEFT );
                    } // end if
                    break;
                case RIGHT: 
                    if ( validMove( maze, row, col + 1 ) ) {
                        mazeTraversal( maze, xCoord, yCoord, row, col + 1, DOWN );
                    } // end if
                    break;
                case UP: 
                    if ( validMove( maze, row - 1, col ) ) {
                        mazeTraversal( maze, xCoord, yCoord, row - 1, col, RIGHT );
                    } // END IF
                    break;
                case LEFT: 
                    if ( validMove( maze, row, col - 1 ) ) {
                        mazeTraversal( maze, xCoord, yCoord, row, col - 1, UP );
                    } // end if
                    break;
            } // end switch

    } // end else

} /* end function mazeTraversal */

int coordsAreEdge( int row, int col ) {
    if ( ( row == 0 || row == ( ROW - 1 ) ) && ( col >= 0 && col <= ( COL - 1 ) ) )
        return 1;
    else if ( ( col == 0 || col == ( COL - 1 ) ) && ( row >= 0 && row <= ( ROW - 1 ) ) )
        return 1;
    else  
        return 0;
} /* end function coordsAreEdge */

int validMove( char maze[][ COL ], int row, int col ) {
    return ( row >= 0 && row <= ( ROW - 1 ) && col >= 0 && col <= ( COL - 1 ) && maze[ row ][ col ] == '.' );
} /* end function validMove */

void mazeGenerator( char maze[][ COL ], int * xPos, int * yPos ) {
    int x = 0;
    int y = 0;
    int entry = 0;
    int exit = 0;
    int a = 0;

    srand( time( NULL ) ); 
    // Randomly create exit and entry points
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
    }
    else if ( entry == 1) {
      *xPos = 0;
      *yPos = 1 + rand() % ( COL - 2 );
      maze[ *xPos ][ *yPos ] = '.';
    }
    else if ( entry == 2 ) {
      *xPos = 1 + rand() % ( ROW - 2 );
      *yPos = ( COL - 1 );
      maze[ *xPos ][ *yPos ] = '.';
    }
    else if ( entry == 3 ) {
      *xPos = ( ROW - 1 );
      *yPos = 1 + rand() % ( COL - 2 );
      maze[ *xPos ][ *yPos ] = '.';
    }
    printMaze(maze);

    // exit
    if( exit == 0 ) {
      a = 1 + rand() % ( ROW - 2 );
      maze[ a ][ 0 ] = '.';
    }
    else if ( exit == 1 ) {
      a = 1 + rand() % ( COL - 2 );
      maze[ 0 ][ a ] = '.';
    }
    else if ( exit == 2 ) {
      a = 1 + rand() % ( ROW - 2);
      maze[ a ][ COL - 1 ] = '.';
    }
    else if ( exit == 3 ) {
      a = 1 + rand() % ( COL - 2 );
      maze[ ROW - 1 ][ a ] = '.';
    } 
    printMaze( maze );      

    for ( size_t count = 0; count < POSSIBLE_DOTS; count++ ) {
        x = 1 + rand() % ( ROW - 2 );
        y = 1 + rand() % ( COL - 2 );
        maze[ x ][ y ] = '.';
    } // end for 

} /* end function mazeGenerator */

void printMaze( char maze[][ COL ]) {
    // print the maze
    for ( size_t row = 0; row < ROW; row++ ) {
        for ( size_t col = 0; col < COL; col++ ) {
            printf_s( "%c%c", maze[ row ][ col ], col < ( COL - 1 ) ? ' ' : '\n' );
        } // end for
        puts("");
    } // end for 
    puts("Return to see another move");
    getchar();
} /* end function printMaze */