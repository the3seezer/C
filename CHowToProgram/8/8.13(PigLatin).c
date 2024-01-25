/*
    theBitRiddler
    1/24/2024
    3:54 PM
    8.13 (Pig Latin)
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void printLatinWord( char * );
int main( void ) {
    char * word = "";
    size_t i = 0;  // loop counter
    char words[] = "My name is Bachu Ally. As of now we are working on the pigLatin project, its hard; thought we really like it";
    
    word = strtok( words, " .,;" );

    while ( word != NULL ) {
        printLatinWord( word );
        word = strtok( NULL, " .,;" );
        i++;

        if ( word ) {
            printf( "%c", ' ' );
        }
    } // end while

    printf( "%s", "." );

    return 0; // indicate termation successful

} /* end main */
void printLatinWord( char * w ) {
    char lTemp = ' '; // letter template
    size_t i = 0; // loop counter
    size_t size = strlen( w ); // get the token size

    // swap the first letter to the end
    while( i < size - 1 ) {
        lTemp = w[ i ];
        w[ i ] = w[ i + 1 ];
        w[ i + 1 ] = lTemp;
        i++;
    } // end while

    // Decapitalize the letter
    w[ size - 1 ] = tolower( w[ size - 1 ]);

    printf( "%say", w );
    return;

} /* end function printLatinWord */