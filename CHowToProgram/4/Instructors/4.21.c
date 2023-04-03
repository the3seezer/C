/*
 theBitRiddler
 02/04/2023
 12:16
 counter initialized in definition instead of in the for loop
*/
#include <stdio.h>
int main(void) {
	int counter = 1;
	
	for ( ; counter <= 10; ++counter) 
		printf("%d ", counter);
}
