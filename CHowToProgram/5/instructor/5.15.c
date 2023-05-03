/* 
 theBitRiddler
 5/3/2023
 4:34 PM
 hypotenuse of a right angled triangle
*/
#include <stdio.h>
#include <math.h>

double hypotenuse( double, double );

int main( void ) {
	int i = 0;
	double side1 = 0;
	double side2 = 0;
	
	for ( i = 1; i <= 3; i++ ) {
		printf("%s", "Enter the sides of the triangle: ");
		scanf("%lf%lf", &side1, &side2 );
		
		printf("Hypotenuse : %.4f\n", hypotenuse( side1, side2 ) );
		
	}
		
}

double hypotenuse(double s1, double s2) {
	
	return sqrt( pow( s1, 2 ) + pow( s2, 2 ) );
	
}
