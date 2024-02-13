#include <stdio.h>
int strCmp( const char *s1, const char * s2 );
int strNCmp( const char *s1, const char * s2, size_t );
int main( void ) {
    char string1[80] = "Bachu Ally ";
    char string2[80] = "Bachu Ally Chamani";
    char string3[80] = "Bachu Ibrahim Ally Chamani";

    printf( "strCmp( string1, string2 ) == %d\n", strCmp( string1, string2 ) );
    printf( "strNCmp( string2, string3, 5 ) == %d\n", strNCmp( string2, string3, 5 ) );

    return 0; // indicate termination successful
} /* end main */
int strCmp( const char *s1, const char * s2 ) {
    size_t i = 0;  // counter
    while ( s2[ i ] != '\0' )
        if ( s1[ i ] > s2[ i ] )
            return 1;
        else if ( s1[ i ] < s2[ i ] )
            return -1;
        else
            i++;
 
    return 0; // return when s1 == s2
} /* end function strCmp */
int strNCmp( const char *s1, const char *s2, size_t n ) {
    for ( size_t i = 0; i < n; i++ )
        if ( s1[ i ] > s2[ i ] )
            return 1;
        else if ( s1[ i ] < s2[ i ] )
            return -1;

    return 0; // return when s1 == s2
} /* end function strNCmp */