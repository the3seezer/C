/*
theBitRiddler
7/22/2023
2:17 PM
Eight Queens
*/
#include <stdio.h>

#define SIZE 65

int validMove( int, int, int [][ 8 ] );
int validSquare( int, int, int[][ 8 ] );
void printBoard( int workBoard[][ 8 ] );
int rowRecursive( int, int, int, int, int [][ 8 ]);
int columnRecursive( int, int, int, int, int, int [][ 8 ]);
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

    } /* end for */

} /* end main */

int queen( int row, int column, int route ) {
    int board[ 8 ][ 8 ] = { 0 };
    int currentRow = 0;
    int currentColumn = 0;
    int moveNumber = 0;
    clearBoard(board);
    
    currentRow = row;
    currentColumn = column;
    board[ currentRow ][ currentColumn ] = ++moveNumber;

    int testRow = 0;
    moveNumber = rowRecursive( testRow, moveNumber, currentRow, currentColumn, board );
    
    printBoard(board);
    printf_s( "The last queen was the %dth on route %d\n\n", moveNumber, route );
    if ( moveNumber == 8 ) 
        return 1;
    else  
        return 0;

} /* end main */

int columnRecursive( int testRow, int testColumn, int moveNumber, int currentRow, int currentColumn, int board[][ 8 ]) {
	
	if ( testColumn < 8 ) {

		if( validSquare( testRow, testColumn, board) ) {
            currentRow = testRow;
            currentColumn = testColumn;
            board[ currentRow ][currentColumn ] = ++moveNumber;
        } /* end if */
        
        moveNumber = columnRecursive( testRow, ++testColumn, moveNumber, currentRow, currentColumn, board );
	} /* end if*/
                       
    return moveNumber;
            
} /* end function columnRecursive */

int rowRecursive( int testRow, int moveNumber, int currentRow, int currentColumn, int board[][ 8 ]) {

   if ( testRow < 8 ) {
   		
   		int testColumn = 0;
   		moveNumber = columnRecursive( testRow, testColumn, moveNumber, currentRow, currentColumn, board );
			
	    moveNumber = rowRecursive( ++testRow, moveNumber, currentRow, currentColumn, board );	

   }
        
    return moveNumber;

} /* end function rowRecursive */

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