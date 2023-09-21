/*
theBitRiddler
9/21/2023
4:19 AM
Comparing function between two strings
*/
#include <stdio.h>
#define SIZE 80

int compare( const char *s1, const char *s2 );

int main(void) {
    char string1[ SIZE ] = {0};
    char string2[ SIZE ] = {0};

    printf_s( "%s", "Enter two strings\n");
    scanf( "%79s%79s", string1, string2 );
    printf_s( "The result is %d\n", compare( string1, string2 ) );

    return 0;
} /* end main */

int compare( const char *s1, const char *s2 ) {
    int result = 1;
    for ( ; *s1 != '\0' && *s2 != '\0'; ++s1, ++s2 ) {
        if ( *s1 != *s2 ) {
            result = 0;
        } // end if
    } // end for
    return result;
} /* end function compare */