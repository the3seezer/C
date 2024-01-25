#include <stdio.h>
#include <string.h>

void printLatinWord( char * );
int main( void ) {
    char sentence[ 80 ] = ""; // sentence input by user
    char * tokenPtr = "";

    printf( "%s\n", "Enter a sentence: ");
    gets( sentence );
    printf( "%s\n", "The sentence in PigLatin is: " );

    tokenPtr = strtok( sentence, " .,;" );

    while ( tokenPtr ) {
        printLatinWord( tokenPtr );
        tokenPtr = strtok( NULL, " .,;" );

        if ( tokenPtr ) {
            printf( "%s", " " );
        } // end if
    } // end while
    
    printf( "%s", "." );
    return 0; // indicate termination successful

} /* end main */

void printLatinWord( char * word ) {
    for ( size_t i = 1; i < strlen( word ); i++ ) {
        printf( "%c", word[ i ] );
    } // end for
    printf( "%c%s", word[ 0 ], "ay" );
    return;
} /* end function printLatinWord */