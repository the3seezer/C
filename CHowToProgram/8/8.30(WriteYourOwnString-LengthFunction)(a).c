/*
    theBitRiddler
    2/2/2024
    9:58 PM
    8.30 (Write Your Own String-Length Function) 
*/
#include <stdio.h>
size_t strLen( const char *s );
int main( void ) {
    char string[80] = "Bachu Ally";
    printf( "strLen( string ) == %zu\n", strLen( string ) );

    return 0; // indicate termination successful
} /* end main */
size_t strLen( const char *s ) {
    size_t i = 0;
    while( s[ i ] != '\0' )
        i++;

    return i;
} /* end function strLen */