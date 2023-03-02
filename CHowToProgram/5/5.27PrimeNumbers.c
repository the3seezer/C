//theBitRiddler
//10-11-2022
//6:07pm
/*
Prime Numbers
with n used as n/2 range of divisors
*/
#include <stdio.h>

int prime(int);

int main(void){
	int n = 0;
	puts("Enter a number to find a range of prime numbers");
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		prime(i);
	} 
}

int prime(int x){
	int m = x/2;
	int flag = 0;
	int i = 2;//n = 0;
	for(i = 2;i <= m;i++){
		if((x % i) == 0){
			flag = 1;
			break;
		}
	}
	if(flag == 1 || x == 1){
		//printf("%d is not a prme number\n",x);
	}
	else{
		printf("%d\n",x);
	}
}
