/*
theBitRiddler
7/8/2023
9:02 PM
Multipurpose sorting program using function pointers.
*/
#include <stdio.h>

#define SIZE 10

void bubbleSort( int work[], size_t size, int * ( compare)( int a, int b ) );
int ascending( int a, int b );
int descending( int a, int b );

int main( void ) {
    int a[ SIZE ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

    puts( "Array in original order ");

    for ( size_t i = 0; i < SIZE; i++ )
        printf_s( "%4d", a[ i ] );

    printf_s( "%s", "\n\nEnter 1 to sort in ascending order and \n 2 to sort descending order\n");
    int order = 0; 
    scanf_s( "%d", &order );

    if ( order == 1 )
        bubbleSort( a, SIZE, ascending );
    else
        bubbleSort( a, SIZE, descending);

    puts( "\nArray in sorted order ");

    for ( size_t i = 0; i < SIZE; i++ )
        printf_s( "%4d", a[ i ] );

    return 0;

} /* end main */

void bubbleSort( int work[], size_t size, int * (compare)( int a, int b ) ) {
    void swap( int *element1, int *element2 );

    for ( int pass = 1; pass < size; pass++ ) {
        for ( size_t counter = 0; counter < size - 1; counter++ ) {
            if ( (*compare)( work[counter], work[ counter + 1 ] ) ) {

                swap( &work[ counter ], &work[ counter + 1 ] );

            } /* end if */
        } /* end for */
    } /* end for */

} /* end function bubbleSort */

void swap( int *element1, int * element2 ) {
    int hold = *element1;
    *element1 = *element2;
    *element2 = hold;
} /* end function swap */

int ascending( int a, int b ) {

    return b < a;

} /* end function ascending */

int descending( int a, int b ) {

    return b > a;

} /* end function ascending */