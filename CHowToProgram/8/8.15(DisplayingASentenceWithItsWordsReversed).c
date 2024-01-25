/*
    theBitRiddler
    1/25/2024
    9:57 AM
    8.15 (Displaying a Sentence with Its Words Reversed)
*/
#include <stdio.h>
#include <string.h>

void reverse( char * );
int main( void ) {
    char sentence[100] = {'\0'}; // sentence input by user
    char * tokenPtr = NULL;

    printf( "%s\n", "Enter a sentence: " );
    gets(sentence);
    printf( "\n%s\n", "The sentence with its words reversed: " );

    tokenPtr = strtok( sentence, " .,;" );

    while( tokenPtr != NULL ) {
        reverse( tokenPtr );
        tokenPtr = strtok( NULL, " .,;" );

        if ( tokenPtr ) {
            printf( "%s", " " );
        } // end if
    } // end while
    printf( "%s", "." );

} /* end main */

// reverse and display the word
void reverse( char * word ) {

    if ( word[ 0 ] == '\0' ) {
        return;
    } // end if
    reverse( &word[ 1 ] );
    printf( "%c", word[ 0 ] );

} /* end function reverse */