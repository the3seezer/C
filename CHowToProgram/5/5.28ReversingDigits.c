//theBitRiddler
//10-14-2022
//1:32pm
/*
Reversing Numbers
*/
#include <stdio.h>

int reverse(int);

int main(void){
	puts("Enter any four digit number to reverse");
	int x = 0;
	scanf("%d",&x);
	printf("The Reverse:%d\n",reverse(x));
}

int reverse(int y){
	int rev = 0;//reverse
	for(int i = 1;i <= 4;i++){
		int z = y % 10;//remainder
		rev = rev * 10 + z;
		y /= 10;//cut off the last digit
	}
	return rev;
}
