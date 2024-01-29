#include <stdio.h>
#include <string.h>

void bubbleSort( char a[][50] );
int main( void ) {
    char text[10][50] = {'\0'};  // line of text by user
    size_t i = 0;                  // loop counter

    // Enter 10 lines of text
    for ( i = 0; i <= 9; i++ ) {
        printf( "%s", "Enter a string: " );
        scanf( "%s", &text[i][0] );
    } // end for

    // alphabetize
    bubbleSort( text );
    printf( "%s\n", "The strings in alphabetic order: " );
    for ( i = 0; i <= 9; i++ ) {
        printf( "%s\n", &text[i][0] );
    } // end for

    return 0; // indicate termination successful
} /* end main */

void bubbleSort( char a[][50] ) {
    int i = 0;  // loop pass counter
    size_t j = 0;  // loop counter
    char temp[50] = {'\0'};

    for ( i = 0; i <= 8; i++ ) {
        for ( j = 0; j <= 8; j++ ) {
            if ( strcmp( &a[ j ][ 0 ], &a[ j + 1 ][ 0 ] ) > 0 ) {
                strcpy( temp, &a[ j ][ 0 ] );
                strcpy( &a[ j ][ 0 ], &a[ j + 1 ][ 0 ] );
                strcpy( &a[ j + 1 ][ 0 ], temp );
            } // end if
        } // end for
    } // end for

    return;
} /* end function bubbleSort */