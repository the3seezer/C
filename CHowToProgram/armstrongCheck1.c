//theBitRiddler
//11/20/2022
//5:57pm
//check arm strong
#include <stdio.h>
#include <math.h>

int armSCheck(int);

int main(void){
	puts("Enter a three digit number");
	int n = 0;
	scanf("%d",&n);
	armSCheck(n);
}

int armSCheck(int num){
	int original = num,n = 0,result = 0;
	for(original = num;original != 0;++n){
		original /= 10;
	}
	for(original = num;original != 0;original /= 10){
		int rem = original % 10;
		result += pow(rem,n);
	}
	if(num == result){
		printf("%d is an armstrong",n);
	}
	else{
		printf("%d is not an armstrong",n);
	}
}
