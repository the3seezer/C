/* 
 theBitRiddler
 5/6/2023
 11:21 PM
 Quality Points
*/
#include <stdio.h>

int qualityPoints( int a );

int main( void ) {
	int i = 0;
	int average = 0;
	
	for (i = 1; i <= 5; i++ ) {
		
		printf( "Enter the student's average: ");
		scanf( "%d", &average );
		
		
		printf( "%d on a four point scale is %d\n", 
		average, qualityPoints( average ) );
		
	} /* end for */
		
} /* end main */

int qualityPoints( int a ) {
	
	if ( a >= 90 ) {
		return 4;
	} /* end if */
	else if ( a >= 80 ) {
		return 3;
	} /* end else if */
	else if ( a >= 70 ) {
		return 2;
	} /* end else if */
	else if ( a >= 60) {
		return 1;
	}
	else {
		return 0;
	} /* end else */
	
} /* end function qualityPoints */
