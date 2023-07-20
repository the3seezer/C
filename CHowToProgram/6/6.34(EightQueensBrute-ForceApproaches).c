#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YES 1
#define NO 0

int validMove( int, int, int [][ 8 ] );
int validSquare( int, int, int[][ 8 ] );
void printBoard( int workBoard[][ 8 ] );
void clearBoard( int [][ 8 ] );
int queenMoves(int moveNumber, int currentRow, int currentColumn, int workBoard[][ 8 ]);

int main( void ) {
    int board[ 8 ][ 8 ] = { 0 };
    srand( time( NULL) );
    int moveNumber = 0;
    int currentRow = rand() % 8;
    int currentColumn = rand() % 8;

    clearBoard(board);
    board[ currentRow ][ currentColumn ] = ++moveNumber;

    moveNumber = queenMoves( moveNumber, currentRow, currentColumn, board); 

    printBoard(board);
    printf_s( "\nThe last queen was the %dth\n", moveNumber );
} /* end main */

int queenMoves(int moveNumber, int currentRow, int currentColumn, int board[][ 8 ]) {
    int moved = NO;
    int done = NO;
    int goodSquare = 0;

    int testRow = rand() % 8;
    int testColumn = rand() % 8;

    goodSquare = validSquare( testRow, testColumn, board);

    if( goodSquare ) {
        currentRow = testRow;
        currentColumn = testColumn;
        board[ currentRow ][currentColumn ] = ++moveNumber;
        moved = YES;
    }
    else {
        for ( int count = 0; count < 7 && !goodSquare; count++ ) {
            testRow = ++testRow % 8;

            goodSquare = validSquare( testRow, testColumn, board);

            if( goodSquare ) {
                currentRow = testRow;
                currentColumn = testColumn;
                board[ currentRow ][currentColumn ] = ++moveNumber;
                moved = YES;
            } /* end if */
            else {
                for ( int count = 0; count < 7 && !goodSquare; count++ ) {
                    testColumn = ++testColumn % 8;

                    if( goodSquare ) {
                        currentRow = testRow;
                        currentColumn = testColumn;
                        board[ currentRow ][currentColumn ] = ++moveNumber;
                        moved = YES;
                    } /* end if */

                } /* end for */
            } /* end else */
        } /* end for */    
    } /* end else */

    if ( !moved ) {
        done = YES;
    } /* end if */

    if ( done ) {
        return moveNumber;
    } /* end if */
    else {
        queenMoves( moveNumber, currentRow, currentColumn, board);
    } /* end else */
}

int validSquare( int currentRow, int currentColumn, int board[][ 8 ]) {
    int badSquare = 0;

    for ( int direction = 0; direction < 8; direction++ ) {
            switch( direction ) {
                case 0:
                    for ( size_t distance = 0; currentColumn + distance <= 7; distance++ ) {
                        if ( !( validMove(currentRow, currentColumn + distance, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 1: 
                    for ( size_t distance = 0; currentRow + distance <= 7 && currentColumn + distance <= 7; distance++ ) {
                        if ( !( validMove(currentRow + distance, currentColumn + distance, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 2: 
                    for ( size_t distance = 0; currentRow + distance <= 7; distance++ ) {
                        if ( !( validMove( currentRow + distance, currentColumn, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 3: 
                    for ( int distance = 0; currentRow + distance <= 7 && currentColumn - distance >= 0; distance++ ) {
                        if ( !( validMove(currentRow + distance, currentColumn - distance, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 4: 
                    for ( int distance = 0; currentColumn - distance >= 0; distance++ ) {
                        if ( !( validMove(currentRow, currentColumn - distance, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 5: 
                    for ( int distance = 0; currentRow - distance >= 0 && currentColumn - distance >= 0; distance++ ) {
                        if ( !( validMove(currentRow - distance, currentColumn - distance, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 6: 
                    for ( int distance = 0; currentRow - distance >= 0; distance++ ) {
                        if ( !( validMove( currentRow - distance, currentColumn, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 7: 
                    for ( int distance = 0; currentRow - distance >= 0 && currentColumn + distance <= 7; distance++ ) {
                        if ( !( validMove( currentRow - distance, currentColumn + distance, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
            } /* end switch for direction */
        } /* end for of direction */

    if ( !badSquare )
        return 1;
    else 
    	return 0;

} /* end function validSquare */

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