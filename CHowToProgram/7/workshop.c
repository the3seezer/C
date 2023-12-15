#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void quicksort( int * array, int first, int last );
int partition( int * array, int left, int right );
void swap( int * ptr1, int * ptr2 );
int main( void ) {
    int array[ MAX ] = { 0 };
    srand( time( NULL ) );

    for ( size_t i = 0; i < MAX; i++ ) {
        array[ i ] = rand() % 1000;
    } // end for

    printf_s( "%s", "Initial array elements \n" );

    for ( size_t i = 0; i < MAX; i++ ) {
        printf_s( "%4d", array[ i ] );
    } // end for

    printf_s( "%s", "\n\n" );

    if ( MAX == 1 ) {
        printf_s( "This array is sorted %d\n", array[ 0 ] );
    } // end if
    else {
        quicksort( array, 0, MAX - 1 );

        printf_s( "%s", "Sorted array elements are :\n " );

        for ( size_t i = 0; i < MAX; i++ ) {
            printf_s( "%4d", array[ i ] );
        } // end for
    } // end else
    return 0;

} /* end main */

void quicksort( int * array, int first, int last ) {
    int currentPosition = 0;

    if ( first >= last ) {
        return;
    } // end if

    currentPosition = partition( array, first, last );
    quicksort( array, first, currentPosition - 1 );
    quicksort( array, currentPosition + 1, last );

} /* end function quicksort */

int partition( int * array, int left, int right ) {
    int position = left;

    while ( 1 ) {

        while ( array[ position ] <= array[ right ] && position != right ) {
            --right;
        } // end while

        if ( position == right ) {
            return position;
        } // end if

        if ( array[ position ] > array[ right ]) {
            swap( &array[ position ], &array[ right ] );
            position = right;
        } // end if

        while ( array[ left ] <= array[ position ] && position != left ) {
            ++left;
        } // end while

        if ( position == left ) {
            return position;
        } // end if

        if ( array[ left ] > array[ position ] ) {
            swap( &array[ left ], &array[ position ]);
            position = left;
        } // end if

    } // end while

} /* end function partition */

void swap( int * ptr1, int * ptr2 ) {
    int temp = 0;
    temp = * ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
} /* end function swap */