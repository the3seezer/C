/*
    theBitRiddler
    1/23/2024
    8:33 AM
    8.9 (Comparing Strings)
*/
#include <stdio.h>
#include <string.h>
#define SIZE 100
int main( void ) {
    char string1[SIZE] = "";
    char string2[SIZE] = "";
    int c = 0; // The condition template

    printf_s( "%s\n", "Enter two lines of characters: " );

    gets(string1);
    gets(string2);

    printf( "%s%s%s\n", "string1 is ",
    ( c = strcmp( string1, string2 ) ) > 0 ? "greater than " : c < 0 ? "less than " : "equal to ", "string2" );

    return 0;
} /* end main */