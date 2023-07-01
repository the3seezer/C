/* 
theBitRiddler
7/1/2023
9:40 AM
(Find the Minimum Value in an Array) 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int recursiveMinimum( int a[], size_t low, size_t high );

int main( void ) {
    int array[ SIZE ] = { 0 };

    srand( time( NULL ));

    for ( size_t i = 0; i < SIZE; i++ ) {
        array[ i ] = 1 + rand() % 100;
    } /* end for */

    printf_s( "%s", "Elements in the array\n");
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%5d", array[ i ]);
    } /* end for */

    printf_s( "\n\nThe smallest element is %d\n", recursiveMinimum(array, 0, SIZE - 1));

    return 0;
} /* end main */

int recursiveMinimum( int a[], size_t low, size_t high ) {
    static int smallest = 101;
    if ( low == high ) {
        return smallest;
    } /* end if */
    else if ( a[ low ] < smallest) {
        smallest = a[ low ];
    } /* end else if */

    return recursiveMinimum( a, low + 1, high );

} /* end function recursiveMinimum */

