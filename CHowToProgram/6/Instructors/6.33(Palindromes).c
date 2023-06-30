/*
theBitRiddler
6/30/2023
9:39 AM
Palindrome
*/
#include <stdio.h>

#define SIZE 80

int testPalindrome( char array[], size_t left, size_t right);

int main( void) {
    char c = ' ';
    char string[ SIZE ] = { ' '};
    char copyString[ SIZE ] = { ' '};
    size_t count = 0;
    size_t copyCount = 0;

    printf_s( "%s", "Enter a sentense\n");

    while ( ( c = getchar() ) != '\n' && count < SIZE ) {
        string[ count++ ] = c;
    } /* end while */

    string[ count ] = '\0';

    for ( size_t i = 0; string[ i ] != '\0'; i++ ) {
        if ( string[ i ] != ' ') {
            copyString[ copyCount++ ] = string[ i ];
        } /* end if */
    } /* end for */

    if ( testPalindrome( copyString, 0, copyCount - 1 ) ) {
        printf_s( "%s", "is a palindrome\n");
    } /* end if */
    else {
        printf_s( "%s", "is not a palindrome\n");
    } /* end else */

    return 0;
} /* end main */

int testPalindrome( char array[], size_t left, size_t right ) {
    if ( left == right || left > right ) {
        return 1;
    } /* end if */
    else if ( array[ left ] != array[ right] ) {
        return 0;
    }
    else {
        return testPalindrome( array, left + 1, right - 1 );
    }
}