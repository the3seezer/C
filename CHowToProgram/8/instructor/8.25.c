#include <stdio.h>
int main( void ) {
    int c = 0;

    printf( "%s", "Enter an ASCII character code ( EOF to end ): " );

    while ( scanf( "%d", &c ) != EOF ) {

        if ( c >= 0 && c <= 255 ) {
            printf( "The corresponding character is '%c': \n", c );
        } // end if
        else {
            printf( "%s\n", "Invalid character code ");
        } // end else

        printf( "%s", "Enter an ASCII character code ( EOF to end ): " );
    } // end while

    return 0; // indicate termination successful
} /* end main */