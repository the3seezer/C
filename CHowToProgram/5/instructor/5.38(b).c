/* 
 theBitRiddler
 5/8/2023
 9:15 AM
 Fibonacci with double data type
*/
#include <stdio.h>
#define SIZE 100  /* between 100000 and 1000000 */

double fibonacci( int n );

int main( void ) {
	
	for ( int loop = 0; loop <= SIZE; loop++ ) {
		printf( "Fibonacci( %d ) == %.1f\n", loop, fibonacci( loop ) );
	} /* end for */
	return 0;
	
} /* end main */

double fibonacci( int n ) {
	double fib[ SIZE ] = { 0 };
	fib[ 0 ] = 0.0;
	fib[ 1 ] = 1.0;
	
	for ( size_t i = 2; i <= n; i++ ) {
		fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ];
	}
	
	return fib[ n ];
	
} /* end function fibonacci */
