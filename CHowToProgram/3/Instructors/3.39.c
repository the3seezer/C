<<<<<<< HEAD
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
=======
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
>>>>>>> 78d99489bc9fd084c8e4baa79a5431b5829ff12e
