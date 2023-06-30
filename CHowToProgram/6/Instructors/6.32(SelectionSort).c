/* 
theBitRiddler
6/29/2023
5:34 PM
Selection Sort
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAXRANGE 1000

void selectionSort(int a[], size_t size );

int main( void ) {
    int array[ SIZE ] = { 0 };
    
    srand( time( NULL ));

    for ( size_t i = 0; i < SIZE; i++ ) {
        array[ i ] = 1 + rand() % MAXRANGE;
    } /* end for */

    printf_s( "%s", "\nUnsorted array\n");

    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%7d", array[ i ]);
    } /* end for */

    selectionSort( array, SIZE );

    printf_s( "%s", "\n\nSorted array\n");

    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%7d", array[ i ]);
    } /* end for */
    return 0;
} /* end main*/

void selectionSort( int a[], size_t size ) {
    int temp = 0;

    if ( size >= 1 ) {

        for ( size_t i = 0; i < size - 1; i++ ) {

            if ( a[ i ] < a[ 0 ]) {
                temp = a[ i ];
                a[ i ] = a[ 0 ];
                a[ 0 ] = temp;
            } /* end if */

        } /* end for */

        selectionSort( &a[ 1 ], size - 1);
    } /* end if */

} /* end function selectionSort */