/*
    theBitRiddler
    1/22/2024
    12:35 PM

*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    /* c : The size of the char array is equal to the size of string; no terminating nul character
    
    Error: Character array s is not large enough to store the terminating null
    character.
    Correction: Declare the array with more elements. */
    char s[13] = "";
    strcpy( s, "Welcome Home" );
    /* d : The returns zero when the strings are equal
    
    Error: Function strcmp returns 0 if the strings are equal; therefore, the condition in the if statement is false, and the printf will not execute.
    Correction: Compare the result of strcmp with 0 in the condition. */
    char * string1 = "hello";
    char * string2 = "hello";
    if ( strcmp( string1, string2 ) == 0 ) {
        puts( "The strings are equal");
    } // end if

} /* end main */