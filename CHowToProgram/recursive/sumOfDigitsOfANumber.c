//theBitRiddler
//11/20/2022
//6:12pm
/* To find sum of digits of a number using Recursion */
#include <stdio.h>

int sum(int);

int main(void){
	puts("Enter a number to find sum of its digits");
	int num = 0;
	scanf("%d",&num);
	printf("the sum of %d is %d",num,sum(num));
}

int sum(int n){
	if(n != 0){
		return (n % 10 + sum(n / 10));
	}
	else{
		return 0;
	}
}
