/* 
 theBitRiddler
 3/6/2023
 12:13 PM
 Separating the digits
*/
#include <stdio.h>
int main(void) {
	int number = 0;
	int temp1 = 0;
	int temp2 = 0;
	
	printf("Enter a five digit number ");
	scanf("%d", &number);
	
	printf("%d   ", number / 10000);
	temp1 = number % 10000;
	
	printf("%d   ", temp1 / 1000);
	temp2 = temp1 % 1000;
	
	printf("%d   ", temp2 / 100);
	temp1 = temp2 % 100;
	
	printf("%d   ", temp1 / 10);
	temp2 = temp1 % 10;
	
	printf("%d", temp2);
}
