#include <stdio.h>
int main(void){//(a)Factorial
	int n = 0;
	int total = 1;
	printf_s("%s","Write a non negative integer:");
	scanf_s("%d",&n);
	while(n >= 1){
		printf_s("%d",n);
	    printf_s("%s", n > 1 ? " . " : " Which is: ");
	    total = total * n;//total *= n;
		n--;
	}
	printf_s("%d",total);
}
