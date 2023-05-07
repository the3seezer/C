/* 
 theBitRiddler
 5/7/2023
 11:48 AM
 Guess the number
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessGame( void );

int main( void ) {
	srand( time( NULL ) );
	guessGame();
	return 0;
} /* end main */

void guessGame( void ) {
	int x = 0;
	int guess = 0;
	int response = 0;
	
	do {
		x = 1 + rand() % 1000;
		
		printf( "%s", "I have a number between 1 and 1000.\n"
		"Can you guess my number?\n"
		"Please type your first guess.\n" );
		scanf( "%d", &guess );
		
		while ( guess != x ) {
			
			if ( guess < x ) {
				printf( "%s", "Too low. Try again.\n" );
			}
			else {
				printf( "%s", "Too high. Try again.\n" );
			} /* end if */
			
			scanf( "%d", &guess );
			
		} /* end while */
		
		printf( "%s", "Excellent! You guessed the number!\n"
 		"Would you like to play again?"
		"\nPlease type (y == 1 or n == 2)\n?" );
		scanf( "%d", &response );
		
	}
	 while ( response == 1 ); /* end do while */
	
} /* end function guessGame */
