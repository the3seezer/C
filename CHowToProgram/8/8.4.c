/*
    theBitRiddler
    1/22/2024
    12:35 PM

*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    /* a: must include a terminating nul character '\0' 
    
    Error: Function strncpy does not write a terminating null character to array
    s, because its third argument is equal to the length of the string "hello".
    Correction: Make the third argument of strncpy 6, or assign '\0' to s[5].*/
    char s[10] = "";
    // strncpy( s, "hello", 5 );
    // s[5] = '\0'; // a terminating nul character OR
    strncpy( s, "hello", 6 );
    printf( "%s\n", s );
    /* b : an int data pointed to a pointer to a character
    
    Error: Attempting to print a character constant as a string.
    Correction: Use %c to output the character, or replace 'a' with "a". */
    // printf( "%c\n", 'a' ); OR
    printf( "%s", "a" );

} /* end main */