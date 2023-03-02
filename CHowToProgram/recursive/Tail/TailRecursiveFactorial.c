//theBitRiddler
//11/18/2022
//1:57pm
//Tail Recursive Factorial
#include <stdio.h>

int Fac(int ,int);

int main(void){
	puts("Enter a number to fing a factorial");
	int num = 0;
	scanf("%d",&num);
	int a = 1;
	printf("The factorial:%d\n",Fac(num,a));
}

int Fac(int n,int a){
	if(n == 0){
		return a;
	}
	else{
		return Fac(n - 1,a * n);
	}
}
