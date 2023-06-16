/*
theBitRiddler
6/15/2023
2:33 PM
 (Eight Queens)
 : It’s possible to assign a numeric value to each square of the chessboard indicating how many squares of an empty chessboard are “eliminated” once a
queen is placed in that square. For example, each of the four corners would be assigned the value 22, as illustrated in the following diagram:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YES 1
#define NO 0

void clearBoard( int [][ 8 ] );
void printBoard( int [][ 8 ] );
int validMove( int, int, int [][ 8 ] );
int postMove( int row, int column, int workAccess[][ 8 ], int workBoard[][ 8 ] );

int main( void ) {
    int board[ 8 ][ 8 ] = { 0 };
    int access[ 8 ][ 8 ] = { 22, 23, 24, 24, 24, 24, 23, 22,
                             23, 24, 26, 26, 26, 26, 24, 23,
                             24, 26, 28, 28, 28, 28, 26, 24,
                             24, 26, 28, 28, 28, 28, 26, 24,
                             24, 26, 28, 28, 28, 28, 26, 24,
                             24, 26, 28, 28, 28, 28, 26, 24,
                             23, 24, 26, 26, 26, 26, 24, 23,
                             22, 23, 24, 24, 24, 24, 23, 22 };
    int currentRow = 0;
    int currentColumn = 0;
    int testRow = 0;
    int testColumn = 0;
    int minRow = 0;
    int minColumn = 0;
    int moveNumber = 0; 
    int accessNumber = 0;
    int postAccessNumber = 0;
    int thisPostAccessNumber = 0;
    int minAccess = 29;
    int done = NO;

    srand( time( NULL ) );
    currentRow = rand() % 8;
    currentColumn = rand() % 8;
    clearBoard( board );

    board[ currentRow ][ currentColumn ] = ++moveNumber;

    while ( !done ) {
        accessNumber = minAccess;
        testRow = currentRow;
        testColumn = currentColumn;

        for ( size_t direction = 0; direction < 8; direction++ ) {

            for ( size_t distance = 1; distance <= 8; distance++ ) {
                switch( direction ) {
                    /* test right */
                    case 0: 
                        testColumn = currentColumn + distance;
                        break;

                    /* test down right */
                    case 1: 
                        testRow = currentRow + distance;
                        testColumn = currentColumn + distance;
                        break; 

                    /* test down */
                    case 2: 
                        testRow = currentRow + distance;
                        break;

                    /* test down left */
                    case 3: 
                        testRow = currentRow + distance;
                        testColumn = currentColumn - distance;
                        break;

                    /* test left */
                    case 4: 
                        testColumn = currentColumn - distance;
                        break;

                    /* test up left */
                    case 5: 
                        testRow = currentRow - distance;
                        testColumn = currentColumn - distance;
                        break; 

                    /* test up */
                    case 6: 
                        testRow = currentRow - distance;
                        break;

                    /* test up right */
                    case 7: 
                        testRow = currentRow - distance;
                        testColumn = currentColumn + distance;
                        break;
                } /* end switch */

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

        } /* end for */

        if ( accessNumber == minAccess ) {
            done = YES;
        } /* end if */
        else {
            currentRow = minRow;
            currentColumn = minColumn;
            board[ currentRow ][ currentColumn ] = ++moveNumber;
        } /* end else */

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
    int testMinorRow = 0;
    int testMinorColumn = 0;
    int minorNumber = 29;

    for (size_t direction = 0; direction < 8; direction++ ) {

        for ( size_t distance = 1; distance <= 8; distance++ ) {
            switch( direction ) {
                    /* test right */
                    case 0: 
                        testMinorColumn = column + distance;
                        break;

                    /* test down right */
                    case 1: 
                        testMinorRow = row + distance;
                        testMinorColumn = column + distance;
                        break; 

                    /* test down */
                    case 2: 
                        testMinorRow = row + distance;
                        break;

                    /* test down left */
                    case 3: 
                        testMinorRow = row + distance;
                        testMinorColumn = column - distance;
                        break;

                    /* test left */
                    case 4: 
                        testMinorColumn = column - distance;
                        break;

                    /* test up left */
                    case 5: 
                        testMinorRow = row - distance;
                        testMinorColumn = column - distance;
                        break; 

                    /* test up */
                    case 6: 
                        testMinorRow = row - distance;
                        break;

                    /* test up right */
                    case 7: 
                        testMinorRow = row - distance;
                        testMinorColumn = column + distance;
                        break;
                } /* end switch */

            if ( validMove( testMinorRow, testMinorColumn, workBoard ) ) {

                if ( workAccess[ testMinorRow ][ testMinorColumn ] < minorNumber ) {
                    minorNumber = workAccess[ testMinorRow ][ testMinorColumn ];
                } /* end if */

            } /* end if */

        } /* end for */

    } /* end for */

    return minorNumber;

} /* end function postMove */

int validMove( int row, int column, int workBoard[][ 8 ] ) {

    return ( row >= 0 && row <= 7 && column >= 0 && column <= 7 && workBoard[ row ][ column ] == 0 );

} /* end function validMove */

void printBoard( int workBoard[][ 8 ] ) {
    printf_s( "%s", "    0   1   2   3   4   5   6   7\n" );
    for ( size_t i = 0; i < 8; i++ ) {
        printf_s( "%zu", i );
        for ( size_t j = 0; j < 8; j++ ) {
            printf_s( "%4d", workBoard[ i ][ j ] );
        } /* end for */
        printf_s( "%s", "\n" );
    } /* end for */
} /* end function printBoard */

void clearBoard( int workBoard[][ 8 ] ) {
    for ( size_t i = 0; i < 8; i++ ) {
        for ( size_t j = 0; j < 8; j++ ) {
            workBoard[ i ][ j ] = 0;
        } /* end for */
    } /* end for */
} /* end function clearBoard */