#include <stdio.h>
int main( void ) {
    char text[4][20] = {'\0'};  // text input by user
    size_t i = 0;               // loop counter

    printf( "%s\n", "Enter four strings: ");
    for ( i = 0; i < 4; i++ ) {
        scanf( "%s", text[i] );
    } // end for

    // display strings beginning with "b";
    printf( "%s\n", "Strings beginning with 'b': " );
    for ( i = 0; i < 4; i++ ) {
        if ( text[ i ][ 0 ] == 'b' ) {
            printf( "%s\n", &text[ i ][ 0 ] );
        } // end if
    } // end for

    return 0; // indicate termination successful
} /* end main */