#include <stdio.h>
#include <ctype.h>
int main( void ) {
    char s[100] = "";
    size_t i = 0;

    printf( "%s\n", "Enter a line of text: ");
    gets( s );
    printf( "%s\n", "The line in uppercase is: ");

    // convert each character to uppercase and output
    for ( i = 0; s[ i ] != '\0'; i++ ) {
        printf( "%c", toupper( s[ i ] ) );
    } // end for

    printf( "\n\n%s\n", "The line in lowercase is: ");

    // convert each character to lowercase and output
    for ( i = 0; s[ i ] != '\0'; ++i ) {
        printf( "%c", tolower( s[ i ] ) );
    } // end for
    return 0; // indicate termination successful
}