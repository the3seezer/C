//theBitRiddler
//11/20/2022
//5:14pm
//Armstrong Check for three digit integers
#include <stdio.h>

int armSCheck(int);

int main(void){
	puts("Enter a three digit number");
	int n = 0;
	scanf("%d",&n);
	armSCheck(n);
}

int armSCheck(int n){
	int original = n,result = 0;
	while(original != 0){
		int rem = original % 10;
		result += rem * rem * rem;
		original /= 10;
	}
	
	if(n == result){
		printf("%d is an armstrong",n);
	}
	else{
		printf("%d is not an armstrong",n);
	}
}
