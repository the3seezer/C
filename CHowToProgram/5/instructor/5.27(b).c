/* 
 theBitRiddler
 5/6/2023
 9:41 PM
 Prime numbers
*/
#include <stdio.h>
#include <math.h>

int prime( int );

int main( void ) {
	int j = 0;
	int count = 0;
	
	printf( "%s", "Prime numbers between 1 and 10000: \n" );
	
	for ( j = 1; j <= 10000; j++ ) {
		
		if ( prime( j ) ) {
			
			++count;
			printf( "%6d", j );
			
			if ( count % 10 == 0 ) {
				
				printf( "%s", "\n" );
				
			} /* end if */
			
		} /* end if */
		
	} /* end for */
	
} /* end main */

int prime( int n ) {
	int i = 0;
	
	for ( i = 2; i <= ( int ) sqrt( n ); i++ ) {
		
		if ( n % i == 0 ) {
			
			return 0;
			
		} /* end if */
		
	} /* end for */
	
	return 1;
		
} /* end main */
