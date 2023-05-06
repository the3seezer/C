/*
 theBitRiddler
 5/5/2023
 6:03 PM
 smallest of the three doubleing point values
*/
#include <stdio.h>

double smallest3( int a, int b, int c );

int main( void ) {
	double x = 0;
	double y = 0;
	double z = 0;
	
	printf( "%s", "Enter three doubleing point values: ");
	scanf( "%lf%lf%lf", &x, &y, &z );
	
	printf( "The smallest value is %f \n", smallest3( x, y, z ) );
	
}

double smallest3( int a, int b, int c ) {
	double smallest = a;
	
	if ( b < smallest ) {
		
		smallest = b;
		
	}
	
	if ( c < smallest ) {
		
		smallest = c;
		
	}
	
	return smallest;
	
}
 
