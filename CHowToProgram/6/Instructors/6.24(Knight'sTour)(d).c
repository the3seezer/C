/*
theBitRiddler
9:27 PM
6/5/2023
Write a version of the Knight’s Tour program which, when encountering a
tie between two or more squares, decides what square to choose by looking
ahead to those squares reachable from the “tied” squares. Your program
should move to the square for which the next move would arrive at a square
with the lowest accessibility number
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

void clearBoard( int workBoard[][ 8 ] );
void printBoard( int workBoard[][ 8 ] );
int validMove( int row, int column, int workBoard[][ 8 ] );
int postMove( int row, int column, int workAccess[][ 8 ], int workBoard[][ 8 ] );

int main( void ) {
    int board[ 8 ][ 8 ] = { 0 };
    int access[ 8 ][ 8 ] = {2, 3, 4, 4, 4, 4, 3, 2,
                            3, 4, 6, 6, 6, 6, 4, 3,
                            4, 6, 8, 8, 8, 8, 6, 4,
                            4, 6, 8, 8, 8, 8, 6, 4,
                            4, 6, 8, 8, 8, 8, 6, 4,
                            4, 6, 8, 8, 8, 8, 6, 4,
                            3, 4, 6, 6, 6, 6, 4, 3,
                            2, 3, 4, 4, 4, 4, 3, 2};
    int horizontal[ 8 ] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int vertical[ 8 ] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    int currentRow = 0;
    int currentColumn = 0;
    int moveNumber = 0;
    int testRow = 0;
    int testColumn = 0;
    int minRow = 0;
    int minColumn = 0;
    int accessNumber = 0;
    int postAccessNumber = 0;
    int thisPostAccessNumber = 0;
    int minAccess = 9;
    int done = FALSE;

    clearBoard( board );
    srand( time( NULL ) );
    currentRow = rand() % 8;
    currentColumn = rand() % 8;
    board[ currentRow ][ currentColumn ] = ++moveNumber;

    while ( !done ) {
        accessNumber = minAccess;

        for ( size_t moveType = 0; moveType < 8; moveType++ ) {
            testRow = currentRow + vertical[ moveType ];
            testColumn = currentColumn + horizontal[ moveType ];

            if ( validMove( testRow, testColumn, board ) ) {

                if ( access[ testRow ][ testColumn ] == accessNumber ) {
                    thisPostAccessNumber = postMove( testRow, testColumn,  access, board );

                    if ( thisPostAccessNumber < postAccessNumber ) {
                        minRow = testRow;
                        minColumn = testColumn;
                        accessNumber = access[ testRow ][ testColumn ];
                    } /* end if */

                } /* end if */

                if ( access[ testRow ][ testColumn ] < accessNumber ) {
                    postAccessNumber = postMove( testRow, testColumn,  access, board );

                    accessNumber = access[ testRow ][ testColumn ];
                    minRow = testRow;
                    minColumn = testColumn;

                } /* end if */
  
                --access[ testRow ][ testColumn ];

            } /* end if */

        } /* end for */

        if ( accessNumber == minAccess ) {
            done = TRUE;
        } /* end if */
        else {
            currentRow = minRow;
            currentColumn = minColumn;
            board[ currentRow ][ currentColumn ] = ++moveNumber;
        } /* end else if */

    } /* end while */

    printf_s( "The tour ended with %d moves.\n", moveNumber );

    if ( moveNumber == 64 ) {
        printf_s( "%s", "This was a full tour.\n\n" );
    } /* end if */
    else {
        printf_s( "%s", "This was not a full tour.\n\n" );
    } /* end if */

    printf_s( "%s", "The board for this test is:\n\n" );
    printBoard( board );

    return 0;

} /* end main */

int postMove( int row, int column, int workAccess[][ 8 ], int workBoard[][ 8 ] ) {
    int horizontalAccess[ 8 ] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int verticalAccess[ 8 ] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    int testMinorRow = 0;
    int testMinorColumn = 0;

    int minorNumber = 9;

    for (size_t moveType = 0; moveType < 8; moveType++ ) {
        testMinorRow = row + verticalAccess[ moveType ];
        testMinorColumn = column + horizontalAccess[ moveType ];

        if ( validMove( testMinorRow, testMinorColumn, workBoard ) ) {

            if ( workAccess[ testMinorRow ][ testMinorColumn ] < minorNumber ) {
                minorNumber = workAccess[ testMinorRow ][ testMinorColumn ];
            } /* end if */

        } /* end if */

    } /* end for */

    return minorNumber;

} /* end function postMove */

void clearBoard( int workBoard[][ 8 ] ) {
    for ( size_t i = 0; i < 8; i++ ) {
        for ( size_t j = 0; j < 8; j++ ) {
            workBoard[ i ][ j ] = 0;
        } /* end for */
    } /* end for */
} /* end function clearBoard */

int validMove( int row, int column, int workBoard[][ 8 ] ) {

    return ( row >= 0 && row <= 7 && column >= 0 && column <= 7 && workBoard[ row ][ column ] == 0 );

} /* end function validMove */

void printBoard( int workBoard[][ 8 ] ) {
    printf_s( "%s", "   0  1  2  3  4  5  6  7 \n" );

    for ( size_t i = 0; i < 8; i++ ) {
        printf_s( "%zu", i );

        for ( size_t j = 0; j < 8; j++ ) {
            printf_s( "%3d", workBoard[ i ][ j ] );
        } /* end for */
        printf_s( "%s", "\n" );

    } /* end for */
    printf_s( "%s", "\n" );
}