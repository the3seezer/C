/*
    theBitRiddler
    2/1/2024
    1:57 AM
    My Own string-copy and string-concatenation Functions
*/
#include <stdio.h>
char * strCpy( char * , const char * );
char * strNCpy( char *, const char *, size_t );
char * strCat( char * , const char * );
char * strNCat( char *, const char *, size_t );
int main( void ) {
    char s1[] = "";       //NOTE: use char s1[] = ""; instead of char * s1 = ""; To avoid Segmentation Fault when initializing this string
    char *s2 = "Bachu Ally";
    strCpy( s1, s2 );
    printf( "s1 :'%s'\n", s1 );

    char s3[] = "";
    char *s4 = "Bachu Ally";
    strNCpy( s3, s4, 7 );
    // Add '\0' to s1
    *(s3 + 7) = '\0';
    printf( "s3: '%s'\n", s3 );

    char s5[] = "Bachu ";
    char *s6 = "Ally";
    strCat( s5, s6 );
    printf( "s5: '%s'\n", s5 );

    char s7[] = "Bachu ";
    char * s8 = "Ally";
    strNCat( s7, s8, 5 ); // include the terminating null character
    printf( "s7: '%s'\n", s7 );

} /* end main */
char * strCpy( char * s1, const char * s2 ) {
    while ( *s2 != '\0' ) {
        *(s1++) = *(s2++);
    } // end while 
    // and '\0' at the end of s1 to avoid disrupting other strings
    *s1 = *s2;

    return s1; // return s1
} /* end function strCpy */
char * strNCpy( char * s1, const char * s2, size_t n ) {
    for ( size_t i = 0; i < n; i++ ) {
        *(s1+i) = *(s2+i);
    } // end for
         
    return s1;
} /* end function strNCpy */
char * strCat( char * s1, const char * s2 ) {
    // get the terminating null character
    while ( *s1 != '\0' )
        s1++;
    // concatenate
    while( *s2 != '\0' ) {
        *s1 = *s2;
        (s1)++; (s2)++;
    } // end while
    // and '\0' at the end of s1 to avoid disrupting other strings
    *s1 = *s2;

    return s1; // return s1
} /* end function strCat */
char * strNCat( char * s1, const char * s2, size_t n ) {
    // get the terminating null character
    while( *s1 != '\0' )
        (s1)++;
    // concatenate
    for ( size_t i = 0; i < n; i++ ) {
        *( s1 + i) = *( s2 + i );
    } // end for

    return s1; // indicate termination successful
} /* end function strNCat */