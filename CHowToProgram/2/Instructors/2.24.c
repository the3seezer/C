/* 
 theBitRiddler
 3/5/2023
 9:54 PM
 even or odd integer
*/
#include <stdio.h>
int main(void) {
	int integer = 0;
	printf("Enter an integer ");
	scanf("%d", &integer);
	
	if (integer % 2 == 0) {
		printf("%d is an even integer\n", integer);
	}
	if (integer % 2) {
		printf("%d is an odd integer\n", integer);
	}
}
