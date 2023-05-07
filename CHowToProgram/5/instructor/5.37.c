/* 
 theBitRiddler
 5/7/2023
 3:21 PM
 Recursive Power function
*/
#include <stdio.h>

long power( long base, long expo );

int main( void ) {
	long b = 0;
	long e = 0;
	
	printf( "%s", "Enter a base and an exponent. ");
	scanf( "%ld%ld", &b, &e );
	
	printf( "%ld raise to %ld is %ld\n", b, e, power( b, e ) );
	
}

long power( long base, long expo ) {
	
	if ( expo == 1 ) {
		return base;
	}
	else {
		return base * power( base, expo - 1 );
	}
}
