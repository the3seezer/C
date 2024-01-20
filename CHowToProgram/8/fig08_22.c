/*
    theBitRiddler
    1/19/2024
    10:23 AM
    Memory functions of the String-Handling Library
        memmove
*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    char x[] = "Home Sweet Home"; // Initialize char array x

    printf( "The string in array x before memmove is: %s\n", x );
    printf( "The string in array x after memmove is: %s", ( char * ) memmove( x, &x[ 5 ], 10 ) );
} /* end main */