/* 
 theBitRiddler
 5/3/2023
 5:15 PM
 Even function
*/
#include <stdio.h>

int even( int );

int main( void ) {
	int i = 0;
	int x = 0;
	
	for ( i = 1; i <= 3; i++ ) {
		printf( "%s", "Enter an integer: " );
		scanf( "%d", &x );
		
		if ( even( x ) ) {
			
			printf( "%d is an even integer \n", x );
			
		}
		else {
			
			printf( "%d is not an even integer \n", x );
			
		}
		
	}
	
} /* end main */

int even( int a ) {
	
	return !( a % 2 );
	
}
