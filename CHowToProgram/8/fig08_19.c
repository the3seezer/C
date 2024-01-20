/*
    theBitRiddler
    1/19/2024
    8:29 AM
    String-Manipulation functions of the string-Handling library
        Search functions of the String-Handling library
        strstr
*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    const char * string1 = "abcdefabcdef";
    const char * string2 = "def";

    printf( "string1 = %s\nstring2 = %s\n\n%s\n%s%s",
    string1, string2, 
    "The remainder of string1 beginning with the",
    "first occurence of string2 = ", strstr( string1, string2 ) );
} /* end main */