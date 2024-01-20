/*
    theBitRiddler
    1/19/2024
    8:29 AM
    String-Manipulation functions of the string-Handling library
        Search functions of the String-Handling library
        strcspn
*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    const char * string1 = "The value is 3.14159";
    const char * string2 = "1234567890";

    printf( "string1 = \"%s\"\nstring2 = \"%s\"\n%s\n%s%zu\n",
    string1, string2,
    "The lenth of initial segment of string1",
    "Containing no characters from string2 = ", strcspn( string1, string2 ) );
} /* end main */