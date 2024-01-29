#include <stdio.h>
#include <string.h>
int main( void ) {
    char text[4][80] = {'\0'}; // four lines of text entered by user
    char * tokenPtr = "";       // token pointer
    int i = 0;              // loop counter
    int counter = 0;        // token counter

    printf( "%s\n", "Enter four lines of text" );
    for ( i = 0; i < 4; i++ ) {
        gets( &text[i][0] );
    } // end for

    // loop through each line of text
    for ( i = 0; i < 4; i++ ) {
        // get a first token
        tokenPtr = strtok( &text[i][0], " \n" );
        // count the tokens
        while ( tokenPtr ) {
            counter++;
            tokenPtr = strtok( NULL, " \n" );
        } // end while
    } // end for

    // display total number of tokens
    printf( "%s%d", "Total number of words is ", counter );

    return 0; // indicate termination successful
} /* end main */