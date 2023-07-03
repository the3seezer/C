/*
theBitRiddler
7/3/2023
10:27 AM
Putting values into an array, sorting the values into ascending order and printing
the resulting array.
*/
#include <stdio.h>

#define SIZE 10

void bubbleSort(int * const array, size_t size );

int main( void ) {
    int a[ SIZE ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

    printf_s( "%s", "Data items in original order \n");
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%4d", a[ i ]);
    } /* end for */
    
    puts("");

    bubbleSort( a, SIZE );

    printf_s( "%s", "Data items in sorted order \n");
    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%4d", a[ i ]);
    } /* end for */

    return 0;

} /* end main */

void bubbleSort( int *const array, size_t size ) {
    void swap( int * element1Ptr, int * element2Ptr ); // prototype for function swap

    for ( int pass = 1; pass < size; pass++ ) {
        for ( size_t i = 0; i < size - pass; i++ )
            
            swap( &array[ i ], &array[ i + 1]);

    } /* end for */
} /* end function bubbleSort */

void swap( int * element1Ptr, int * element2Ptr ) {
    // Compare adjacent elements
    if (*element1Ptr > *element2Ptr ) {
        int hold = *element1Ptr;
        * element1Ptr = * element2Ptr;
        * element2Ptr = hold;
    } /* end if */
} /* end function swap */