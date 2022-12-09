//theBitRiddler
//10-1-2022
//10:53pm
//Separating Digits
#include <stdio.h>
#include <math.h>

int quotient(int ,int );
//int remainder(int ,int );Avoid reinventing the wheel
int separate(int);

int main(void){
	int a = 0;
	int b = 0;
	puts("Enter the value of 'a' and 'b'");
	scanf("%d%d",&a,&b);
	int q = quotient(a,b);//quotient
	printf("Quotient:%dseparated:",q);
	separate(q);//separated
	int r = fmod(a,b);//remainder
	printf("Remainder:%d\tSeparated:",r);
	separate(r);//separate
}

int quotient(int x,int y){
	return x * y;
}

int separate(int x){
	int newN = 0;
	while(x){//number
		int rem = x % 10;//remainder
		newN = 10 * newN + rem;
		x /= 10;
	}
	while(newN){
		int rem = newN % 10;
		printf("%d  ",rem);
		newN /= 10;
	}
	printf("%s","\n");
}
