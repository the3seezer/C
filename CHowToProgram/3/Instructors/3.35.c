/* 
 theBitRiddler
 3/25/2023
 9:54 AM
 Palindrome
*/
#include <stdio.h>
int main(void) {
	int number = 0;
	int temp1 = 0;
	int temp2 = 0;
	int firstDigit = 0;
	int secondDigit = 0;
	int fourthDigit = 0;
	int fifthDigit = 0;
	
	printf("%s", "Enter a five digit number ");
	scanf("%d", &number);
	
	temp1 = number;
	
	firstDigit = temp1 / 10000;
	temp2 = temp1 % 10000;
	
	secondDigit = temp2 / 1000;
	temp1 = temp2 % 1000;
	
	temp2 = temp1 % 100;
	
	fourthDigit = temp2 / 10;
	temp1 = temp2 % 10;
	
	fifthDigit = temp1;
	
	if (firstDigit == fifthDigit) {
		
		if (secondDigit == fourthDigit) {
			printf("%d is a palindrome\n", number);
		}
		else {
			printf("%d is not a palindrome\n", number);
		}
	}
	else {
		printf("%d is not a palindrome\n", number);
	}
}
