/* 
 theBitRiddler
 5/3/2023
 5:34 PM
 the square of characters
*/
#include <stdio.h>

void square( char fillCharacter, int side );

int main( void ) {
	char c = '0';
	int s = 0;
	
	printf( "%s", "Enter a character and a side: ");
	scanf( "%c%d", &c, &s );
	
	square( c, s );
	
} /* end main */

void square( char fillCharacter, int side ) {
	int loop = 0;
	int loop2 = 0;
	
	for ( loop = 1; loop <= side; loop++ ) {
		
		for ( loop2 = 1; loop2 <= side; loop2++ ) {
			
			printf( "%c", fillCharacter );
			
		}
		
		printf( "%s", "\n");
		
	}
}
