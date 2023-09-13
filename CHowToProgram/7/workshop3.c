/*
theBitRiddler
9/7/2023
5:18 PM
 (Maze Traversal)
*/
#include <stdio.h>

#define SIZE 12
#define DIR 4 // direction

void display( char [][ SIZE ]);
void mazeTraverse( int currentRow, int currentColumn, char [][ SIZE ], char [][ SIZE ]);
int validMove( int, int, char[][ SIZE ]);
int entry( int, int, char[][ SIZE ], char[][ SIZE ] ); // Find entry and Exit
void copy( char[][ SIZE ], char [][ SIZE ]);

int main(void) {
    char copy[ SIZE ][ SIZE ] = {{0}};
    char maze[ SIZE ][ SIZE ] = { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
                                  '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',
                                  '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#',
                                  '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#',
                                  '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.',
                                  '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                                  '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                                  '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                                  '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#',
                                  '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#',
                                  '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#',
                                  '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' };
    display( maze );
    int currentRow = 2;
    int currentColumn = 0;
    entry(currentRow, currentColumn, maze, copy );
    
    mazeTraverse( currentRow, currentColumn, maze, copy );

} /* end main */

void copy( char copy[][ SIZE ], char maze[][ SIZE ] ) {
    for ( size_t row = 0; row < SIZE; row++ )
        for ( size_t column = 0; column < SIZE; column++ )
        copy [row][column] = maze[row][column];
} /* end function copy */

int entry( int currentRow, int currentcolumn, char maze[][ SIZE ], char copyMaze[][ SIZE ] ) {
    copy( copyMaze, maze);
    // get start 
    copyMaze[ currentRow ][ currentcolumn ] = 'A'; 
} /* end function exit */

void mazeTraverse( int currentRow, int currentColumn, char mazeWork[][ SIZE ], char copyWork[][ SIZE ] ) {
    if ( currentRow == 0 || currentRow == 11 || currentColumn == 0 || currentColumn == 11 && copyWork[ currentRow ][ currentColumn] != 'A') {
        puts("Success");
    } // end if
    mazeWork[ currentRow][ currentColumn] = 'x';
    int horizontal[ DIR ] = { 1, 0, -1, 0 }; // east, north, west and south
    int vertical[ DIR ] = { 0, -1, 0, 1 }; // east, north, west and south
    int validDir[ DIR ] = { 0 }; // record valid directions
    int counter = 0; // counter for valid directions

    for ( int i = 0; i < 4; i++ ) { // i for east, north, west or south, respectively
        if ( validMove( currentRow + vertical[ i ], currentColumn + horizontal[ i ], mazeWork ) ) {
            validDir[ counter ] = i;
            counter++;
        } // end if
    } // end for

    if ( !counter ) {
        display( mazeWork );
        return ;
    } // end if
    else if ( counter == 1 ) {
        counter--;
        if ( validDir[ counter ] == 0 || validDir[ counter ] == 2 ) {
            currentColumn += horizontal[ validDir[ counter ] ];
        } // end if
        if ( validDir[ counter ] == 1 || validDir[ counter ] == 3 ) {
            currentRow += vertical[ validDir[ counter ] ];
        } // end if
        mazeTraverse( currentRow, currentColumn, mazeWork, copyWork);
    } // end if
    else if ( counter > 1 ) {
        for ( int i = 0; i < counter; i++ ) {
            mazeTraverse( currentRow + vertical[ validDir[ i ] ], currentColumn + horizontal[ validDir[ i ] ], mazeWork, copyWork );
        } /* end for */
    } /* end else if */
} /* end function mazeTraverse */

int validMove( int row, int column, char mazeWork[][ SIZE ]) {
    return ( row >= 0 && row <= 11 && column >= 0 && column <= 11 && mazeWork[ row ][ column ] == '.' );
} /* end function validMove */

void display( char mazeWork[][ SIZE ]) {
    for ( size_t row = 0; row < SIZE; row++ ) {
        for ( size_t column = 0; column < SIZE; column++ )
            printf_s( "%c%c", mazeWork[ row ][ column ], column == 11 ? '\n' : ' ' );
    } // end for
    puts("\n");
} /* end function display */