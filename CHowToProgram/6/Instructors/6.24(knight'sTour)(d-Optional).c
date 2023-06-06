/* 
theBitRiddler
6/4/2023
10:18 PM
Knight's Tour Modified
 (Optional: Modify the program to run 64 tours,
one from each square of the chessboard. How many full tours did you get?)
*/
#include <stdio.h>

#define TRUE 1
#define FALSE 0

void printBoard( int workBoard[][ 8 ] );
void clearBoard( int workBoard[][ 8 ] );
int validMove( int row, int column, int workBoard[][ 8 ] );
int postMove( int row, int column, int workAccess[][ 8 ], int workBoard[][ 8 ] );
void tour( int row, int column, int moveTour );

int main( void ) {
    int move = 0;

    for ( size_t i = 0; i < 8; i++ ) {

        for ( size_t j = 0; j < 8; j++ ) {
            tour( i, j, ++move );
        } /* end for */

    } /* end for */

    return 0;
} /* end main */

void tour( int row, int column, int moveTour ) {
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

    currentRow = row;
    currentColumn = column;
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

    printf_s( "The %dth tour ended with %d moves.\n", moveTour, moveNumber );

    
    if ( moveNumber == 64 ) {
        printf_s( "%s", "This is a full tour.\n" );
    } /* end if */
    else {
        printf_s( "%s", "This is not a full tour.\n\n" );
    } /* end if */

    printf_s( "%s", "The board for this test is:\n\n" );
    printBoard( board );
    
} /* end function tour */

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

int validMove( int row, int column, int workBoard[][ 8 ] ) {

    return ( row >= 0 && row <= 7 && column >= 0 && column <= 7 && workBoard[ row ][ column] == 0 );

} /* end function validMove */

void clearBoard( int workBoard[][ 8 ] ) {
     
     for ( size_t i = 0; i < 8; i++ ) {
        for ( size_t j = 0; j < 8; j++ ) {
            workBoard[ i ][ j ] = 0;
        } /* end for */

     } /* end for */

} /* end function clearBoard */

void printBoard( int workBoard[][ 8 ] ) {
    printf_s( "%s", "   0  1  2  3  4  5  6  7  \n" );
    for ( size_t i = 0; i < 8; i++ ) {
        printf_s( "%zu", i );

        for ( size_t j = 0; j < 8; j++ ) {
            printf_s( "%3d", workBoard[ i ][ j ] );
        }
        printf_s( "%s", "\n" );

    }
    printf_s( "%s", "\n\n\n" );

} /* end function printBoard */