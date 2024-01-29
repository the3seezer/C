#include <stdio.h>
#include <string.h>
int main( void ) {
    char text[5][20] = {'\0'};  // text entered by user
    size_t i = 0;               // loop counter
    int size = 0;               // size of string

    // Enter a series of strings
    for ( i = 0; i < 5; i++ ) {
        printf( "%s", "Enter a string: " );
        scanf( "%s", text[i] );
    } // end for

    // display a string ending with "ed"
    printf( "%s\n", "Strings ending with \"ed\": " );
    for ( i = 0; i <= 4; i++ ) {
        size = strlen( text[ i ] );
        if ( text[ i ][  size - 2 ] == 'e' && text[ i ][ size - 1 ] == 'd') {
            printf( "%s\n", &text[ i ][ 0 ] );
        } // end if
    } // end for

    return 0; // indicate termination successful
} /* end main */