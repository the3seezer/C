/*
theBitRiddler
9/6/2023
10:13 PM
String Character counter
*/
#include <stdio.h>
size_t cCounter( const char * s );

int main( void ) {
    char string[80];
    puts("Enter a string");
    scanf( "%79s", string );

    printf_s( "%zu", cCounter( string ) );

} /* end function main */

size_t cCounter( const char * s ) {
    size_t x;

    for ( x = 0; *s != '\0'; s++ ) {
        ++x;
    } // end for

    return x;
} /* end function cCounter */