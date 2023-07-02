/*
theBitRiddler
7/2/2023
11:45 AM
Cube a variable using pass-by-value
*/
#include <stdio.h>

int cubeByValue( int n );

int main( void ) {
    int number = 5;

    printf_s( "The original value of number is %d\n", number );
    number = cubeByValue( number );
    printf_s( "The new value of number is %d\n", number );
    
} /* end main */

int cubeByValue( int n ) {
    return n * n * n;
} /* end function cubeByValue */