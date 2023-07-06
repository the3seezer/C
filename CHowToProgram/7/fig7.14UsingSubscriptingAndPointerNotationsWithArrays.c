/*
theBitRiddler
7/6/2023
8:47 PM 
*/
#include <stdio.h>

#define ARRAY_SIZE 4

int main( void ) {
    int b[ ARRAY_SIZE ] = { 10, 20, 30, 40 };
    int * bPtr = b;

    printf_s( "%s", "Array b printed with:\nArray subscript notation\n");

    for ( size_t i = 0; i < ARRAY_SIZE; i++ ) {
        printf_s( "b[ %zu ] = %5d\n", i, b[ i ]);
    } /* end for */

    puts( "\nPointer/offset notation where the pointer is the array name");

    for ( size_t i = 0; i < ARRAY_SIZE; i++ ) {
        printf_s( "* ( b + %zu ) = %5d\n", i, * ( b + i ) );
    } /* end for */

    puts( "\nPointer subscript notation");

    for ( size_t i = 0; i < ARRAY_SIZE; i++ ) {
        printf_s( " bPtr[ %zu ] = %5d\n", i, bPtr[ i ]);
    } /* end for */

    puts( "\nPointer/offset notation" );

    for ( size_t i = 0; i < ARRAY_SIZE; i++ ) {
        printf_s( " * ( bPtr + %zu ) = %5d\n", i, * ( bPtr + i ) );
    } /* end for */

    return 0;
} /* end main*/