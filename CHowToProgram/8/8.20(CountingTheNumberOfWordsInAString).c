/*
    theBitRiddler
    1/27/2024
    12:45 PM
    8.20 (Counting the Number of Words in a String) 
*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    char text[3][100] = {'\0'};   // Three lines of text input by user
    char *tokenPtr = "";         // pointer to a search character
    int i = 0;                    // loop counter
    int count = 0;                // token counter

    printf( "%s\n", "Enter three lines of characters: ");
    for ( i = 0; i < 3; i++ ) {
        gets( &text[i][0] );
    } // end for

    // loop through each line of text
    for ( i = 0; i < 3; i++ ) {

        //Enter a line of into strtok and count the first token
        tokenPtr = strtok( &text[i][0], " \n" );

        if ( tokenPtr )
            count++;

        while( tokenPtr = strtok( NULL, " \n" ) ) {
            ++count;
        } // end while

    } // end for

    printf( "%s%d%s\n", 
    "There are ", count, " words in the text." );

    return 0; // indicate termination successful
} /* end main */