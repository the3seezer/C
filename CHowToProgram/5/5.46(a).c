//theBitRiddler
//11-12-2022
//5:20pm
//Testing some program
#include <stdio.h>

double cube(float);

int main(void){
	puts("Enter any number");
	int a = 0;
	scanf("%d",&a);
	printf("cube %lf\n",cube(a));
}

double cube(float number){
	return number * number * number;
}
