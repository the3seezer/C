/*
theBitRiddler
7/7/2023
8:32 PM
Copying a string using array notation and pointer notation.
*/
#include <stdio.h>

#define SIZE 10

void copy1( char * const s1, const char * const s2 );
void copy2( char * s1, const char * s2 );

int main( void ) {
    char string1[ SIZE ] = { ' ' };
    char * string2 = "Hello! ";

    copy1( string1, string2 );

    char string3[ SIZE ] = { ' ' };
    char string4[ SIZE ] = "Good bye!";

    copy2( string3, string4 );

    printf_s( "string1 is %s\n", string1 );
    printf_s( "string3 is %s\n", string3 );

} /* end main */

void copy1( char * const s1, const char * const s2 ) {

    for ( size_t i = 0; (s1[ i ] = s2[ i ]) != '\0' ; i++ );

} /* end functioin copy1 */

void copy2( char * s1, const char * s2 ) {

    for ( ; ( *s1 = *s2) != '\0' ; ++s1, ++s2 );

} /* end function copy2 */