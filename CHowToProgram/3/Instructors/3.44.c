/*
 theBitRiddler
 3/26/2023
 2:37 PM
 Triangle or Not triangle
*/
#include <stdio.h>
int main(void) {
	double a = 0;
	double b = 0;
	double c = 0;
	
	printf("%s", "Enter the three doubling point numbers ");
	scanf("%lf%lf%lf", &a, &b, &c);
	
	if (c * c == a * a + b * b) {
		printf("%s", "The three numbers could be sides of a triangle\n");
	}
	else {
		printf("%s", "The three numbers probability ");
		printf("%s", "are not the sides of a triangle\n");
	}
}