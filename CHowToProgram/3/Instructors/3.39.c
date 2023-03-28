/* 
 theBitRiddler
 3/26/2023
 12:04 PM
 sevens
*/
#include <stdio.h>
int main(void) {
	int number = 0;
	int numCopy = 0;
	int digit = 0;
	int factor = 10000;
	int sevens = 0;
	
	printf("%s", "Enter a five digit number ");
	scanf("%d", &number);
	
	numCopy = number;
	
	while (factor >= 1) {
		
		digit = numCopy / factor;
		
		if (digit == 7) {
			++sevens;
		}
		
		numCopy %= factor;
		factor /= 10;
	}
	
	printf("The number %d has %ld seven(s) in it\n", number, sevens);
}
