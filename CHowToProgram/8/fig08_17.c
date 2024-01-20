/*
    theBitRiddler
    1/19/2024
    8:29 AM
    String-Manipulation functions of the string-Handling library
        Search functions of the String-Handling library
        strrchr
*/
#include <string.h>
#include <stdio.h>
int main( void ) {
    const char * s1 = "A zoo has many animals including zebras";
    char c = 'z';

    printf( "%s \'%c\' %s\n\"%s\"\n",
    "Remainder of s1 beginning with the last occurence of character",
    c, "is", strrchr( s1, c ) );
} /* end main */