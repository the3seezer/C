//theBitRiddler
//11/20/2022
//9:24am
//Adding two number withot plus operator using half adder logic
#include <stdio.h>

int Add(int ,int);

int main(void){
	puts("Enter Two values");
	int a = 0,b = 0;
	scanf("%d%d",&a,&b);
	printf("Total:%d\n",Add(a,b));
}

int Add(int a,int b){
	if(!b){
		return a;
	}
	
	int sum = a ^ b;
	int carry = (a & b) << 1;
	
	return Add(sum, carry);
}
