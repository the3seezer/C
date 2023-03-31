/*
 theBitRiddler
 3/30/2023
 12:20 PM
 Factorial from integers from 1 to 5
*/
#include <stdio.h>
int main(void) {
	int i = 0;
	int j = 0;
	int factorial = 0;
	
	printf("%s", "X\tFactorial of X\n");
	for (i = 1; i <= 5; ++i) {
		factorial = 1;
		
		for (j = 1; j <= i; ++j)
			factorial *= j;
		
		printf("%d\t%d\n", i, factorial);
	}
}
