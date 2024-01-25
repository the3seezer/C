#include <stdio.h>
#include <string.h>
int main( void ) {
    char string1[100] = "";
    char string2[100] = "";
    int result = 0;
    int compareCount = 0;

    printf( "%s", "Enter two lines of strings: " );
    scanf( "%s%s", string1, string2 ); // Enter two string input by user

    printf( "%s", "How many characters should be compared: " );
    scanf( "%d", &compareCount );

    result = strncmp( string1, string2, compareCount );

    if ( result > 0 ) {
        printf( "\"%s\" is greater than \"%s\" up to %d characters\n", string1, string2, compareCount );
    } // end if
    else if ( result == 0 ) {
        printf( "\"%s\" is equal to \"%s\" up to %d characters\n", string1, string2, compareCount );
    } // end else if
    else {
        printf( "\"%s\" is less than \"%s\" up to %d characters\n", string1, string2, compareCount );
    } // end else
    return 0; // indicate termination successful 
} /* end main */