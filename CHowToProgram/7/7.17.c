/*
theBitRiddler
9/6/2023
4:41 PM
Two strings appending
*/
#include <stdio.h>

#define SIZE 80
void append( char *s1, const char * s2 );

int main( void ) {
    char string1[ SIZE ];
    char string2[ SIZE ];

    puts( "Write two strings");
    scanf( "%39s%39s", string1, string2 );

    append( string1, string2 );

    printf_s( "%s", string1 );

} /* end main */

void append( char *s1, const char * s2 ) {
    while ( *s1 != '\0') {
        ++s1;
    } // end while
    for ( ; *s1 = *s2; s1++, s2++ ) {
        ; // empty statement
    } // end for
} // end function append