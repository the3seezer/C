//theBitRiddler
//9-29-2022
//11:35pm
//Exponetiation
#include <stdio.h>

double integerPower(int base,unsigned int exponent);

int main(void){
	printf("%.2f\n",integerPower(3,4));
}

double integerPower(int x,unsigned int y){
	if(y == 1){
		return x; 
	}
	else{
		return x * integerPower(x,y-1);
	}
}
