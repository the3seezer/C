/*
    theBitRiddler
    1/19/2024
    8:29 AM
    String-Manipulation functions of the string-Handling library
        Search functions of the String-Handling library
        strtok
                NOTE: Declare with the square brackets if you want the function to work: 13:( line 13 )
*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    char string[] = "This is a sentence with 7 tokens"; // Declare with the square brackets if you want the function to work
    
    printf( "The string to be tokenized is \"%s\"\n\n", string );
    puts( "The tokens are: ");
    
    char * tokenPtr = strtok( string, " " ); // begin tokenizing sentence

    // continue tokenizing sentence until tokenPtr becomes NULL
    while ( tokenPtr != NULL ) { // Continue tokenizing
        printf( "%s\n", tokenPtr );
        tokenPtr = strtok( NULL, " " ); // get next token
    } // end while
} /* end main */