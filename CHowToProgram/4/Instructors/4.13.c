/*
 theBitRiddler 
 3/30/2023
 12:14 PM
 product of odd integers from 1 to 15
*/
#include <stdio.h>
int main(void) {
	long i = 0;
	long product = 1;
	
	for (i = 3; i <= 15; i += 2)
		product *= i;
		
	printf("Product of odd integers from 1 to 15 is %d\n", product);
}
