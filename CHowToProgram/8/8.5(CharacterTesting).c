/*
    theBitRiddler
    1/22/2024
    2:23 PM
    8.5 (Character Testing) 
*/
#include <stdio.h>
#include <ctype.h>
int main( void ) {
    char c = ' ';
    puts("Enter a character: ");
    c = getchar();
    printf( "%s%c\n%s%d\n%s%d\n%s%d\n%s%d\n%s%d\n\n"
    "%s%d\n%s%d\n%s%d\n%s%d\n%s%d\n\n"
    "%s%d\n%s%d\n%s%d\n%s%d\n",
    "The character entered ", c,
    "isblank( \'%c\' ) = ", isblank( c ),
    "isdigit( \'%c\' ) = ", isdigit( c ),
    "isalpha( \'%c\' ) = ", isalpha( c ),
    "isalnum( \'%c\' ) = ", isalnum( c ),
    "isxdigit( \'%c\' ) = ", isxdigit( c ),
    "islower( \'%c\' ) = ", islower( c ),
    "isupper( \'%c\' ) = ", isupper( c ),
    "tolower( \'%c\' ) = ", tolower( c ),
    "toupper( \'%c\' ) = ", toupper( c ),
    "isspace( \'%c\' ) = ", isspace( c ),
    "iscntrl( \'%c\' ) = ", iscntrl( c ),
    "ispunct( \'%s\' ) = ", ispunct( c ),
    "isprint( \'%c\' ) = ", isprint( c ),
    "isgraph( \'%c\' ) = ", isgraph( c ) );
} /* end main */