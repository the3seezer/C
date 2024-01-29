/*
    theBitRiddler
    1/27/2024
    10:11 AM
    Counting the letters of the Alphabet in a string, HINT a = 97, z = 122
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main( void ) {
    char text[3][100] = {'\0'};    // line of text input by user
    int alCount[123] = {0};       // alphabet counter
    int i = 0;                      // loop counter
    int j = 0;                      // loop counter

    for ( i = 0; i < 3; i++  ) {
        printf( "%s\n", "Enter a line of text");
        gets( text[i] );
    } // end for

    // loop through all the characters
    for ( i = 0; i < 3; i++ ) {

        for ( j = 0; text[i][j] != '\0'; j++ ) {
            // convert all characters to lowercase
            text[i][j] = tolower( text[i][j] );
            // count the alphabet
            if ( isalpha( text[i][j] ) )
                ++alCount[ (int) text[i][j] ];

        } // end for
    } // end for

    // Display the alphabets
    printf( "%s\n", "There are: " );
    for( i = 97; i < 123; i++ ) {
        // check if the array is empty
        if ( alCount[i] )
            printf( "%c: %d\n", i, alCount[i] );

    } // end for

    return 0; // indicate termination successful
} /* end main */