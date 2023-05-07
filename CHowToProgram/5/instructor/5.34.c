/*
 theBitRiddler
 5/7/2023
 11:09 AM
 Advanced Computer Assisted Instruction
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void incorrectAnswer( void );
void correctAnswer( void );
void multiplication( void );

int main( void ) {
	srand( time( NULL ) );
	multiplication();
	return 0;
} /* end main */

void multiplication( void ) {
	int i = 0;
	int x = 0;
	int y = 0;
	int response = 0;
	int right = 0;
	int wrong = 0;
	
	for ( i = 1; i <= 10; i++ ) {
		x = rand() % 10;
		y = rand() % 10;
		
		printf( "How much is %d times %d\n", x, y );
		scanf( "%d", &response );
		
		while ( response != x * y ) {
			++wrong; 
			i++; /* continue i to get accurate wrongs and rights */
			incorrectAnswer();
			scanf( "%d", &response );
		} /* end while */
		
		++right;
		correctAnswer();
		
	} /* end for */
	
	if ( ( double ) right / ( right + wrong ) < .75 ) {
		printf( "%s", "Please ask your instructor for extra help.\n");
	}
	
	printf( "%s", "That's all for now. Bye!\n");
	
} /* end function multiplication */

void incorrectAnswer( void ) {
	
	switch ( rand() % 4 ) {
		case 0:
			printf( "%s", "No. Please try again.\n?" );
			break;
		
		case 1: 
			printf( "%s", "Wrong. Try once more.\n?" );
			break;
			
		case 2:
			printf( "%s", "Don't give up.\n?" );
			break;
			
		case 3:
			printf( "%s", "No. Keep trying.\n?" );
			break;
	} /* end switch */	
} /* end function incorrectAnswer */

void correctAnswer( void ) {
	
	switch ( rand() % 4 ) {
		case 0:
			printf( "%s", "Very Good!\n\n" );
			break;
			
		case 1:
			printf( "%s", "Excellent!\n\n" );
			break;
			
		case 2:
			printf( "%s", "Nice work!\n\n" );
			break;
			
		case 3:
			printf( "%s", "Keep up the good work!\n\n" );
			break;
	} /* end switch */	
} /* end function correctAnswer */
