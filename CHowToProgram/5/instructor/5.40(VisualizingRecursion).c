/*
 theBitRiddler
 5/8/2023
 10:21 AM
 Visualizing Recursion
*/
#include <stdio.h>

long factorial( int );
void printRecursion( int );

int main( void ) {

    for ( int i = 0; i <= 10; i++ ) {

        printf( "%d! == %ld\n", i, factorial( i ) );

    } /* end for */
	
} /* end main */

long factorial( int n ) {

    if ( n <= 1 ) {
        return 1;
    } /* end if */
    else {
    
        printRecursion( n );
        return n * factorial( n - 1 );

    }

} /* end function factorial */

void printRecursion( int num ) {
    printf( "number == %*d\n", num, num );
}
