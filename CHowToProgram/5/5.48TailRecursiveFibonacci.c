//theBitRiddler
//11/18/2022
//2:10pm
//Fibonacci
#include <stdio.h>

int Fib(int ,int ,int);

int main(void){
	puts("Enter a number elements to find it's fibonacci series");
	int num = 0;
	scanf("%d",&num);
	int a = 0,b = 1;
	printf("%d ",a);
	Fib(num,a,b);
}

int Fib(int n,int a,int b){
	if(n == 0){
		return a;
	}
	else if(n == 1){
		return b;
	}
	else{
		printf(" %d",b);
		return Fib(n - 1,b,a + b);
	}
}               
