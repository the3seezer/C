/* 
 theBitRiddler
 5/14/2023
 10:19 AM
 Exercise 6.8
*/
#include <stdio.h>

#define SIZE 26

void printHeader( void );
void printArray( const float a[] );

int main( void ) {
    /* 6.8(a) */
    char f[ SIZE ] = {};
    char a = 'A';
    printHeader();

    for ( size_t i = 0; i < SIZE; i++ ) { 
        printf_s( "%3c ",  f[ i ] = a );
        a += 1;
    } /* end for */

    printf_s( "\n6.8(a): %c\nEnter an integer: \n?", f[ 6 ] );

    /* 6.8(b) */
    float b[ SIZE ] = {0};
    scanf_s( "%f", &b[ 3 ] );
    printf_s( "\n6.8(b): %.2f\n", b[ 3 ] );

    /* 6.8(c) */
    int g[ 5 ] = {0};
    for ( size_t i = 0; i < 5; i++ ) 
        g[ i ] = 8;
    printf_s( "%s", "6.8(c):   " );
    for ( size_t i = 0; i < 5; i++ )
        printf_s( "%2d", g[ i ] );
    puts("");

    /* 6.8(d) */
    float c[ 100 ] = {0};
    for ( size_t i = 0; i < 100; i++ )
        c[ i ] = i * 2;
    int sum = 0;
    for ( size_t i = 0; i < 100; i++ )
        sum += c[ i ];
    printf_s( "6.8(d): total %d\n", sum );

    /* 6.8(e) */
    int d[ 11 ] = {0};
    for ( size_t i = 0; i < 11; i++ )
        d[ i ] = i * 2;
    int e[ 34 ] = {0};
    for ( size_t i = 0; i < 34; i++ )
        e[ i ] = 100;
    for ( size_t i = 0; i < 11; i++ )
        e[ i ] = d[ i ];
    printf_s( "%s", "6.8(e):  " );
    for ( size_t i = 0; i < 34; i++ )
        printf_s( "%4d", e[ i ] );
    puts("");

    /* 6.8(f) */
    // int smallest = 200,largest = 0,w[ 0 ] = {0}; //or w[ 99 ] = {0};
    int smallest = 30,largest = 0;
    int w[ 99 ] = {  7, 8, 9, 8, 7, 8, 9, 8, 9,
                 7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
                 6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
                 7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
                 6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
                 7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
                 5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
                 7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
                 7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
                 4, 5, 6, 1, 6, 5, 7, 8, 7, 9 };


    for ( size_t i = 0; i <= 98; i++ )
        printf_s( "%4d", w[ i ] );
    puts("");
    for ( size_t i = 0; i <= 98; i++ )
        if ( w[ i ] > largest )
            largest = w[ i ];
        else if ( w[ i ] < smallest )
            smallest = w[ i ];

    printf_s( "6.8(f):   \nThe smallest is %d\nThe largest is %d\n", smallest, largest );

} /* end main */

void printArray( const float a[] ) {
    for ( size_t i = 0; i < 100; i++ )
        printf_s( "%d", a[ i ] );
} /* end function printArray */

void printHeader( void ) {
    for ( int i = 0; i < SIZE; i++ )
        printf_s( "%3d ", i );
    puts("");
} /* end function printHeader */