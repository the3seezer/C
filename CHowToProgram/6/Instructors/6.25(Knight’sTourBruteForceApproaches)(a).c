/* 
theBitRiddler
6/13/2023
12:47 PM
 (Knight’s Tour: Brute Force Approaches)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YES 1
#define NO 0

int validMove( int row, int column, int workBoard[][ 8 ] );
void printBoard( int workBoard[][ 8 ] );

int main( void ) {
    int currentRow = 0;
    int currentColumn = 0;
    int testRow = 0;
    int testColumn = 0;
    int moveType = 0;
    int moveNumber = 0;
    int goodMove = 0;
    int done = NO;
    int board[ 8 ][ 8 ] = { 0 };
    int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    
    srand( time( NULL ) );
    currentRow = rand() % 8;
    currentColumn = rand() % 8;
    while ( !done ) {
        moveType = rand() % 8;
        testRow = currentRow + vertical[ moveType ];
        testColumn = currentColumn + horizontal[ moveType ];

        goodMove = validMove( testRow, testColumn, board );

        if ( goodMove ) {
            currentRow = testRow;
            currentColumn = testColumn;
            board[ currentRow ][ currentColumn ] = ++moveNumber;
        }
        else {

            for ( int count = 0; count < 7 && !goodMove; count++ ) {
                moveType = ++moveType % 8;
                testRow = currentRow + vertical[ moveType ];
                testColumn = currentColumn + horizontal[ moveType ];

                goodMove = validMove( testRow, testColumn, board );

                if ( goodMove ) {
                    currentRow = testRow;
                    currentColumn = testColumn;
                    board[ currentRow ][ currentColumn ] = ++moveNumber;
                } /* end if */

            } /* end for */

            if ( !goodMove ) {
                done = YES;
            } /* end if */

        } /* end else */

        if ( moveNumber == 64 ) {
            done = YES;
        } /* end if */

    } /* end while */

    printf_s( "The Tour end with %d moves.\n", moveNumber );

    if ( moveNumber == 64 ) {
        printf_s( "%s", "This is a complete tour.\n" );
    } /* end if */
    else {
        printf_s( "%s", "This is not a complete tour.\n" );
    } /* end else */

    printf_s( "%s", "The board for this random test was:\n\n" );
    printBoard( board );

    return 0;

} /* end main */

int validMove( int row, int column, int workBoard[][ 8 ] ) {
    
    return ( row >= 0 && row <= 7 && column >= 0 && column <= 7 && workBoard[ row ][ column ] == 0 );

} /* end function validMove */

void printBoard( int workBoard[][ 8 ] ) {
    printf_s( "%s", "    1   2   3   4   5  6  7   8\n" );

    for ( size_t row = 0; row < 8; row++ ) {
        printf_s( "%d", row );
        for ( size_t column = 0; column < 8; column++ ) {
            printf_s( "%4d", workBoard[ row ][ column ] );
        } /* end for */
        printf_s( "%s", "\n" );
    } /* end for */
    printf_s( "%s", "\n" );
} /* end function printBoard */