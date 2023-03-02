//theBitRiddler
//17-9-2022
//13:31
//factorial
#include <stdio.h>

unsigned long long int factorial(int number);

int main(void){
	int n = 0;
	puts("Enter any number");
	scanf("%d",&n);
	printf("The factorial of %d is %u\n",n,factorial(n));
}

unsigned long long int factorial(int number){
	if(number <= 1){//base case
		return 1;
	}
	else{
		return number * (factorial(number - 1));
	}
}
