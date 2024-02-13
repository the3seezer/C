#include <stdio.h>
size_t strLen( const char *s );
int main( void ) {
    char *string = "Bachu Ally Chamani";
    printf( "strLen( string ) == %zu\n", strLen( string ) );

    return 0; // indicate termination successful
} /* end main */
size_t strLen( const char *s ) {
    size_t i = 0;
    while ( *s++ != '\0' )
        i++;
    
    return i;
} /* end function strLen */