#include <stdio.h>

int sum(int);

int main(void){
	printf("%d\n",sum(10));
}

int sum(int x){
	if(x == 0){
		return x;
	}
	else{
		return x + sum(x - 1);
	}
}
