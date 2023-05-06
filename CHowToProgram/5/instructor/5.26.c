/*
 theBitRiddler
 5/6/2023
 9:03 PM
 the perfect numbers
*/
#include <stdio.h>

int perfect( int );

int main( void ) {
	int j = 0;
	
	printf( "%s", "For integers between 1 and 1000: \n");
	
	for ( j = 2; j <= 1000; j++ ) {
		
		if ( perfect( j ) ) {
			
			printf( "%d is a perfect integer.\n", j );
			
		}
		
	} /* end for */
	
} /* end main */

int perfect( int value ) {
	int factorSum = 1;
	int i = 0;
	
	for ( i = 2; i <= value / 2; i++ ) {
		
		if ( value % i == 0 ) {
			
			factorSum += i;
			
		} /* end if */
		
	} /* end for */
	
	if ( factorSum == value ) {
		
		return 1;
		
	} /* end if */
	else {
		
		return 0;
		
	} /* end else */
	
}

