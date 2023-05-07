/* 
 theBitRiddler
 5/6/2023
 10:05 PM
 
*/
#include <stdio.h>

int reverseDigits( int );

int main( void ) {
	int number = 0;
	
	printf( "%s", "Enter a number between 1 and 9999: ");
	scanf( "%d", &number );
	
	printf( "The number with its digits reversed is %d\n", 
	reverseDigits( number ) );
	
} /* end main */

int reverseDigits( int n ) {
	int reverse = 0;
	int divisor = 1000;
	int multiplier = 1;
	
	while ( n >= 9 ) {
		
		if ( n >= divisor ) {
			
			reverse += n / divisor * multiplier;
			
			n %= divisor;
			divisor /= 10;
			multiplier *= 10;
			
		} /* end if */
		else {
			
			divisor /= 10;
			multiplier *= 10;
			
		} /* end else */
		
	} /* end while */
	
	reverse += n * multiplier;
	
	return reverse;
	
} /* end function reverseDigits */
