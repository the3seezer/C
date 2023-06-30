/*
theBitRiddler
6/30/2023
10:50
Linear Search
*/
#include <stdio.h>

#define SIZE 100

int linearSearch( int array[], int key, size_t low, size_t high);

int main( void ) {
    int a[ SIZE ] = { 0 };
    int searchKey = 0;
    int element = 0;

    for ( size_t loop = 0; loop < SIZE; loop++ ) {
        a[ loop ] = loop * 2;
    } /* end for */

    printf_s( "%s", "Enter search key\n" );
    scanf_s( "%d", &searchKey );

    element = linearSearch( a, searchKey, 0, SIZE - 1 );

    if ( element != -1 ) {
        printf_s( "Value found at subscript %d\n", element );
    } /* end if */
    else {
        printf_s( "Value not found \n");
    } /* end else */
    
    return 0;
} /* end main*/

int linearSearch( int array[], int key, size_t low, size_t high ) {
    if ( array[ low ] == key ) {
        return low;
    }
    else if ( low == high ) {
        return -1;
    }
    else {
        return linearSearch( array, key, low + 1, high );
    }
}