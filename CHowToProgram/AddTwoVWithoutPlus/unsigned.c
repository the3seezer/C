//theBitRiddler
//11/20/2022
//7:54am
/*Adding two numbers without addition operator
however this only works for positive integers */
#include <stdio.h>
#include <math.h>

int Add(int ,int);

int main(void){
	puts("Enter two numbers ");
	int num1 = 0,num2 = 0;
	scanf("%d%d",&num1,&num2);
	printf("Total: %d",Add(num1,num2));
}

int Add(int n,int m){
	/*if(m < 0 && n > 0){
		fabs(m);
		for(int i = 1;i >= m;i++){
			n--;
		}
		return n;
	}*/
	for(int i = 1;i <= m;i++){
		n++;
	}
	return n;
}
