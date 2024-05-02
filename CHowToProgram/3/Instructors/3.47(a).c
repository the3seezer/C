/*
 theBitRiddler
 3/27/2023
 12:13 PM
 Factorial
*/
#include <stdio.h>
int main(void) {
	int n = 0;
	int number = -1;
	unsigned factorial = 1;
	
	do {
		printf("%s", "Enter a positive integer ");
		scanf("%d", &number);
	} while (number < 0);
	
	n = number;
	
	while (n >= 0) {
		
		if (n == 0) {
			factorial *= 1;
		}
		else {
			factorial *= n;
		}
		
		--n;
	}
	
	printf("%d! is %u\n", number, factorial);
}