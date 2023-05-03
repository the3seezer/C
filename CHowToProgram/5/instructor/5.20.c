/* 
 theBitRiddler
 5/3/2023
 5:34 PM
 the square of characters
*/
#include <stdio.h>

void square(int side, char fillCharacter);

int main( void ) {
	int s = 0;
	char c = 0;
	
	printf( "%s", "Enter a side and a character: ");
	scanf( "%d%c", &s, &c );
	
	square( s, c );
	
} /* end main */

void square( int side, char fillCharacter ) {
	int loop = 0;
	int loop2 = 0;
	
	for ( loop = 1; loop <= side; loop++ ) {
		
		for ( loop2 = 1; loop2 <= side; loop2++ ) {
			
			printf( "%c", fillCharacter );
			
		}
		
		printf( "%s", "\n");
		
	}
}
