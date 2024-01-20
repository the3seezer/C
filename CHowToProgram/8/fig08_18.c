/*
    theBitRiddler
    1/19/2024
    8:29 AM
    String-Manipulation functions of the string-Handling library
        Search functions of the String-Handling library
        strspn
*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    const char * string1 = "The value is 3.14159";
    const char * string2 = "aehi lsTuv";

    printf( "string1 = %s\nstring2 = %s\n\n%s\n%s%zu",
    string1, string2, 
    "The lenth of initial segment of string1",
    "containing only characters from string2 = ", strspn( string1, string2 ) );
} /* end main */