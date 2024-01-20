/*
    theBitRiddler
    1/18/2024
    5:37 PM
    String-Manipulation functions of the string-Handling library
        Search functions of the String-Handling library
        strchr
*/
#include <string.h>
#include <stdio.h>
int main( void ) {
    const char *string = "This is a test";
    char character1 = 'a';
    char character2 = 'z';

    // if character1 was found in string
    if ( strchr( string, character1 ) != NULL ) { // can remove "!= NULL"
        printf( "\'%c\' was found in string \"%s\"\n", character1, string );
    } // end if
    else { // if character1 was not found in string
        printf( "\"%c\" was not found in string \"%s\"\n", character1, string );
    } // end else 

    // if character2 was found in string
    if ( strchr( string, character2 ) ) { // can remove "!= NULL"
        printf( "\'%c\' was found in string \"%s\"\n", character2, string );
    } // end if
    else { // if character2 was not found in string
        printf( "\'%c\' was not found in string \"%s\"\n", character2, string );
    } // end else
} /* end main */