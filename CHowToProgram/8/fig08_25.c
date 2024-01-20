/*
    theBitRiddler
    1/19/2024
    10:23 AM
    Memory functions of the String-Handling Library
        memset
*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    char string1[15] = "BBBBBBBBBBBBBB";

    printf( "string1 = %s\n", string1 );
    printf( "string1 after memset = %s\n", ( char * ) memset( string1, 'b', 7 ) );
} /* end main */