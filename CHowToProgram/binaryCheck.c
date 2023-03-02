//theBitRiddler
//11/20/2022
//10:25am
//to binary or not
#include <stdio.h>

int binCheck(int);

int main(void){
	puts("Enter your number");
	int n = 0;
	scanf("%d",&n);
	binCheck(n);
}

int binCheck(int n){
	int j = 0;
	while(n > 0){
		j = n % 10;
		if(j != 0 && j != 1){
			printf("%s","This is not a binary number\n");
			break;
		}
		n /= 10;
		if(n == 0){
			printf("%s","This is a binary number\n");
		}
	}
}
