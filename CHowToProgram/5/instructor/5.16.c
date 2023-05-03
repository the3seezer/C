/*
 theBitRiddler
 5/3/2023
 4:48 PM
 The base exponent function
*/
#include <stdio.h>

int integerPower( int, int );

int main( void ) {
	int base = 0;
	int exponent = 0;
	
	printf( "%s", "Enter integer base and exponent: " );
	scanf( "%d%d", &base, &exponent );
	
	printf( "%d to the power of %d is: %d\n", 
	base, exponent, integerPower( base, exponent ) );
	
} /* end main */

int integerPower( int b, int e ) {
	int i = 0;
	int product = 1;
	
	for ( i = 1; i <= e; i++ ) {
		
		product *= b;
		
	}
	
	return product;
	
}


