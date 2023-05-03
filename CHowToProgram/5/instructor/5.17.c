/*
 theBitRiddler
 5/3/2023
 5:07 PM
 the multiple function
*/
#include <stdio.h>

int multiple( int a, int b);

int main( void ) {
	int i = 0;
	int x = 0;
	int y = 0;
	
	for (i = 1; i <= 3; i++ ) {
		printf("%s", "Enter two integers: ");
		scanf( "%d%d", &x, &y );
		
		if (multiple( x, y ) ) {
			
			printf("%d is a multiple of %d\n", y, x );
			
		}
		else {
			
			printf("%d is not a multiple of %d\n", y, x );
			
		}
		
	}
	
}

int multiple( int a, int b) {
	
	return !( b % a );
	
}
