/*
 theBitRiddler
 5/18/2023
 5:07 PM
 WHAT does it do?
*/
#include <stdio.h>

#define SIZE 10
int total( const int b[], size_t p );

int main( void ) {
    int x = 0;
    int a[ SIZE ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    x = total( a, SIZE );

    printf_s( "The result is %d\n", x );

    return 0;
}

int total( const int b[], size_t p ) {
    if ( p == 1 ) {
        return b[ 0 ];
    }
    else {
        return b[ p - 1 ] + total( b, p - 1 );
    }
}