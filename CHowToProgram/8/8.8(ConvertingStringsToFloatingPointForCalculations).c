/*
    theBitRiddler
    1/22/2024
    5:47 PM
    8.8 (Converting Strings to Floating Point for Calculations) 
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
int main( void ) {
    double a = 0, b = 0, c = 0, d = 0; // The numbers
    char * aPtr = NULL, *bPtr = NULL, *cPtr = NULL, *dPtr = NULL; // The pointers
    char aStr[SIZE] = "", bStr[SIZE] = "", cStr[SIZE] = "", dStr[SIZE] = "";

    puts( "Enter four strings representing doubles" );

    scanf( "%s%s%s%s", aStr, bStr, cStr, dStr );

    a = strtod( aStr, &aPtr );
    b = strtod( bStr, &bPtr );
    c = strtod( cStr, &cPtr );
    d = strtod( dStr, &dPtr );

    printf( "The sum of the doubles is = %.4f", a + b + c + d );

    return 0;

} /* end main */