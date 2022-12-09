#include <stdio.h>

int square(int );//The variable name is not required but just for documentational purposes

int main(void){
	int x = 0;
	puts("Enter any integer");
	scanf("%d",&x);
	printf("%d squared to %d",x,square(x));
}

int square(int x){
	return x * x;
}
