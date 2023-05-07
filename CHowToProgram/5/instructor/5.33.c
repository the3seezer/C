/* 
 theBitRiddler
 5/7/2023
 8:57 PM
 Computer Assisted Instruction CAI
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void correctAnswer( void );
void incorrectAnswer( void );
void multiplication( void );

int main( void ) {
	srand( time( NULL ) );
	multiplication();
	return 0;
} /* end function main */

void multiplication( void ) {
	int x = 0;
	int y = 0;
	int response = 0;
	
	printf( "%s", "Enter -1 to end. \n");
	
	while ( response != -1 ) {
		x = rand() % 10;
		y = rand() % 10;
		
		printf( "How much is %d times %d ?\n", x, y );
		scanf( "%d", &response );
		
		while ( response != -1 && response != x * y ) {
			incorrectAnswer();
			scanf( "%d", &response );
		} /* end while */
		
		if ( response != -1 ) {
			correctAnswer();
		} /* end if */
		
	} /* end while */
	
	printf( "%s", "That's all for now. Bye\n" );
	
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
