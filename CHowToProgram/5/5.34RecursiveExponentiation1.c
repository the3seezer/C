//theBitRiddler
//10-15-2022
//10:19pm
//Exponetiation
#include <stdio.h>

double integerPower(int base,unsigned int exponent);

int main(void){
	puts("Enter the base...");
	int base = 0;
	scanf("%d",&base);
	puts("Enter the exponent...");
	int expo = 0;
	scanf("%d",&expo);
	printf("%.2f\n",integerPower(base,expo));
}

double integerPower(int x,unsigned int y){
	if(y == 1){
		return x; 
	}
	else{
		return x *= integerPower(x,y-1);
	}
}
