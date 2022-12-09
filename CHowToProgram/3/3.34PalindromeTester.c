#include <stdio.h>
int main(void){
	int number = 0;
	int newN = 0;
	int counter = 1;
	printf_s("%s","Enter a five digit integer: \n");
	scanf("%d",&number);
	int restore = number;//preserve the original value
	while(counter <= 5){
		int remainder = number % 10;
		newN = 10 * newN + remainder;
		number /= 10;
		counter++;
	}
	if(restore == newN){
		printf_s("%d is a palindrome\n",restore);
	}
	//printf_s("%d",restore);
}
