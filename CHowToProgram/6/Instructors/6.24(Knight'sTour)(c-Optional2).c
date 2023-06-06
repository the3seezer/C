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
void tour( int row, int column, int moveTour );

int main( void ) {
    int move = 0;
    int i = 0;
    int j = 0;

    for ( i = 0; i < 8; i++ ) {

        for ( j = 0; j < 8; j++ ) {
            tour( i, j, ++move );
        } /* end for */

    } /* end for */

    return 0;
} /* end main */

void tour( int row, int column, int moveTour ) {
 int board[ 8 ][ 8 ]; /* chess board */
 /* array of accesibility */
 int access[ 8 ][ 8 ] = { 2, 3, 4, 4, 4, 4, 3, 2,
 3, 4, 6, 6, 6, 6, 4, 3,
 4, 6, 8, 8, 8, 8, 6, 4,
 4, 6, 8, 8, 8, 8, 6, 4,
 4, 6, 8, 8, 8, 8, 6, 4,
 4, 6, 8, 8, 8, 8, 6, 4,
 3, 4, 6, 6, 6, 6, 4, 3,
 2, 3, 4, 4, 4, 4, 3, 2 };

 /* eight horizontal and vertical moves for the knight */
 int horizontal[ 8 ] = { 2, 1, -1, -2, -2, -1, 1, 2 };
 int vertical[ 8 ] = { -1, -2, -2, -1, 1, 2, 2, 1 };
 int currentRow; /* current row */
 int currentColumn; /* current column */
 int moveNumber = 0; /* move counter */
 int testRow; /* possible next row */
 int testColumn; /* possible next column */
 int minRow; /* row with minimum access number */
 int minColumn; /* column with minimum access number */
 int minAccess = 9; /* impossible access number */
 int accessNumber; /* current access number */
 int moveType; /* current move type */
 int done; /* flag to indicate end */
 
 clearBoard( board ); /* initialize array board */
 currentRow = row;
 currentColumn = column;
 board[ currentRow ][ currentColumn ] = ++moveNumber;
 done = FALSE;

 /* continue while knight still has valid moves */
 while ( !done ) { 
 accessNumber = minAccess;

 /* loop through all move types */
 for ( moveType = 0; moveType < 8; moveType++ ) { 
 testRow = currentRow + vertical[ moveType ];
 testColumn = currentColumn + horizontal[ moveType ];

 /* make sure move is valid */
 if ( validMove( testRow, testColumn, board ) ) { 

 /* if move is valid and has lowest accessNumber,
 set square to accessNumber */
 if ( access[ testRow ][ testColumn ] < accessNumber ) { 
 accessNumber = access[ testRow ][ testColumn ];
 minRow = testRow;
 minColumn = testColumn;
 } /* end if */

 --access[ testRow ][ testColumn ];
 } /* end if */

 } /* end for */

 /* end if knight has no moves */
 if ( accessNumber == minAccess ) {
 done = TRUE;
 } /* end if */
 else { 
 currentRow = minRow;
 currentColumn = minColumn;
 board[ currentRow ][ currentColumn ] = ++moveNumber;
 } /* end else */
 } /* end while */

 printf( "The %dth tour ended with %d moves.\n", moveTour, moveNumber ); 

 /* determine and print if a full tour was made */
 if ( moveNumber == 64 ) {
 printf( "This was a full tour!\n\n" );
 } /* end if */
 else {
 printf( "This was not a full tour.\n\n" );
 } /* end else */

 printf( "The board for this test is:\n\n" );
 printBoard( board );

 } /* end function tour */

 /* function to clear chess board */
 void clearBoard( int workBoard[][ 8 ] )
 { 
 int row; /* row counter */
 int col; /* column counter */

 /* set all squares to zero */
 for ( row = 0; row < 8; row++ ) {

 for ( col = 0; col < 8; col++ ) {
 workBoard[ row ][ col ] = 0;
 } /* end for */

 } /* end f*/

 } /* end function clearBoard */

 /* function to print chess board */
 void printBoard( int workBoard[][ 8 ] )
 { 
 int row; /* row counter */
 int col; /* column counter */

 printf( " 0 1 2 3 4 5 6 7\n" );

 /* print squares */
 for ( row = 0; row < 8; row++ ) { 
 printf( "%d", row );

 for ( col = 0; col < 8; col++ ) {
 printf( "%3d", workBoard[ row ][ col ] );
 } /* end for */

 printf( "\n" );
 } /* end for */

 printf( "\n\n\n" );
 } /* end function printBoard */

 /* function to determine if move is legal */
 int validMove( int row, int column, int workBoard[][ 8 ] )
 { 
 
 /* NOTE: This test stops as soon as it becomes false */
 return ( row >= 0 && row <= 7 && column >= 0 &&
 column <= 7 && workBoard[ row ][ column ] == 0 );

 } /* end function validMove */