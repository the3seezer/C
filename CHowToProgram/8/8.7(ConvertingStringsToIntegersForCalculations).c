/*
 theBitRiddler
 1/22/2024
 5:19 PM
 8.7 (Converting Strings to Integers for Calculations) 
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
int main( void ) {
    long int a = 0, b = 0, c = 0, d = 0; // The integers
    char * aPtr = NULL, *bPtr = NULL, *cPtr = NULL, *dPtr = NULL; // The end pointers
    char aStr[SIZE] = "", bStr[SIZE] = "", cStr[SIZE] = "", dStr[SIZE] = ""; // The strings

    puts("Enter four strings representing integers" );

    scanf( "%s%s%s%s", aStr, bStr, cStr, dStr );
    
    a = strtol( aStr, &aPtr, 0 );
    b = strtol( bStr, &bPtr, 0 );
    c = strtol( cStr, &cPtr, 0 );
    d = strtol( dStr, &dPtr, 0 );

    printf( "The sum of the integers is %ld\n", a + b + c + d );

    return 0;

} /* end main */