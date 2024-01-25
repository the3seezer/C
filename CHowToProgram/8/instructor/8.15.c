#include <stdio.h>
#include <string.h>

void reverseToken( char * sentence );
int main( void ) {
    char text[80] = ""; // a line of text from user

    printf( "%s\n", "Enter a line of text: " );
    gets( text );

    reverseToken( text );

    return 0; // indicate termination successful
} /* end main */

// Reverse the token
void reverseToken( char * sentence ) {
    char * pointers[50] = { '\0' }; // array to store the entire sentence
    char * temp = "";               // pointer to each token
    int count = 0;                 // token counter
    int i = 0;                      // loop counter

    temp = strtok( sentence, " " );

    while ( temp ) {

        pointers[ count++ ] = temp;
        temp = strtok( NULL, " " );
    } // end while

    printf( "\n%s\n", "Tokens in reverse order are: " );

    for ( i = ( count - 1 ); i >= 0; i-- ) {
        printf( "%s ", pointers[ i ] );
    } // end for

    return; // indicate termination successful
} /* end function reverseToken */