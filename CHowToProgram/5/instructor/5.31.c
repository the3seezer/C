/* 
 theBitRiddler
 5/6/2023
 11:36 PM
 Head or Tails
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip( void );

int main( void ) {
	int loop = 0;
	int headCount = 0;
	int tailCount = 0;
	
	srand( time( NULL ) );
	
	for ( loop = 1; loop <= 100; loop++ ) {
		
		if ( flip() ) {
			
			++headCount;
			
		} /* end if */
		else {
			
			++tailCount;
			
		} /* end else */
		
		if ( loop % 10 == 0 ) {
			
			printf( "%s", "\n" );
			
		}
		
	} /* end for */
	
	printf( "The total number of heads was %d\n", headCount );
	printf( "The total number of tails was %d\n", tailCount );
	
	return 0;
	
}

int flip( void ) {
	int HorT = rand() % 2;
	
	if ( HorT ) {
		printf( "%s", "Heads ");
	} /* end if */
	else {
		printf( "%s", "Tails ");
	} /* end else */
	
	return HorT;
	
} /* end function flip */
