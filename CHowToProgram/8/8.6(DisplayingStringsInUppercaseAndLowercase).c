/*
    theBitRiddler
    1/22/2024
    3:56 PM
    8.6 (Displaying Strings in Uppercase and Lowercase)
*/
#include <stdio.h>
#include <ctype.h>
#define SIZE 100
int main( void ) {
    char s[SIZE] = "";
    puts("Enter a line of text: " );
    fgets( s, SIZE, stdin );
    for ( size_t i = 0; s[ i ] != '\0'; ++i )
        printf( "%c", toupper( s[ i ] ) );
    puts("");
    for ( size_t i = 0; s[ i ] != '\0'; ++i )
        printf( "%c", tolower( s[ i ] ) );
    puts("");
} /* end main */