/*
    theBitRiddler
    2/2/2024
    10:38 PM
    getchar, gets, putchar and puts
*/
#include <stdio.h>
int getChar( void );
char * Gets( char * );
int putChar( int );
int Puts( const char * );
int main( void ) {
    char c = ' '; // char input by user
    char s[] = ""; // string input by user 

    c = getChar();
   
    Gets( s );

    putChar( c ); // putChar prints the first element of 'Gets( s )' instead of what we added in 'getChar()'

    Puts( s );

    return 0; // indicate termination successful
} /* end main */
int getChar( void ) {
    char c = 0;
    scanf( "%c", &c );
    return c; // return an int 
} /* end function getChar */
char * Gets( char *s ) {
    scanf( "%c", s );
    while( *s != '\0' ) {
        s++;
        scanf( "%c", s );

        // Break the loop when  Enter('\n') is entered; end of line character
        if ( *s == '\n' )
            break;
    } // end while
    *s = '\0';
    
    return s; // return a string
} /* end function Gets */
int putChar( int c ) {
    printf( "%c", c );
    return c;
} /* end function putChar */
int Puts( const char *s ) {
    size_t i = 0; // counter
    while ( s[i] != '\0' ) {
        printf( "%c", s[i++] );
    } // end while

    // if the string is empty return 0
    if ( i == 0 )
        return 0;

    printf( "%s", "\n" );

    return 1; // indicate termination successful
} /* end function Puts */