//theBitRiddler
//10-15-2022
//10:15am
/*
Greatest Common Divisor
*/
#include <stdio.h>

int gcd(int ,int);

int main(void){
	int a = 0;
	int b = 0;
	puts("Enter two integers to determine the Greatest Common Divisor");
	scanf("%d%d",&a,&b);
	printf("The Greatest Common Divisor:%d\n",gcd(a,b));
}

int gcd(int x,int y){
	int z = x;
	if(y < z){
		z = y;
	}
	for(int i = z;i >= 1;i--){
		if(x % i == 0 && y % i == 0){
			return i;
			break;
		}
	}
}
