//theBitRiddler
//11/20/2022
//9:24am
//Adding two number withot plus operator using substraction
#include <stdio.h>

int Add(int ,int);

int main(void){
	puts("Enter Two values");
	int a = 0,b = 0;
	scanf("%d%d",&a,&b);
	printf("Total:%d\n",Add(a,b));
}

int Add(int a,int b){
	return a - (-b);
}
