/* 
 theBitRiddler
 5/1/2023
 9:53 AM
 Rounding the decimal places
*/
#include <stdio.h>
#include <math.h>

double roundToInteger( double n );
double roundToTenths( double n );
double roundToHundredths( double n );
double roundToThousands( double n );

int main(void) {
	int i = 0;
	int count = 0;
	double number = 0;
	
	printf("%s", "How many number do you want to process? ");
	scanf("%d", &count);
	
	for (i = 0; i < count; i++) {
		
		printf("%s", "Enter a number: ");
		scanf("%lf", &number);
		
		printf("%f rounded to integer is %f\n",
		 number, roundToInteger( number ) );
		 
		printf("%f rounded to tenths is  %f\n",
		 number, roundToTenths( number ) );
		 
		printf("%f rounded to hundredths is %f\n",
		 number, roundToHundredths( number ) );
		 
		printf("%f rounded to thousands is %f\n\n",
		 number, roundToThousands( number ) );
		
	} /* end for */
		
} /* end main */

double roundToInteger( double n ) {
	
	return floor(n + .5);
	
} /* end roundTointeger */

double roundToTenths( double n ) {
	
	return floor( n * 10 + .5 ) / 10;
	
} /* end roundToTenths */

double roundToHundredths( double n ) {
	
	return floor( n * 100 + .5 ) / 100;
	
}

double roundToThousands( double n ) {
	
	return floor( n * 1000 + .5 ) / 1000;
	
}


