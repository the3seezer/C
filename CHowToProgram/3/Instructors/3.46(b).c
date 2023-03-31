/* 
 theBitRiddler
 3/26/2023
 5:36 PM
 Decrypting
*/
#include <stdio.h>
int main(void) {
	int first = 0;
	int second = 0;
	int third = 0;
	int fourth = 0;
	int encryptedNumber = 0;
	int temp1 = 0;
	int temp2 = 0;
	int decryptedNumber = 0;
	
	printf("%s", "Enter a four digit encrypted number ");
	scanf("%d", &encryptedNumber);
	
	temp1 = encryptedNumber;
	
	first = temp1 / 1000;
	temp2 = temp1 % 1000;
	
	second = temp2 / 100;
	temp1 = temp2 % 100;
	
	third = temp1 / 10;
	temp2 = temp1 % 10;
	
	fourth = temp2;
	
	temp1 = (first + 3) % 10;
	first = (third + 3) % 10;
	third = temp1;
	
	temp1 = (second + 3) % 10;
	second = (fourth + 3) % 10;
	fourth = temp1;
	
	decryptedNumber = (first * 1000) + (second * 100) +
					  (third * 10) + fourth;
					  
	printf("Decrypted number is %d\n", decryptedNumber);
}
