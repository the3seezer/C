/*
theBitRiddler
7/3/2023
12:29 PM
Finding the number of elements of an Array using the sizeof operator
*/
#include <stdio.h>

#define SIZE 22 

int main( void ) {
    double real[ SIZE ] = { 0 };

    printf_s( "The number of elements of real is %zu\n", sizeof( real ) / sizeof( real[ 0 ] ) );

    return 0;
} /* end main */