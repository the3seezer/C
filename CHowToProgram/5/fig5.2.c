#include <stdio.h>

int maximum(int x,int y,int z);

int main(void){
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	puts("Enter three integers");
	scanf("%d%d%d",&num1,&num2,&num3);
	printf("MAXIMUM:%d\n", maximum(num1,num2,num3));
}

int maximum(int x,int y,int z){
	int max = x;
	if(y > max){
		max = y;
	}
	if(z > max){
		max = z;
	}
	return max;
}
