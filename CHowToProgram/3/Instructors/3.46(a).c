/* 
 theBitRiddler
 3/26/2023
 4:56 PM
 Encrypting
*/
#include <stdio.h>
int main(void) {
	int first = 0;
	int second = 0;
	int third = 0;
	int fourth = 0;
	int digit = 0;
	int temp1 = 0;
	int temp2 = 0;
	int encryptedNumber = 0;
	
	printf("%s", "Enter a four digit number to be encripted ");
	scanf("%d", &digit);
	
	temp1 = digit;
	
	first = (temp1 / 1000 + 7) % 10; 
	temp2 = temp1 % 1000;
	
	second = (temp2 / 100 + 7) % 10; 
	temp1 = temp2 % 100;
	
	third = (temp1 / 10 + 7) % 10; 
	temp2 = temp1 % 10;
	
	fourth = (temp2 + 7) % 10; 
	
	
	temp1 = first;
	first = third * 1000;  
	third = temp1 * 10; 
	
	temp1 = second;
	second = fourth * 100; 
	fourth = temp1; 
	
	encryptedNumber = first + second + third + fourth;
	printf("Encripted number is %d\n", encryptedNumber);
}