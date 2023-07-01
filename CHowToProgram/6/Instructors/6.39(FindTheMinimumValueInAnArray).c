/*
theBitRiddler
7/1/2023
10:14 AM
(Find the Minimum Value in an Array) 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAXRANGE 1000

int recursiveMinimum( int a[], size_t low, size_t high );

int main( void) {
    int array[ SIZE ] = { 0 };
    int smallest = 0;
    srand( time( NULL));

    for (size_t i = 0; i < SIZE; i++ ) {
        array[ i ] = 1 + rand() % MAXRANGE;
    } /* end for */

    printf_s( "Here are array elements: \n");
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%7d", array[ i ]);
    } /* end for */

    smallest = recursiveMinimum( array, 0, SIZE - 1);
    printf_s( "\nThe smallest value is %d\n", smallest );

    return 0;
} /* end main */

int recursiveMinimum(int a[], size_t low, size_t high ) {
    static int smallest = MAXRANGE;

    if ( a[ low ] < smallest ) {
        smallest = a[ low ];
    } /* end if */
    

    if ( low == high ) {
        return smallest;
    } /* end if */
    else {
        return recursiveMinimum( a, low + 1, high );
    } /* end else */
} /* end function recursiveMinimum */