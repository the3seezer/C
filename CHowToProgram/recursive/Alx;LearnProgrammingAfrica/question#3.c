//theBitRiddler
//11-14-2022
//4:57pm
//recursion
#include <stdio.h>

void print(int);

int main(void){
	puts("Enter a number to count down");
	int num = 0;
	scanf("%d",&num);
	print(num);
}

void print(int n){
	if(n < 0){
		return;
	}
	printf("%d",n);
	n--;
	print(n);
}
