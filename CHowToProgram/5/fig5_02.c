#include <stdio.h>

int maximum(int x,int y,int z);

int main(void){
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	puts("Enter three integers");
	scanf("%d%d%d",&num1,&num2,&num3);
	printf("MAXIMUM:%d", maximum(num1,num2,num3));
}

int maximum(int x,int y,int z){
	if(x > y && x > z){
		return x;
	}
	if(y > x && y > z){
		return y;
	}
	if(z > x && z > y){
		return z;
	}
}
