#include <stdio.h>
#include <string.h>
int main( void ) {
    char text[5][20] = {'\0'};  // text input by user
    size_t i = 0;               // loop counter
    size_t length = 0;          // string length

    // Enter a series of strings
    for ( i = 0; i <= 4; i++ ) {
        printf( "%s", "Enter a string: ");
        scanf( "%s", &text[i][0] );
    } // end for

    // display a string ending with "ed"
    printf( "%s\n", "Strings ending with \"ed\": ");
    for ( i = 0; i < 5; i++ ) {
        length = strlen( &text[ i ][ 0 ] );
        if ( strcmp( &text[ i ][ length - 2 ], "ed" ) == 0 ) {
            printf( "%s\n", &text[i][0] );
        } // end if
    } // end for

    return 0; // indicate termination successful
} /* end main */