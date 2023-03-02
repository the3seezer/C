//theBitRiddler
//10-19-2022
//4:06pm
//recursive fibonacci
#include <stdio.h>

void fibonacci(int n);

int main(void){
	int numb = 0;
	puts("Enter a number of elements");
	scanf("%d",&numb);
	printf("%d %d",0,1);
	fibonacci(numb - 2);// - 2 b'se two elements are already printed 
}

void fibonacci(int n){
	static int n1 = 0,n2 = 1,n3 = 0;//assigning n3 is not required but for security 
	if(n > 0){
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		printf(" %d",n3);
		fibonacci(n - 1);
	}
}
