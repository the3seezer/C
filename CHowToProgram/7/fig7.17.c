/*
theBitRiddler
7/9/2023
9:25 PM

*/
#include <stdio.h>

#define SIZE 10

void bubbleSort( int work[], size_t size, int ( * compare )( int a, int b ) );
int ascending( int a, int b);
int descending(int a, int b );

int main( void ) {
    int a[ SIZE ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

    printf_s( "%s", "Enter 1 to sort in ascending order\n"
              "Enter 2 to sort in descending order: ");

    int order = 0;
    scanf_s( "%d", &order );

    puts( "Data items in original order");
    for ( size_t counter = 0; counter < SIZE; counter++ ) {
        printf_s( "%4d", a[ counter ]);
    } /* end for */

    if ( order == 1 ) {
        bubbleSort( a, SIZE, ascending );
        puts( "\nData items in asceding order");
    }
    else {
        bubbleSort( a, SIZE, descending );
        puts( "\nData items in descending order");
    }

    for ( size_t counter = 0; counter < SIZE; counter++ ) {
        printf_s( "%4d", a[ counter ] );
    } /* end for */

    return 0;

} /* end main */

void bubbleSort( int work[], size_t size, int ( * compare )( int a, int b ) ) {
    void swap( int * element1Ptr, int * element2Ptr );

    for ( int pass = 1; pass < size; pass++ ) {
        for ( size_t count = 0; count < size - 1; count++ ) {
            if ( (* compare )( work[ count ], work[ count + 1 ] ) ) {
                swap( &work[ count ], &work[ count + 1 ] );
            }
        }
    }
} /* end function bubbleSort */

int ascending( int a, int b ) {

    return a > b;

} /* end function ascending */

int descending( int a, int b ) {

    return a < b;

} /* end function asceding */

void swap( int *element1Ptr, int *element2Ptr ) {
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
} /* end function swap */