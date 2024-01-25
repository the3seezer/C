/*
    theBitRiddler

 */
#include <stdio.h>
#include <ctype.h>
int main( void ) {
    char c = ' '; // character input by user

    printf( "%s\n", "Enter a character: ");
    c = getchar();

    // Test each function of the character-handling library
    printf( "isblank(\'%c\') = %d\n", c, isblank( c ) );
    printf( "isdigit(\'%c\') = %d\n", c, isdigit( c ) );
    printf( "isalpha(\'%c\') = %d\n", c, isalpha( c ) );
    printf( "isalnum(\'%c\') = %d\n", c, isalnum( c ) );
    printf( "isxdigit(\'%c\') = %d\n", c, isxdigit( c ) );

    printf( "islower(\'%c\') = %d\n", c, islower( c ) );
    printf( "isupper(\'%c\') = %d\n", c, isupper( c ) );
    printf( "tolower(\'%c\') = %d\n", c, tolower( c ) );
    printf( "toupper(\'%c\') = %d\n", c, toupper( c ) );
    printf( "isspace(\'%c\') = %d\n", c, isspace( c ) );

    printf( "ispunct(\'%c\') = %d\n", c, ispunct( c ) );
    printf( "iscntrl(\'%c\') = %d\n", c, iscntrl( c ) );
    printf( "isprint(\'%c\') = %d\n", c, isprint( c ) );
    printf( "isgraph(\'%c\') = %d\n", c, isgraph( c ) );

    return 0; // indicate successful termination
} /* end main */