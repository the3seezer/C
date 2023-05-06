/* 
 theBitRiddler
 5/5/2023
 5:25 PM
 Fahreinheit and Celcius
*/
#include <stdio.h>

int celcius( int );
int fahrenheit( int );

int main( void ) {
	
	printf( "%s", "Fahrenheit equivalents of celcius temperatures: \n");
	printf( "%s\t\t%s\n", "Celcius", "Fahreinheit" );
	
	for ( int i = 0; i <= 100; i++ ) {
		
		printf( "%d\t\t%d\n", i, fahrenheit( i ) );
		
	}
	
	printf( "\n\n%s", "Celcius equivalents of fahrenheit temperatures: \n");
	printf( "%s\t\t%s\n", "Fahreinheit", "Celcius" );
	
	for ( int i = 32; i <= 212; i++ ) {
		
		printf( "%d\t\t\t%d\n", i, celcius( i ) );
		
	}
	
}

int  fahrenheit( int cTemp ) {
	
	return ( int ) ( 9.0 / 5.0 * cTemp + 32 );
	
}

int celcius( int fTemp ) {
	
	return ( int ) ( 5.0 / 9.0 * ( fTemp - 32 ) );
	
}
