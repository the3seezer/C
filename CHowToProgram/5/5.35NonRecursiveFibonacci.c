//theBitRiddler
//10-19-2022
//3:41pm
//Non recursive fibonacci
#include <stdio.h>

unsigned long long int fibonacci(int);

int main(void){
	int num = 0;
	puts("Enter the number of fibonacci elements");
	scanf("%d",&num);
	fibonacci(num);
}

unsigned long long int fibonacci(int x){
	int n1 = 0;
	int n2 = 1;
	int n3 = 0;//assigning n3 is not required in program but its for security
	printf("%d %d",n1,n2);
	for(int i = 2;i < x;i++){//loop start with 2 b'se 0 and 1 are already printed
		n3 = n1 + n2;
		printf(" %d",n3);
		n1 = n2;
		n2 = n3;
	}
}
