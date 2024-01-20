/*
    theBitRiddler
    1/19/2024
    10:23 AM
    Memory functions of the String-Handling Library
        memcmp
*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    char s1[] = "ABCDEFG";
    char s2[] = "ABCDXYZ";

    printf( "s1 = %s\ns2 = %s\n\n%s%2d\n%s%2d\n%s%2d\n",
    s1, s2, 
    "memcmp( s1, s2, 4 ) = ", memcmp( s1, s2, 4 ),
    "memcmp( s1, s2, 7 ) = ", memcmp( s1, s2, 7 ),
    "memcmp( s2, s1, 7 ) = ", memcmp( s2, s1, 7 ) );
} /* end main */