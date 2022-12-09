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
		int p = prime(i);
		if(p == 0){
			continue;
		}
		printf("Prime:%d\n",p);
	}
}

int prime(int x){
	static int z = 0;
	for(int i = 1;i < x;i++){
		if(i == x || i == 1){
			continue;
		}
		else if(x % i == 0){
			if(i > z){
				return z;
			}
			else{
				return i;
			}
		}
	}
}
