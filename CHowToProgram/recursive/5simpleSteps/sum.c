//theBitRiddler
//11/18/2022
//3:29pm
//Recursive Sum
#include <stdio.h>

int sum(int);

int main(void){
	puts("Enter a number to get a sum of integers upto the number");
	int n = 0;
	scanf("%d",&n);
	printf("The sum;%d\n",sum(n));
}

int sum(int n){
	if(n == 0){
		return 0;
	}
	else{
		return n + sum(n - 1);
	}
}
