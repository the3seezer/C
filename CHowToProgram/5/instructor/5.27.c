/*
 theBitRiddler
 5/6/2023
 9:27 PM
 The prime numbers
*/
#include <stdio.h>

int prime( int n );

int main( void ) {
	int loop = 0;
	int count = 0;
	
	printf( "%s", "Prime numbers from 1 to 10000: \n");
	
	for ( loop = 1; loop <= 10000; loop++ ) {
		
		if ( prime( loop ) ) {
			
			++count;
			printf( "%6d", loop );
			
			if ( count % 10 == 0 ) {
				
				printf( "%s", "\n" );
				
			}
			
		} /* end if */
		
	} /* end for */
	
} /* end main */

int prime( int n ) {
	int loop2 = 0;
	
	for ( loop2 = 2; loop2 <= n / 2; loop2++ ) {
		
		if ( n % loop2 == 0 ) {
			
			return 0;
			
		} /* end if */
		
	} /* end for */
	
	return 1;
	
} /* end prime */
