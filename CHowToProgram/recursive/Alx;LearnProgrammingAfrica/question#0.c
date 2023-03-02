//theBitRiddler
//11-14-2022
//4:31pm
//recursive
#include <stdio.h>

void print(int);

int main(void){
	puts("Enter a number to figure out the count down");
	int number = 0;
	scanf("%d",&number);
	print(number);
}

void print(int n){
	printf("%d",n);
	n--;
	if(n > 0){
		print(n);
	}
}
