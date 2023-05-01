/* 
 theBitRiddler
 5/1/2023
 9:35 AM
 Rounding off to the nearest integer
*/
#include <stdio.h>
#include <math.h>

void calculateFloor(void);

int main (void) {
	
	calculateFloor();
	
} /* end main */

void calculateFloor(void) {
	double x = 0;
	double y = 0;
	int i = 0;
	
	for (i = 1; i <= 5; i++) {
		
		printf("%s", "Enter a floating point number: ");
		scanf("%lf", &x);
		
		/* round off the number to nearest integer */
		y = floor( x + .5);
		printf("%f rounded is %.1f\n\n", x, y);
		
	} /* end for */
		
} /* end calculateFloor */
