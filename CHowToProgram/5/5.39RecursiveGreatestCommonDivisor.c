//theBitRiddler
//11-10-2022
//8:32am
//recursive Greatest Common Divisor 
#include <stdio.h>

unsigned long long int gcd(int ,int);

int main(void){
	puts("Enter two integers to find the greatest common divisor");
	int x = 0,y = 0;
	scanf("%d%d",&x,&y);
	printf("The Greatest Common Divisor:%llu\n",gcd(x,y));
}

unsigned long long int gcd(int x,int y){
	if(y == 0){
		return x;
	}
	else{
		return gcd(y,x % y);
	}
}
