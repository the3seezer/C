/* 
theBitRiddler
6/15/2023
5:33 PM
Eight Queens Brute-Force Approaches
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YES 1
#define NO 0

void clearBoard( int [][ 8 ] );
void printBoard( int workBoard[][ 8 ] );
int validMove( int, int, int [][ 8 ] );

int main( void ) {
    int board[ 8 ][ 8 ] = { 0 };
    int currentRow = 0;
    int currentColumn = 0;
    int testRow = 0;
    int testColumn = 0;
    int direction = 0;
    int moveNumber = 0;
    int done = NO;

    srand( time( NULL ) );

    currentRow = rand() % 8;
    currentColumn = rand() % 8;
    clearBoard( board );
    board[ currentRow ][ currentColumn ] = ++moveNumber;

    while ( !done ) {
        testRow = currentRow;
        testColumn = currentColumn;

        direction = rand() % 8;

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

                int goodMove = validMove( testRow, testColumn, board );

                if ( goodMove ) {
                    currentRow = testRow;
                    currentColumn = testColumn;
                    board[ currentRow ][ currentColumn ] = ++moveNumber;
                } /* end if */
                else {

                    for ( size_t count = 0; count < 7 && !goodMove; count++) {
                        direction = ++direction % 8;

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

                            int goodMove = validMove( testRow, testColumn, board );

                            if ( goodMove ) {
                                currentRow = testRow;
                                currentColumn = testColumn;
                                board[ currentRow ][ currentColumn ] = ++moveNumber;
                            } /* end if */

                        } /* end for */

                    } /* end for */

                    if ( !goodMove ) {
                        done = YES;
                    } /* end if */

                } /* end else */

        } /* end for */

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

} /* end funtion validMove */

void printBoard( int workBoard[][ 8 ] ) {
    printf_s( "%s", "    0   1   2   3   4   5   6   7\n" );
    for ( size_t i = 0; i < 8; i++ ) {
        printf_s( "%zu", i );
        for ( size_t j = 0; j < 8; j++ ) {
            printf_s( "%4d", workBoard[ i ][ j ] );
        } /* end for */
        printf_s( "%s", "\n" );
    } /* end for */
    printf_s( "%s", "\n" );
} /* end function printBoard */

void clearBoard( int workBoard[][ 8 ] ) {
    for ( size_t i = 0; i < 8; i++ ) {
        for (size_t j = 0; j < 8; j++ ) {
            workBoard[ i ][ j ] = 0;
        } /* end for */
    } /* end for */
} /* end function void */