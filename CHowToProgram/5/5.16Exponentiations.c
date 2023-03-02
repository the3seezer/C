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
	double z = 1;
	for(int i = 1;i <= y;i++){
		z *= x;
	}
	return z;
}
