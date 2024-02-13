/*
    theBitRiddler
    2/5/2024
    11:32 AM
    8.31 (Text Analysis)
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINES 3
int main( void ) {
    char text[LINES][80] = { '\0' }; // Text input by user
    char *textPtr = "";
    int i = 0;  // counter
    int count = 0;  // letter counter
    int character[26] = {0}; // record storage array of letters counted

    puts( "Enter several lines of text: " );
    for ( size_t i = 0; i < LINES; i++ ) {
        gets( text[i] );
    } // end for
        
    // turn each letter to lowercase
    for ( size_t i = 0; i < LINES; i++ ) {
        for ( size_t j = 0; text[i][j] != '\0'; j++ ) {
            text[i][j] = tolower( text[i][j] );
        } // end for
    } // end for
    
    // count each letter of the alphabet
    for ( i = 0; i < 26; i++ ) {
        count = 0;
        for ( size_t j = 0; j < LINES; j++ ) {
            textPtr = text[j]; // assign each line pointer to textPtr
            while( textPtr = strchr( textPtr, 'a' + i ) ) {
                count++; // count the letters
                textPtr++; // move to the next location
            } // end while
            character[i] = count;
        } // end for
    } // end for

    printf( "%s", "The table of letters counted:\n" );
    for ( int i = 0; i < 26; i++)
        printf( "%c%20d\n", 'a' + i, character[i] );

} /* end main */