//theBitRiddler
//9-25-2022
//3:05pm
//rounding x to various ways
#include <stdio.h>
#include <math.h>

int roundToInteger(double);
double roundToTenths(double);
double roundToHundreths(double);
double roundToThousandths(double);

int main(void){
	double x = 0;
	puts("Enter any decimal number or -1 to end");
	scanf("%lf",&x);
	while(x != -1){
		printf("Original:%f\troundToInteger:%d\troundToTenths:%f\troundToHundreths:%f\troundToThousandths:%f\n",x,roundToInteger(x),roundToTenths(x),roundToHundreths(x),roundToThousandths(x));
		puts("Enter any decimal number or -1 to end");
		scanf("%lf",&x);
	}
}

int roundToInteger(double x){
	return floor(x + .5);
}
double roundToTenths(double x){
	return floor(x * 10 + .5) / 10;
}
double roundToHundreths(double x){
	return floor(x * 100 + .5) / 100;
}
double roundToThousandths(double x){
	return floor(x * 1000 + .5) / 1000;
}

