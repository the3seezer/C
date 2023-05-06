/* 
 theBitRiddler
 5/3/2023
 5:56 PM
 Program Segments
*/
#include <stdio.h>

int quotient( int, int );
int remainder( int, int );

int main( void ) {
	int number = 0;
	int divisor = 10000;
	
	printf( "%s", "Enter a number between 1 and 32767: ");
	scanf( "%d", &number );
	
	while ( number >= 10 ) {
		
		if ( number >= divisor ) {
			
			printf( "%d ", quotient( number, divisor ) );
			
			number = remainder( number, divisor );
			
			divisor = quotient( divisor, 10 );
			
		}
		else {
			
			divisor = quotient( divisor, 10 );
			
		}
		
	}
	
	printf( "%d\n", number);

}

int quotient( int a, int b ) {
	
	return a / b;
	
}

int remainder( int a, int b ) {
	
	return a % b;
	
}
