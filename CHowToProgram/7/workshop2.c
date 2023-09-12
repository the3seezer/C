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
void mazeTraverse( int currentRow, int currentColumn, char [][ SIZE ]);
int validMove( int, int, char[][ SIZE ]);

int main(void) {
    char maze[ SIZE ][ SIZE ] = { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
                                  '#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#',
                                  '.', '.', '#', '#', '#', '.', '.', '#', '#', '#', '.', '#',
                                  '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '#', '#',
                                  '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.',
                                  '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#',
                                  '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                                  '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                                  '#', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#',
                                  '#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#',
                                  '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#',
                                  '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' };
    display( maze );
    int currentRow = 4;
    int currentColumn = 11;
    maze[ currentRow][ currentColumn] = 'x';
    
    mazeTraverse( currentRow, currentColumn, maze );

} /* end main */

void mazeTraverse( int currentRow, int currentColumn, char mazeWork[][ SIZE ] ) {

    int horizontal[ DIR ] = { 1, 0, -1, 0 }; // east, north, west and south
    int vertical[ DIR ] = { 0, -1, 0, 1 }; // east, north, west and south
    int validDir[ DIR ] = { 0 }; // record valid directions
    int validRow[ DIR ] = { -1, -1, -1, -1 }; // record valid direction for row
    int validCol[ DIR ] = { -1, -1, -1, -1 }; // record valid direction for column
    int counter = 0; // counter for valid directions

    for ( int i = 0; i < 4; i++ ) { // i for east, north, west or south, respectively
        if ( validMove( currentRow + vertical[ i ], currentColumn + horizontal[ i ], mazeWork ) ) {
            validDir[ counter ] = i;
            if ( i == 0 || i == 2 )   
                validCol[ counter ] = i;
            if ( i == 1 || i == 3 )
                validRow[ counter ] = i;
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
        mazeWork[ currentRow][ currentColumn] = 'x';
        mazeTraverse( currentRow, currentColumn, mazeWork);
    } // end if
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