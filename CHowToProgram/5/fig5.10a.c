//theBitRiddler
//18-9-2022
//2:56pm
//Recursive Fibonacci Function(1.618...)
#include <stdio.h>

unsigned long long int fibonacci(int number);

int main(void) {
	for (int i = 0; i <= 10; i++){
		printf("Fibonacci%2d = %20llu\n", i, fibonacci(i));
	}
	puts("");
	printf("fibonacci(20) = %20llu\n", fibonacci(20));
	printf("fibonacci(30) = %20llu\n", fibonacci(30));
	printf("fibonacci(40) = %20llu\n", fibonacci(40));
}

unsigned long long int fibonacci(int n){
	if(n == 0 || n == 1){
		return n;
	}
	else{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
