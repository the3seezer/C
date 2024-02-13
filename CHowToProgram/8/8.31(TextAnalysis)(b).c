/*
    theBitRiddler
    2/5/2024
    1:52 PM
    8.31 (Text Analysis)
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LINES 3
#define LIMIT 10 // letter limit for each word
size_t counter( char * );

int main( void ) {
    char text[LINES][100] = {'\0'}; // lines of text input by user
    char *textPtr = "";             // text pointer to each line
    int character[LIMIT] = {0};    // word letters counter

    // Enter lines of text
    for ( size_t i = 0; i < LINES; i++ ) {
        printf( "%s\n", "Enter a line of text: " );
        gets( &text[i][0] );
    } // end for

    // count the letters of each word in each line and record
    for ( size_t i = 0; i < LINES; i++ ) {
        textPtr = strtok( text[i], " " );
        while( textPtr != NULL ) {
            ++character[ counter( textPtr) ]; // count the token according to the number of its letters
            textPtr = strtok( NULL, " " );
        } // end while
    } // end for

    // display the table
    printf( "%-20s%-20s\n", "Word Length", "Occurences" );
    for ( size_t i = 1; i < LIMIT; i++ ) {
        printf( "%-20zu%-20d\n", i, character[ i ] );
    } // end for

    return 0; // indicate termination successful
} /* end main */
// count the number of letters in a word
size_t counter( char * token ) {
    size_t count = 0;
    // count the letters of the token
    while ( token[count] != '\0' )
        count++;

    return count; // return the number of letter of token
} /* end function counter */