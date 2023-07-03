/*
theBitRiddler
7/2/2023
6:11 PM
Printing a string one character at a time using a non-constant pointer to constant data.
*/
#include <stdio.h>

void printCharacters( const char *sPtr );

int main( void ) {
    char string[] = "print characters of a string";

    puts( "The string is ");
    printCharacters( string );
    puts("");

} /* end main */

void printCharacters( const char *sPtr ) {
    for ( ; *sPtr != '\0' ; ++sPtr ) {
        printf_s( "%c", *sPtr );
    } /* end for */
} /* end function printCharacters */