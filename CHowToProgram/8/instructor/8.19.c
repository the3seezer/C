#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main( void ) {
    char text[3][80] = {'\0'};  // three lines of text
    char * searchPtr = "";      // pointer to a search character
    char character[26] = { 0 };  // totals for each character
    int count = 0;              // totals for a current character
    int i = 0;          // loop counter
    int j = 0;          // loop counter

    printf( "%s\n", "Enter three lines of text: " );
    for ( i = 0; i < 3; i++ ) {
        gets( &text[i][0] );
    } // end for

    // loop through all the characters 
    for ( i = 0; i < 3; i++ ) {
        // convert to lowercase
        for ( j = 0; text[i][j] != '\0'; j++ ) {
            text[i][j] = tolower( text[i][j]);
        } // end for
    } // end for

    // loop through each character
    for ( i = 0; i <= 25; i++ ) {
        // loop through three lines of text
        for ( j = 0, count = 0; j < 3; j++ )
            // set the first element to the pointer
            searchPtr = &text[j][0];
            while( searchPtr = strchr( searchPtr, 'a' + i ) ) {
                ++count;
                ++searchPtr;
            } // end while

        character[i] = count;
    } // end for

    printf( "%s\n", "The total occurence of each character: ");
    // display total of each character
    for ( i = 0; i < 26; i++ ) {
        printf( "%c:%3d\n", 'a' + i, character[ i ] );
    } // end for

    return 0; // indicate termination successful
} /* end main */