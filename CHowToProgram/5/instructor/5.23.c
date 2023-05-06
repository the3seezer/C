/* 
 theBitRiddler
 5/5/2023
 4:58 PM
 Hours, Minutes and Seconds
*/
#include <stdio.h>
#include <math.h>

unsigned seconds( unsigned, unsigned, unsigned );

int main( void ) {
	int hours = 0;
	int minutes = 0;
	int secs = 0;
	int first = 0;
	int second = 0;
	int difference = 0;
	
	printf( "%s", "Enter the first time as three integers: ");
	scanf( "%d%d%d", &hours, &minutes, &secs );
	
	first = seconds( hours, minutes, secs );
	
	printf( "%s", "Enter the second time as three integers: ");
	scanf( "%d%d%d", &hours, &minutes, &secs);
	
	second = seconds( hours, minutes, secs );
	
	difference = fabs( first - second );
	
	printf( "The difference between the times is %d seconds\n",
	difference);
	
}

unsigned seconds( unsigned h, unsigned m, unsigned s ) {
	
	return h * 3600 + m * 60 + s;
	
}
