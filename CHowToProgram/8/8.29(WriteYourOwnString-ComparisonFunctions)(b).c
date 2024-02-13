#include <stdio.h>
int strCmp( const char *s1, const char * s2 );
int strNCmp( const char *s1, const char * s2, size_t );
int main( void ) {
    char *string1 = "Bachu Ally";
    char *string2 = "Bachu Ally Chamani";
    char *string3 = "Bachu Ibrahim Ally Chamani";

    printf( "strCmp( string1, string2 ) == %d\n", strCmp( string1, string2 ) );
    printf( "strNCmp( string2, string3, 6 ) == %d\n", strNCmp( string2, string3, 6 ) );

    return 0; // indicate termination successful
} /* end main */
int strCmp( const char *s1, const char * s2 ) {
    while( *s2 != '\0' )
        if ( *s1 > *s2 )
            return 1;
        else if ( *s1 < *s2 )
            return -1;
        else {
            s1++; s2++;
        } // end else

    return 0; // return when s1 == s2            
} /* end function strCmp */
int strNCmp( const char *s1, const char *s2, size_t n ) {
    for ( size_t i = 0; i < n; i++ )
        if ( *(s1 + i) > *(s2 + i) )
            return 1;
        else if ( *(s1 + i) < *(s2 + i) )
            return -1;
    
    return 0; // return when s1 == s2
} /* end function strNCmp */