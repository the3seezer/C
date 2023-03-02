//theBitRiddler
//24/9/2022
//9:00am
//math functions
#include <stdio.h>
#include <math.h>

int main(void){
	double x = 0;
	x = fabs(7.5);
	printf("a: %f\n",x);
	x = floor(7.5);
	printf("b %f\n",x);
	x = fabs(0.0);
	printf("c: %f\n",x);
	x = ceil(0.0);
	printf("d: %f\n",x);
	x = fabs(-6.4);
	printf("e: %f\n",x);
	x = ceil(-6.4);
	printf("f: %f\n",x);
	x = ceil(-fabs(-8 + floor(-5.5)));
	printf("g: %f\n",x);
}
