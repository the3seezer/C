//theBitRiddler
//18-9-2022
//13:59
//Recursive Factorial Function
#include <stdio.h>

unsigned long long int factorial(int number);

int main(void){
	for(int i = 1;i <= 21;i++){
		printf("%2d! = %30llu\n",i,factorial(i));
	}
}

unsigned long long int factorial(int number){
	if(number <= 1){
		return 1;
	}
	else{
		return number * factorial(number - 1);
	}
}
