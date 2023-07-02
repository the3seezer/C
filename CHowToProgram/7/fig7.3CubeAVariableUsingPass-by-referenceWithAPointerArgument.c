/*
theBitRiddler
7/2/2023
11:56 AM
Cube a variable using pass-by-reference with a pointer argument.
*/
#include <stdio.h>

void cubeByReference( int *nPtr );

int main( void ) {
    int number = 5;

    printf_s( "The original value of number is %d\n", number );
    cubeByReference( &number );
    printf_s( "The new value of number is %d\n", number );

    return 0;
} /* end main */

void cubeByReference( int *nPtr ) {
    *nPtr = *nPtr * *nPtr * *nPtr;
} /* end function cubeByReference */
