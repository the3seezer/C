/*
    theBitRiddler
    2/5/2024
    2:27 PM
    8.31 (Text Analysis)
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINES 2

int wordCounter( char *, char text[][80] );

int main( void ) {
    char text[LINES][80] = {'\0'}; // Lines of text input by user
    char copy[LINES][80] = {'\0'};
    char *textToken = "";       // pointer to a token
    size_t k = 0;       // string location controller

    // Enter lines of text
    for ( size_t i = 0; i < LINES; i++ ) {
        printf( "%s\n", "Enter a line of text: " );
        gets( text[i] );
    } // end for

    // convert each letter to lowercase
    for ( size_t i = 0; i < LINES; i++ ) {
        for ( size_t j = 0; text[i][j] != '\0'; j++ ) {
            text[i][j] = tolower( text[i][j] );
        } // end for
    } // end for
    // copy each line of text
    for ( size_t i = 0; i < LINES; i++ )
        strcpy( copy[i], text[i] );

    printf( "\n\n%-20s%-20s\n", "Words", "Occurences" );
    // loop through all the lines
    for ( size_t i = 0; i < LINES; i++ ) {
        
        k = 0;
        // get a token
        textToken = strtok( text[i], " ,.;:" );
        // Count and record a word
        while ( textToken != NULL ) {
            printf( "%-20s%-20d\n", textToken, wordCounter( textToken, copy ) );
            // go to the last location of the string token
            while( text[i][k] != '\0' )
                k++;
            // jump the null terminating character
            k += 1;
            textToken = strtok( &text[i][k], " ,.;:" );
        } // end while

    } // end for

    return 0; // indicate termination successful
} /* end main */
// Count the occurrence of a word
int wordCounter( char * word, char text[][80] ) {
    char *tokenPtr = "";
    int count = 0;   // counter of words similary to word
    size_t j = 0;    // string locator
    // loop throung all the lines
    for ( size_t i = 0; i < LINES; i++ ) {
        j = 0;
        // get your first token
        tokenPtr = strtok( text[i], " ,.;:" );
        while( tokenPtr != NULL ) {
            // count all similary words in each line of text
            if ( strcmp( word, tokenPtr ) == 0 ) {
                count++;
            } // end if
            // go to the last location of the string token
            while( text[i][j] != '\0' )
                j++;
            // jump the null terminating character
            j += 1;
            tokenPtr = strtok( &text[i][j], " ,.;:" );
        } // end while

    } // end for

    return count; // return number of words similary to the word
} /* end function wordCounter */