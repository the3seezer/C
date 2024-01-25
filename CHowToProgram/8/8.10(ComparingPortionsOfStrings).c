/*
    theBitRiddler
    1/23/2024
    9:03 AM
    8.10 (Comparing Portions of Strings) 
*/
#include <stdio.h>
#include <string.h>
#define SIZE 100
int main( void ) {
    char s1[SIZE] = "";
    char s2[SIZE] = "";
    int c = 0; // The condition template
    int n = 5; // number of characters to compare

    printf_s( "%s\n", "Enter two lines of text: " );

    gets(s1);
    gets(s2);

    printf_s( "%s%s%d%s\n", "string s1 is ",
    ( c = strncmp( s1, s2, n ) ) > 0 ? "greater than " : c < 0 ? "less than " : "equal to ",
    n, " characters compared to from string s2" );

    return 0;
} /* end main */