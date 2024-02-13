/*
    theBitRiddler
    2/8/2024
    12:44 PM
    Text Analysis
*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    char text[3][80] = {'\0'};
    int length[20] = {0};
    int i = 0;  // loop counter
    char * temp = 0;    // token template

    printf( "%s\n", "Enter three lines of text: ");
    for ( i = 0; i < 3; i++ ) {
        gets( &text[i][0]);
    } // end for

    /* loop through each string */
    for ( i = 0; i < 3; i++ ) {

        temp = strtok (&text[i][0], ". \n");

        while ( temp ) {
            ++length[ strlen(temp) ];
            temp = strtok( NULL, ". \n");
        } // end while

    } // end for

    /* display the words */
    for ( i = 1; i < 20; i++ ) {
        // if its not empty
        if( length[i] ) {
            printf( "%d word%s of length %d\n", 
            length[i], length[i] == 1 ? "" : "s", i );
        } // end if
    } // end for

    return 0; // indicate termination successful
} /* end main */