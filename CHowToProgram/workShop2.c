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
		printf("Prime:%d\n",p);
	}
}

int prime(int x){
	for(int i = 1;i < x;i++){
		if(i == x || i == 1){
			continue;
		}
		else if(x % i == 0){
			static int y = 0;
			return i;
			/*y += i;
			if(i > y){
				return i;
			} */
		}
	}
}
