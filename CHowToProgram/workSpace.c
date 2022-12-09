//theBitRiddler
//10-11-2022
//6:07pm
/*
Prime Numbers
*/
#include <stdio.h>

int prime(int);

int main(void){
	int n = 0;
	puts("Enter 10,000 to find prime numbers");
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		prime(i);
	}
}

int prime(int x){
	for(int y = 1;y <= x;y++){
		if(y == x || y == 1){
			continue;
		}
		if(x % y != 0){
			printf("%d\t",x);
		}
	}
	puts("");
}
