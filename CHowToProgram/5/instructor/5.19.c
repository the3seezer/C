/* 
 theBitRiddler
 5/3/2023
 5:26 PM
 Square Sides
*/
#include <stdio.h>

void square( int s );

int main( void ) {
	int side = 0;
	
	printf( "%s", "Enter square side: " );
	scanf( "%d", &side);
	
	square( side );
	
} /* end main */

void square( int s ) {
	int i = 0;
	int j = 0;
	
	for ( i = 1; i <= s; i++ ) {
		
		for ( j = 1; j <= s; j++ ) {
			
			printf( "%s", "*" );
			
		}
		
		printf( "%s", "\n" );
		
	}
	
}
