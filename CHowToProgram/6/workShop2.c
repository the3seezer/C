/*
theBitRiddler
6/14/2023
2:47 PM
 (Eight Queens) 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YES 1
#define NO 0

int validMove( int, int, int [][ 8 ] );
void printBoard( int workBoard[][ 8 ] );
void clearBoard( int [][ 8 ] );
int directionMoves( size_t direction, int moveNumber, int goodMove, int currentRow, int currentColumn, int workBoard[][ 8 ] );
int queenMoves(int moveNumber, int currentRow, int currentColumn, int workBoard[][ 8 ]);

int main( void ) {
    static int currentRow = 0;
    static int currentColumn = 0;
    static int moveNumber = 0;
    int board[ 8 ][ 8 ] = { 0 };

    srand( time( NULL ) );
    currentRow = rand() % 8;
    currentColumn = rand() % 8;
    clearBoard( board );
    board[ currentRow ][ currentColumn ] = ++moveNumber;

    moveNumber = queenMoves( moveNumber, currentRow, currentColumn, board);   

    printf_s( "The tour ended with %d moves.\n", moveNumber );

    if ( moveNumber == 64 ) {
        printf_s( "%s", "This is a complete tour.\n" );
    }
    else {
        printf_s( "%s", "This is not a complete tour.\n" );
    }

    printf_s( "%s", "The board for this test is:\n" );
    printBoard( board );

    return 0;

} /* end main */

int queenMoves( int moveNumber, int currentRow, int currentColumn, int workBoard[][ 8 ]) {
    static int testRow = 0;
    static int testColumn = 0;
    static int goodMove = 0;
    int done = NO;

    testRow = currentRow;
    testColumn = currentColumn;
    /* get the direction */
    static size_t direction = 0;

    moveNumber = directionMoves( direction + 1, moveNumber, goodMove, testRow, testColumn, workBoard );

    if ( !goodMove ) {
        done = YES;
    } /* end if */


    if ( done == YES ) {
        return moveNumber;
    } /* end if */
    else {
        queenMoves( moveNumber, currentRow, currentColumn, workBoard);
    } /* end else */

} /* end function queenMoves */

int directionMoves( size_t direction, int moveNumber, int goodMove, int currentRow, int currentColumn, int workBoard[][ 8 ] ) {
    int testRow = 0;
    int testColumn = 0;

    testRow = currentRow;
    testColumn = currentColumn;

    /* get the distance */
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

        goodMove = validMove( testRow, testColumn, workBoard );

        if ( goodMove ) {
            currentRow = testRow;
            currentColumn = testColumn;
            workBoard[ currentRow ][ currentColumn ] = ++moveNumber;
            break;
        } /* end if */

    } /* end for */

    if ( direction == 8 || goodMove ) {
        return moveNumber;
    } /* end if */
    else {
        directionMoves( direction + 1, moveNumber, goodMove, currentRow, currentColumn, workBoard );
    } /* end else */

} /* end function directionMoves */

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

int validMove( int row, int column, int workBoard[][ 8 ] ) {

    return ( row >= 0 && row <= 7 && column >= 0 && column <= 7 && workBoard[ row ][ column ] == 0 );

} /* end function validMove */

void clearBoard( int workBoard[][ 8 ] ) {
    for ( size_t i = 0; i < 8; i++ ) {
        for ( size_t j = 0; j < 8; j++ ) {
            workBoard[ i ][ j ] = 0;
        } /* end for */
    } /* end for */
} /* end function clearBoard */