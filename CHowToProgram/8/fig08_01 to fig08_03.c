/*
    theBitRiddler
    1/18/2024
    8:04 AM
    Character-handling library: ctype
*/
#include <ctype.h>
#include <stdio.h>
int main( void ) {
    /*
    fig08.01
     isdigit, isalpha, isalnum and isxdigit */
    printf_s( "%s\n%s%s\n%s%s\n\n", "According to isdigit",
     isdigit( '8' ) ? "8 is a " : "8 is not a ", "digit ",
     isdigit( '#' ) ? "# is a " : "# is not a ", "digit" );

    printf_s( "%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "According to isalpha",
     isalpha( 'A' ) ? "A is a " : "A is not a ", "letter ",
     isalpha( 'b' ) ? "b is a " : "b is not a ", "letter",
     isalpha( '&' ) ? "& is a " : "& is not a ", "letter",
     isalpha( '4' ) ? "4 is a " : "4 is not a ", "letter" );

    printf_s( "%s\n%s%s\n%s%s\n%s%s\n\n", "According to isalnum",
     isalnum( 'A' ) ? "A is a " : "A is not a ", "digit or a letter",
     isalnum( '8' ) ? "8 is a " : "8 is not a ", "digit or a letter",
     isalnum( '#' ) ? "# is a " : "# is not a ", "digit or a letter" );

    printf_s( "%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "According to isxdigit",
     isxdigit( 'F' ) ? "F is a " : "F is not a ", "hexadecimal digit",
     isxdigit( 'J' ) ? "J is a " : "J is not a ", "hexadecimal digit",
     isxdigit( '7' ) ? "7 is a " : "7 is not a ", "hexadecimal digit",
     isxdigit( '$' ) ? "$ is a " : "$ is not a ", "hexadecimal digit",
     isxdigit( 'f' ) ? "f is a " : "f is not a ", "hexadecimal digit" );

    /* 
    fig08.02
    islower, isupper, tolower and toupper*/

    printf_s( "%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "According to islower",
     islower( 'p' ) ? "p is a " : "p is not a ", "lowercase letter ",
     islower( 'P' ) ? "P is a " : "P is not a ", "lowercase letter",
     islower( '5' ) ? "5 is a " : "5 is not a ", "lowercase letter",
     islower( '!' ) ? "! is a " : "! is not a ", "lowercase letter" );

    printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "According to isupper:",
     isupper('D') ? "D is an " : "D is not an ", "uppercase letter",
     isupper('d') ? "d is an " : "d is not an ", "uppercase letter",
     isupper('8') ? "8 is an " : "8 is not an ", "uppercase letter",
     isupper('$') ? "$ is an " : "$ is not an ", "uppercase letter");

    printf_s( "%s%c\n%s%c\n%s%c\n%s%c\n\n",
        "u converted to uppercase is ", toupper( 'u'),
        "7 converted to uppercase is ", toupper( '7' ),
        "$ converted to uppercase is ", toupper( '$' ),
        "L converted to lowercase is ", tolower( 'L' ) );

    /*
    fig08_03.c
     isspace, iscntrl, ispunct, isprint and isgraph */

    printf_s( "%s\n%s%s%s\n%s%s%s\n\n", "According to isspace",
        "Newline", isspace( '\n' ) ? " is a": " is not a",
        " whitespace character", 
        "Horizontal tab", isspace( '\t' ) ? " is a " : " is not a ",
        "whitespace character" );

    printf_s( "%s\n%s%s%s\n%s%s\n\n", "According to iscntrl",
        "Newline", iscntrl( '\n' ) ? " is a": " is not a",
        " control character", 
        iscntrl( '$' ) ? "$ is a " : "$ is not a ",
        "control character" );

    printf_s( "%s\n%s%s\n%s%s\n%s%s\n\n", "According to ispunct",
     ispunct( ';' ) ? "; is a " : "; is not a ", "punctuation character",
     ispunct( 'Y' ) ? "Y is a " : "Y is not a ", "punctuation character",
     ispunct( '#' ) ? "# is a " : "# is not a ", "punctuation character" );

    printf_s( "%s\n%s%s\n%s%s%s\n\n", "According to isprint",
     isprint( '$' ) ? "$ is a" : "$ is not a", " printing character",
     "Alert", isprint( '\a' ) ? " is a " : " is not a ", 
     "printing character" );

    printf_s( "%s\n%s%s\n%s%s%s\n\n", "According to isgraph",
     isgraph( 'Q' ) ? "Q is a" : "Q is not a", " printing character other than a space",
     "Space", isgraph( ' ' ) ? " is a " : " is not a ", 
     "printing character other than a space" );

} /* end main */