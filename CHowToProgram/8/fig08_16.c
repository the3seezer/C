/*
    theBitRiddler
    1/19/2024
    8:29 AM
    String-Manipulation functions of the string-Handling library
        Search functions of the String-Handling library
        strpbrk
*/
#include <string.h>
#include <stdio.h>
int main( void ) {
    char *string1 = "This is a test";
    char *string2 = "Beware";

    printf( "%s\"%s\"\n'%c'%s\"%s\"\n",
    "Of the characters in ", string2, *strpbrk( string1, string2 ),
    " appears eariest in ", string1 );
} /* end main */