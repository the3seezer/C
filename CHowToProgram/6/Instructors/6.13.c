/* 
 theBitRiddler
 5/15/2023
 12:28 PM
 Correct errors
*/
#include <stdio.h>
int main( void ) {
    /* 6.13(a)
     char str[ 5 ]; 
     scanf( "%s", str );
     ANS:  str needs a minimum length of 6; one element for each letter in hello and an element for the terminating NULL
     character.*/
    char str[ 6 ] = {'0'};
    scanf_s( "%s", str ); // Enter hello
    printf_s( "%s", str );
    puts("");
    /* 6.13( b ):
     Assume: int a[ 3 ];
     printf( "$d %d %d\n", a[ 1 ], a[ 2 ], a[ 3 ] ); */
    int a[ 3 ] = { 1, 2, 3 };
    printf_s( "%d %d %d\n", a[ 0 ], a[ 1 ], a[ 2 ] );

    /* 6.13( c ):
    ) double f[ 3 ] = { 1.1, 10.01, 100.001, 1000.0001 };
    ANS: Too many variables defined.
    double f[ 3 ] = { 1.1, 10.01, 100.01 };*/

    /* 6.13( d ):
    Assume: double d[ 2 ][ 10 ]; 
    d[ 1, 9 ] = 2.345;*/
    double d[ 2 ][ 10] = { 0.0 };
    d[ 1 ][ 9 ] = 2.345;

}