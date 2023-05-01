/* 
 theBitRiddler
 4/30/2023
 7:47 PM
 
*/
#include <stdio.h>
#include <math.h>

double calculateCharges(double hours);

int main(void) {
	double h = 0;
	double currentCharge = 0;
	double totalCharges = 0;
	double totalHours = 0;
	int i = 0;
	int first = 1;
	
	printf("Enter the hours packed for three cars: ");
	
	for (i = 1; i <= 3; ++i) {
		
		scanf("%lf", &h);
		
		totalHours += h;
		
		if (first == 1) {
			
			printf("%5s%15s%15s\n", "Cars", "Hours", "currentCharge");
			
			first = 0;
			
		} /* end if */
		
		totalCharges += ( currentCharge = calculateCharges( h ));
		
		printf("%5d%15.1f%15.2f\n", i, h, currentCharge);
		
	} /* end for loop */
	
	printf("%5s%15.1f%15.2f\n", "TOTAL", totalHours, totalCharges);
	
} /* end main */

double calculateCharges( double hours) {
	
	double charge = 0;
	
	if (hours < 3) {
		
		charge = 2.0; 
		
	}
	
	
	else if ( hours < 19 ) {
		
		charge = 2.0 + .5 * ceil( hours - 3);
		
	}
	
	else {
		
		charge = 10.0;
		
	}
	
	return charge;
	
} /* end calculateCharges */


