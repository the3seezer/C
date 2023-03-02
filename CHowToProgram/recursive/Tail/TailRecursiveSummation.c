//theBitRiddler
//11/18/2022
//10:36am
//Tail Recursive Summation of numbers
#include <stdio.h>

int tailSum(int ,int);

int main(void){
	puts("Enter any number to find sum of its individuals");
	int num = 0;
	scanf("%d",&num);
	int a = 0;
	printf("Summation: %d\n",tailSum(num,a));
}

int tailSum(int n,int a){
	if(n == 0){
		return a;	
	} 
	else{
		return tailSum(n - 1,a + n);
	}
}
