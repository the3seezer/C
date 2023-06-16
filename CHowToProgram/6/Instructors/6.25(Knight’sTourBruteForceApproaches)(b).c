/*
theBitRiddler
6/14/2023
10:30 AM
 (Knight’s Tour: Brute Force Approaches)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YES 1
#define NO 0

int validMove( int testRow, int testColumn, int [][ 8 ] );

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
    int moveTotal[ 65 ] = { 0 };

    int horizontal[ 8 ] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int vertical[ 8 ] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    srand( time( NULL ) );

    for ( size_t i = 0; i < 1000; i++ ) {

        for ( size_t row = 0; row < 8; row++ ) {
            for ( size_t column = 0; column < 8; column++ ) {
                board[ row ][ column ] = 0;
            } /* end for */
        } /* end for */

        moveNumber = 0;

        currentRow = rand() % 8;
        currentColumn = rand() % 8;
        board[ currentRow ][ currentColumn ] = ++moveNumber;
        done = NO;

        while ( !done ) {
            moveType = rand() % 8;

            testRow = currentRow + vertical[ moveType ];
            testColumn = currentColumn + horizontal[ moveType ];

            goodMove = validMove( testRow, testColumn, board );

            if ( goodMove ) {
                currentRow = testRow;
                currentColumn = testColumn;
                board[ currentRow ][ currentColumn ] = ++moveNumber;
            } /* end if */
            else {
                
                for ( size_t count = 0; count < 7 && !goodMove; count++ ) {
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
            }

        } /* end while */

        ++moveTotal[ moveNumber ];

    } /* end for */

    for ( size_t i = 0; i < 65; i++ ) {

        if ( moveTotal[ i ] ) {
            printf_s( "There were %d tours of %d moves.\n", moveTotal[ i ], i );
        }
    }
} /* end main */

int validMove( int testRow, int testColumn, int workBoard[][ 8 ] ) {

    if ( testRow >= 0 && testRow < 8 && testColumn >= 0 && testColumn < 8 ) {
        return workBoard[ testRow ][ testColumn ] != 0 ? NO : YES;
    } /* end if */
    else {
        return NO;
    } /* end else */

} /* end function validMove */