/* 
 theBitRiddler
 5/8/2023
 8:52 AM
 Finacci Series
*/
#include <stdio.h>
/* #include <limits.h> */

#define MAX 46

int fibonacci( int );

int main( void ) {
	int loop = 0;
	
	for ( loop = 0; loop <= MAX; loop++ ) {
		printf( "Fibonacci( %d ) == %d\n", loop, fibonacci( loop ) );
		
	}
	/* printf( "%d\n", INT_MAX ); */
	
	return 0;	
}

int fibonacci( int n ) {
	int fib[ MAX ] = { 0 };
	fib[ 0 ] = 0;
	fib[ 1 ] = 1;
	
	for ( size_t i = 2; i <= n; i++ ) {
		fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ];
	}
	
	return fib[ n ];
	
}
