#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LINES 4

int main( void ) {
    char text[LINES][100] = {'\0'};         // lines of text input by user
    char c = ' ';                           // a search character input by user
    char *searchPtr = "";                   // a pointer to the search
    size_t i = 0;                           // loop counter
    size_t j = 0;                           // loop counter
    int count = 0;                          // counter to characters found

    printf( "%s%d lines of text: \n", "Enter ", LINES );
    for ( i = 0; i < LINES; i++ ) {
        gets( text[ i ] );
    } // end for

    // loop through all characters
    for ( i = 0; i < LINES; i++ ) {
        // convert all characters to lowercase
        for ( j = 0; text[ i ][ j ] != '\0'; j++ ) {
            text[ i ][ j ] = tolower( text[ i ][ j ] );
        } // end for

    } // end for

    printf( "%s", "Enter a search character: ");
    c = getchar();

    c = tolower( c );

    // loop through all the characters
    for ( i = 0; i < LINES; i++ ) {
        // set the pointer to the first character of a string
        searchPtr = &text[ i ][ 0 ];

        // search the character
        while ( searchPtr = strchr( searchPtr, c ) ) {
            ++count;
            searchPtr++;
        } // end while

    } // end for

    printf( "%s%d%c\'s %s\n",
    "There are ", count, c, "found in text" );

    return 0; // indicate termination successful
} /* end main */