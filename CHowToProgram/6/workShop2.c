/* 
theBitRiddler
6/30/2023
8:38 PM
Eight Queens 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YES 1
#define NO 0

int validMove( int, int, int [][ 8 ] );
void printBoard( int workBoard[][ 8 ] );
void clearBoard( int [][ 8 ] );
int queensMoves(int current_row, int current_column, int workBoard[][ 8 ], int move_number);

int main( void ) {
    int currentRow = 0;
    int currentColumn = 0;
    int moveNumber = 0;
    
    int board[ 8 ][ 8 ] = { 0 };

    srand( time( NULL ) );
    currentRow = rand() % 8;
    currentColumn = rand() % 8;
    clearBoard( board );
    board[ currentRow ][ currentColumn ] = ++moveNumber;

    queensMoves( currentRow, currentColumn, board, moveNumber);

    printf_s( "The tour ended with %d moves.\n", moveNumber );

    if ( moveNumber == 64 ) {
        printf_s( "%s", "This is a complete tour.\n" );
    }
    else {
        printf_s( "%s", "This is not a complete tour.\n" );
    }

    printf_s( "%s", "The board for this test is:\n" );
    printBoard( board );
    
} /* end main*/

int queensMoves(int current_row, int current_column, int workBoard[][ 8 ], int move_number) {
    int done = NO;
    int goodMove = 0;

    if ( !done ) {
        int testRow = current_row;
        int testColumn = current_column;

        /* get the direction */
        for ( size_t direction = 0; direction < 8; direction++ ) {
            /* get the distance */
            for ( size_t distance = 1; distance <= 8; distance++ ) {
                switch( direction ) {
                    /* test right */
                    case 0: 
                        testColumn = current_column + distance;
                        break;

                    /* test down right */
                    case 1: 
                        testRow = current_row + distance;
                        testColumn = current_column + distance;
                        break; 

                    /* test down */
                    case 2: 
                        testRow = current_row + distance;
                        break;

                    /* test down left */
                    case 3: 
                        testRow = current_row + distance;
                        testColumn = current_column - distance;
                        break;

                    /* test left */
                    case 4: 
                        testColumn = current_column - distance;
                        break;

                    /* test up left */
                    case 5: 
                        testRow = current_row - distance;
                        testColumn = current_column - distance;
                        break; 

                    /* test up */
                    case 6: 
                        testRow = current_row - distance;
                        break;

                    /* test up right */
                    case 7: 
                        testRow = current_row - distance;
                        testColumn = current_column + distance;
                        break;
                } /* end switch */

                goodMove = validMove( testRow, testColumn, workBoard );

                if ( goodMove ) {
                    queensMoves( testRow, testColumn, workBoard, move_number + 1);
                    break;
                } /* end if */

            } /* end for */

            if ( goodMove ) {
                break;
            } /* end if */

        } /* end for */

        if ( !goodMove ) {
            done = YES;
        }

    } /* end if */

    return -1;
} /* end function queensMoves */

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