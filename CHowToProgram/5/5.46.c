//theBitRiddler
//11-12-2022
//5:20pm
//Testing some program
#include <stdio.h>
#include <stdlib.h>

double cube(float);
double square(double);
int sum(int);

int main(void){
	puts("(a)");
	puts("Enter any number");
	int a = 0;
	scanf("%d",&a);
	printf("cube %lf\n",cube(a));
	puts("\n(b)");
	int  randomNumber = rand();
	printf("random %d\n",randomNumber);
	puts("\n(c)");
	double y = 123.45678;
	/*int*/double x;
	x = y;
	printf("%f\n", (double)x);
	puts("\n(d)");
	printf("square %f\n",square(a));
	puts("\n(e)");
	puts("Enter any number to get sum by individual decrement");
	int b = 0;
	scanf("%d",&b);
	printf("sum %d\n",sum(b));
}

double cube(float number){
	return number * number * number;
}

double square(double number){
	/*double number;*/
	return number * number;
}

int sum(int n){
	if(n == 0){
		return 0;
	}
	else{
		return n + sum(n - 1);/*sum(n)*/
	}
}
