#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YES 1
#define NO 0

int validMove( int, int, int [][ 8 ] );
int validSquare( int, int, int[][ 8 ] );
void printBoard( int workBoard[][ 8 ] );
void clearBoard( int [][ 8 ] );

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
    clearBoard(board);
    int moveNumber = 0;
    int currentRow = 0;
    int currentColumn = 0;
    int minRow = 0;
    int minColumn = 0;
    int accessNumber = 0;
    int minAccess = 29;
    int done = NO;

    board[ currentRow ][ currentColumn ] = ++moveNumber;

        for ( currentRow = 0; currentRow < 8; currentRow++ )
            for ( currentColumn = 0; currentColumn < 8; currentColumn++ )
                if( validSquare(currentRow, currentColumn, board) ) {
                    board[ currentRow ][currentColumn ] = ++moveNumber;
                }
    
    printBoard(board);
    printf_s( "\nThe last queen was the %dth\n", moveNumber );
} /* end main */

int validSquare( int testRow, int testColumn, int board[][ 8 ]) {
    int badSquare = 0;

    for ( int direction = 0; direction < 8; direction++ ) {
            switch( direction ) {
                case 0:
                    for ( size_t distance = 0; testColumn + distance <= 7; distance++ ) {
                        if ( !( validMove(testRow, testColumn + distance, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 1: 
                    for ( size_t distance = 0; testRow + distance <= 7 && testColumn + distance <= 7; distance++ ) {
                        if ( !( validMove(testRow + distance, testColumn + distance, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 2: 
                    for ( size_t distance = 0; testRow + distance <= 7; distance++ ) {
                        if ( !( validMove( testRow + distance, testColumn, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 3: 
                    for ( int distance = 0; testRow + distance <= 7 && testColumn - distance >= 0; distance++ ) {
                        if ( !( validMove(testRow + distance, testColumn - distance, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 4: 
                    for ( int distance = 0; testColumn - distance >= 0; distance++ ) {
                        if ( !( validMove(testRow, testColumn - distance, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 5: 
                    for ( int distance = 0; testRow - distance >= 0 && testColumn - distance >= 0; distance++ ) {
                        if ( !( validMove(testRow - distance, testColumn - distance, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 6: 
                    for ( int distance = 0; testRow - distance >= 0; distance++ ) {
                        if ( !( validMove( testRow - distance, testColumn, board ) ) ) {
                            badSquare = 1;
                        }
                    }
                    break;
                case 7: 
                    for ( int distance = 0; testRow - distance >= 0 && testColumn + distance <= 7; distance++ ) {
                        if ( !( validMove( testRow - distance, testColumn + distance, board ) ) ) {
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
