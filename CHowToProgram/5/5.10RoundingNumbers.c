//theBitRiddler
//9/25/2022
//2:21pm
//Rounding numbers to nearest integer
#include <stdio.h>
#include <math.h>

int main(void){
	double x = 0;
	puts("Enter any decimal value or -1 to end");
	scanf("%lf",&x);
	while(x != -1){
		int y = floor(x + .5);
		printf("Original:%f Rounded:%d\n",x,y);
		puts("Enter any decimal value or -1 to end");
		scanf("%lf",&x);
	}
}
