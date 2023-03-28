/*
 theBitRiddler
 3/26/2023
 11:00 AM
 binary to decimal
*/
#include <stdio.h>
int main(void) {
	int binary = 0;
	int number = 0;
	int decimal = 0;
	int highBit = 16;
	int factor = 10000;
	
	printf("%s", "Enter a binary number (five digit maximum) ");
	scanf("%d", &binary);
	
	number = binary;
	
	while (highBit >= 1) {
		
		decimal += binary / factor * highBit;
		
		binary %= factor;
		
		highBit /= 2;
		
		factor /= 10;
	}
	
	printf("The decimal equivalence of %d is %d\n", number, decimal);
}
