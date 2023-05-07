/* 
 theBitRiddler
 5/3/2023
 7:18 pm
 workshop
*/
#include <stdio.h>

/*  ARRAYS
 Are groug of variables of the same data type according to c language.
 examples of data types are: int %d, char %c or %s, float %f, double %lf then %f long double %Lf then %lf
 VARIABLE 
 IS a structure which stores a single value 
 synthax: date type (variable name) = value
 array synthax; data type array name [];*/ 
int power( int, int );
 
int main( void ) {
	int x = 1;
	int y = 0;
	 //array declared 
	printf( "%s", "Enter the base and the exponent. ");
	scanf( "%d%d", &x, &y );
	printf( "%d", power( x, y ) );
}

int power( int b, int e ) {
	if ( e == 1 ) {
		return b;
	}
	else {
		b *= power( b, e - 1);
	}
}
