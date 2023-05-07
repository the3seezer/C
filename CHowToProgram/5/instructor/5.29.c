/*
 theBitRiddler
 5/6/2023
 11:00 PM
 Greatest Common Divisor
*/
#include <stdio.h>

int gcd( int, int );

int main( void ) {
	int j = 0;
	int a = 0;
	int b = 0;
	
	for ( j = 1; j <= 5; j++ ) {
		
		printf( "%s", "Enter two integers: ");
		scanf( "%d%d", &a, &b );
		
		printf( "The greatest Common Divisor "
		"of %d and %d is %d\n", a, b, gcd( a, b ) );
		
	} /* end for */
		
} /* end main */

int gcd( int x, int y ) {
	int i = 0;
	int greatestCD = 1;
	
	for ( i = 1; i <= ( ( x < y ) ? x : y ); i++ ) {
		
		if ( x % i == 0 && y % i == 0 ) {
			
			greatestCD = i;
			
		} /* end if */
		
	} /* end for */
	
	return greatestCD;
	
} /* end function gcd */
