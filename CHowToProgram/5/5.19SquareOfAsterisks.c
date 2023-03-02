//theBitRiddler
//10-1-2022
//5:06pm
//Square of Asterisks
#include <stdio.h>

int asterisksSquare(int);

int main(void){
	int a = 0;
	puts("Enter any number to create a square");
	scanf("%d",&a);
	asterisksSquare(a);
}

int asterisksSquare(int x){
	for(int row = 1;row <= x;row++){
		for(int col = 1;col <= x;col++){
			printf("%s","*");
		}
		puts("");
	}
}
