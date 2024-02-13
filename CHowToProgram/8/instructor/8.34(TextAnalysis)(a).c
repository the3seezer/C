/*
    theBitRiddler
    2/7/2024
    6:54 PM
    8.34 (Text Analysis) 
*/
#include <stdio.h>
#include <ctype.h>
int main( void ) {
    char text[3][80] = { '\0' };
    char letters[26] = "";

    printf( "%s\n", "Enter three lines of text");
    for ( size_t i = 0; i < 3; i++ ) {
        gets( &text[i][0] );
    } // end for

    // loop through the text
    for ( size_t i = 0; i < 3; i++ ) {
        for ( size_t j = 0; text[i][j] != '\0'; j++ ) {
            if ( isalpha( text[i][j] ) ) {
                ++letters[ tolower( text[i][j] ) - 'a' ];
            } // end if
        } // end for
    } // end for

    printf( "%s\n", "Total letter counts");
    for ( size_t i = 0; i < 26; i++ ) {
        printf( "%c%20d\n", i + 'a', letters[ i ] );
    } // end for

} /* end main */