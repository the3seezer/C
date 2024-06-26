/*
theBitRiddler
7/22/2023
2:17 PM
Eight Queens
*/
#include <stdio.h>

#define YES 1
#define NO 0
#define SIZE 65

int validMove( int, int, int [][ 8 ] );
int validSquare( int, int, int[][ 8 ] );
void accessNegate( int, int, int [][ 8 ]);
void printBoard( int workBoard[][ 8 ] );
void clearBoard( int [][ 8 ] );
int queen( int, int, int );

int main( void ) {
    int route = 0;
    int arrayRoute[ SIZE ] = { 0 };

    for ( int row = 0; row < 8; row++ ) {
        for ( int column = 0; column < 8; column++ ) {
            if( queen(row, column, ++route ) ) {
                ++arrayRoute[ route ];
            } /* end if */
        } /* end for */
    } /* end for */

    printf_s( "%s", "Complete tours are: ");
    for ( int route = 0; route < SIZE; route++ ) {
        if ( arrayRoute[ route ])
            printf_s( "%3d", route );
    } 
    
} /* end main */

int queen( int row, int column, int route ) {
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
    int currentRow = row; 
    int currentColumn = column;
    int minRow = 0;
    int minColumn = 0;
    int accessNumber = 0;
    int minAccess = 29;
    int done = NO;

    board[ currentRow ][ currentColumn ] = ++moveNumber;
    
    accessNegate(currentRow, currentColumn, access );

    while ( !done ) {
        accessNumber = minAccess;

        for ( int testRow = 0; testRow < 8; testRow++ )
            for ( int testColumn = 0; testColumn < 8; testColumn++ )
                if( validSquare( testRow, testColumn, board) ) {
                    if ( access[ testRow ][ testColumn ] < accessNumber ) {
                        accessNumber = access[ testRow ][ testColumn ];
                        minRow = testRow;
                        minColumn = testColumn;
                    } /* end if */
                }

        if ( accessNumber == minAccess ) { // accessNumber == minAccess moveNumber == 8
            done = YES;
        } /* end if */
        else {
            currentRow = minRow;
            currentColumn = minColumn;
            board[ currentRow ][ currentColumn ] = ++moveNumber;
            accessNegate(currentRow, currentColumn, access );
        } /* end else */

    } /* end while */
    printBoard(board);
    printf_s( "The last queen was the %dth on route %d\n\n", moveNumber, route );
    if ( moveNumber == 8 ) 
        return 1;
    else  
        return 0;

} /* end function queen */

void accessNegate( int accessRow, int accessColumn, int accessBoard[][ 8 ]) {
    
    for ( int direction = 0; direction < 8; direction++ ) {
        switch( direction ) {
            case 0:
                for ( size_t distance = 0; accessColumn + distance <= 7; distance++ ) {
                    --accessBoard[ accessRow ][ accessColumn + distance ];
                }
                break;
            case 1: 
                for ( size_t distance = 0; accessRow + distance <= 7 && accessColumn + distance <= 7; distance++ ) {
                    --accessBoard[ accessRow + distance ][ accessColumn + distance ];
                }
                break;
            case 2: 
                for ( size_t distance = 0; accessRow + distance <= 7; distance++ ) {
                    --accessBoard[ accessRow + distance ][ accessColumn ];
                }
                break;
            case 3: 
                for ( int distance = 0; accessRow + distance <= 7 && accessColumn - distance >= 0; distance++ ) {
                    --accessBoard[ accessRow + distance ][ accessColumn - distance ];
                }
                break;
            case 4: 
                for ( int distance = 0; accessColumn - distance >= 0; distance++ ) {
                    --accessBoard[ accessRow ][ accessColumn ];
                }
                break;
            case 5: 
                for ( int distance = 0; accessRow - distance >= 0 && accessColumn - distance >= 0; distance++ ) {
                    --accessBoard[ accessRow - distance ][ accessColumn - distance ];
                }
                break;
            case 6: 
                for ( int distance = 0; accessRow - distance >= 0; distance++ ) {
                    --accessBoard[ accessRow - distance ][ accessColumn ];
                }
                break;
            case 7: 
                for ( int distance = 0; accessRow - distance >= 0 && accessColumn + distance <= 7; distance++ ) {
                    --accessBoard[ accessRow - distance ][ accessColumn + distance ];
                }
                break;
        } /* end switch for direction */
    } /* end for of direction */
} /* end function accessNegate*/

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
