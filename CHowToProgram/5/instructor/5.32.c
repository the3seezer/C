/* 
 theBitRiddler
 5/7/2023 
 7:22 AM
 How much is x times y?
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void multiplication( void );

int main( void ) {
	srand( time( NULL ) );
	multiplication();
	
	return 0;
} /* end main */

void multiplication( void ) {
	int x = 0;
	int y = 0;
	int response = 0;
	
	printf( "%s", "Enter -1 to end \n");
	
	while ( response != -1 ) {
		x = rand() % 10;
		y = rand() % 10;
		
		printf( "How much is %d times %d\n", x, y );
		scanf( "%d", &response );
		
		while ( response != -1 && response != x * y ) {
			
			printf( "%s", "No, Please try again\n");
			scanf( "%d", &response );
			
		} /* end while */
		
		if ( response != -1 ) {
			
			printf( "%s", "Very Good\n\n");
			
		} /* end if */
		
	} /* end while */
	
	printf( "%s", "That's all for today, Bye!\n");
	
}
