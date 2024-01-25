#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main( void ) {
    char text[3][80] = { '\0' };    // 3 lines of text by user
    char search[20] = "";           // search by user
    char *searchPtr = "";           // pointer to a search string
    int counter = 0;                // search counter
    int i = 0;                      // loop counter
    int j = 0;                      // loop counter

    // Enter a line of text from user
    printf( "%s\n", "Enter three lines of text: " );
    for ( i = 0; i <= 2; i++ ) {
        gets( &text[ i ][ 0 ] );
    } // end for

    // make all characters lowercase
    for ( i = 0; i <= 2; i++ ) {

        // loop through all characters
        for ( j = 0; text[ i ][ j ] != '\0'; j++ ) {
            text[ i ][ j ] = tolower( text[ i ][ j ] );
        } // end for

    } // end for

    printf( "%s", "Enter a search string: " );
    gets( search );

    // loop through all three strings
    for ( i = 0; i <= 2; i++ ) {

        // set pointer to first character of a string
        searchPtr = &text[ i ][ 0 ];

        // loop while strstr does not return NULL
        while( searchPtr = strstr( searchPtr, search ) ) {
            ++counter;
            searchPtr++;
        } // end while

    } // end for

    printf( "\n\nThe total occurence of \"%s\" in the text is: %d\n",
    search, counter );
    
    return 0; // indicate termination successful
} /* end main */
