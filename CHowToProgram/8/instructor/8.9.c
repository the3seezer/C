#include <stdio.h>
#include <string.h>
int main( void ) {
    char string1[100] = "";
    char string2[100] = "";
    int result = 0;

    printf( "%s", "Enter two strings: " );
    scanf( "%s%s", string1, string2 );

    result = strcmp( string1, string2 );

    if ( result > 0 ) {
        printf( "\"%s\" is greater than \"%s\"\n", string1, string2 );
    } // end if
    else if ( result == 0 ) {
        printf( "\"%s\" is equal to \"%s\"\n", string1, string2 );
    } // end else if
    else {
        printf( "\"%s\" is less than \"%s\"\n", string1, string2 );
    } // end else
    return 0; // indicate termination successful 
} /* end main */