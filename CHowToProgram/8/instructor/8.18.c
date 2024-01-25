#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main( void ) {
    char text[3][80] = {'\0'};  // lines of text input by user
    char search = ' ';          // search character input by user
    char * searchPtr = "";      // pointer to a search string in a line of text
    int count = 0;              // character counter
    int i = 0, j = 0;           // loop counters

    printf( "%s\n", "three lines of text:");
    for ( i = 0; i <= 2; i++ ) {
        gets( &text[ i ][ 0 ] );
    } // end for

    // convert all characters to lowercase
    for ( i = 0; i <= 2; i++ ) {
        // loop through all characters
        for ( j = 0; text[ i ][ j ] != '\0'; j++ ) {
            text[ i ][j] = tolower( text[i][j]);
        } // end for
    } // end for

    printf( "%s", "Enter a search character: ");
    scanf( "%c", &search );

    // Search for the character
    for ( i = 0; i <= 2; i++ ) {
        // set the pointer to first character of a text
        searchPtr = &text[ i ][0];
        while( searchPtr = strchr( searchPtr, search ) ) {
            count++;
            searchPtr++;
        } // end while
    } // end for

    printf( "\nThe total occurence of \'%c\' in text is %d\n", search, count );

    return 0; // indicate termination successful
} /* end main */