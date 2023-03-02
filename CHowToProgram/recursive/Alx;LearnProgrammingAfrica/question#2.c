//theBitRiddler
//11-14-2022
//4:50pm
//Recursive
#include <stdio.h>

void print(int);

int main(void){
	puts("Enter a number to make a count up");
	int num = 0;
	scanf("%d",&num);
	print(num);
}

void print(int n){
	printf("%d",n);
	n++;
	if(n < 10){
		print(n);
	}
}
