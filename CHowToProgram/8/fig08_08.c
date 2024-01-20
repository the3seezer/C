/*
    theBitRiddler
    1/18/2024
    11/19 AM
    Standard input / output library functions
        getchar
*/
#include <stdio.h>
#define SIZE 80
int main( void ) {
    int c = 0; // variable to hold character input by user 
    char sentence[SIZE] = "";
    int i = 0;

    puts("Enter a line of text: ");
    while ( ( i < SIZE - 1 ) && ( ( c = getchar() ) != '\n' ) ) {
        sentence[ i++ ] = c;
    } // end while

    sentence[ i ] = '\0'; // terminate string

    puts("The line entered was: ");
    puts(sentence);
} /* end main */