/*
theBitRiddler
7/2/2023
5:32 PM
Converting a string to uppercase using a non-constant pointer to non-constant data.
*/
#include <stdio.h>
#include <ctype.h>

void convertToUpperCase( char *sPtr);

int main( void ) {
    char string[] = "cHaRaCters and $32.98";

    printf_s( "String before conversion is: \n%s\n", string);
    convertToUpperCase( string );
    printf_s( "String after conversion is: \n%s", string );
} /* end main */

void convertToUpperCase( char *sPtr ) {
    while ( *sPtr != '\0' ) {
        *sPtr = toupper( *sPtr );
        ++sPtr;
    } /* end while */
} /* end function convertToUpperCase */
