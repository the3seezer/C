#include <stdio.h>

#define SIZE 10

void bubbleSort( int const * array, size_t size );

int main( void ) {
    int a[ SIZE ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

    puts( "Elements in original order" );
    for ( size_t i = 0; i < SIZE; i++ )
        printf_s( "%4d", a[ i ]);

    bubbleSort( a, SIZE );

    puts( "\nElements in ascending order\n" );
    for ( size_t i = 0; i < SIZE; i++ )
        printf_s( "%4d", a[ i ]);

    return 0;

} /* end main */

void bubbleSort( int const * array, size_t size ) {
    void swap( int * firstPtr, int * secondPtr );

    for ( int pass = 1; pass < size; pass++ )
        for ( size_t i = 0; i < size - pass; i++ )
            if ( array[ i ] > array[ i + 1 ])
                swap( &array[ i ], &array[ i + 1 ]);


} /* end function bubbleSort */

void swap( int * firstPtr, int * secondPtr ) {
    int temp = * firstPtr;
    * firstPtr = * secondPtr;
    * secondPtr = temp;
} /* end function swap */