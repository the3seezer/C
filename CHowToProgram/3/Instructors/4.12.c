/*
 theBitRiddler
 3/30/2023
 12:09 PM
 sum from 2 to 30
*/
#include <stdio.h>
int main(void) {
	int i = 0;
	int sum = 0;
	
	for (i = 2; i <= 30; i += 2)
		sum += i;
		
	printf("The sum of even integers from 2 to 30 is %d\n", sum);
}
