/* 
theBitRiddler
7/1/2023
8:45 AM
Print an Array
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printArray( int a[], size_t low, size_t high );

int main( void ) {
    srand( time( NULL ) );
    int array[ SIZE ] = { 0 };

    for ( size_t i = 0; i < SIZE; i++ ) {
        array[ i ] = 1 + rand() % 1000;
    } /* end for */

    printf_s( "%s", "Array printed in main\n");
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%7d", array[ i ]);
    } /* end for */

    printf_s( "%s", "\nArray printed in printArray\n");
    printArray( array, 0, SIZE - 1 );

    return 0;
} /* end main */

void printArray( int a[], size_t low, size_t high ) {
    
    printf_s( "%7d", a[ low ]);

    if ( low == high ) {
        return;
    } /* end if */
    else {
        printArray( a, low + 1, high );
    } /* end else */
} /* end function printArray */