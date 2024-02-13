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
    char s1[21] = "";
    char s2[20] = "Bachu Ally";
    strCpy( s1, s2 );

    char s3[21] = "";
    char s4[20] = "Bachu Ally";
    strNCpy( s3, s4, 7 );

    char s5[41] = "Bachu ";
    char s6[20] = "Ally";
    strCat( s5, s6 );

    char s7[41] = "Bachu ";
    char s8[20] = "Ally";
    strNCat( s7, s8, 3 );

    return 0; // indicate termination successful
} /* end main */
char * strCpy( char * s1, const char * s2 ) {
    size_t i = 0; // counter

    // copy s2 into s1
    while( s2[ i ] != '\0' ) {
            s1[ i ] = s2[ i ];
        i++;
    } // end while

    return s1; // return s1  
} /* end function strCpy */
char * strNCpy( char * s1, const char * s2, size_t n ) {
    size_t i = 0; // counter
    // copy s2 into s1
    for ( ; i < n; i++ )
        s1[ i ] = s2[ i ];

    return s1; // indicate termination successful and return s1
} /* end function strNCpy */
char * strCat( char * s1, const char * s2 ) {
    size_t i = 0; // counter
    size_t j = 0; // counter
    // get the null character of s1 to replace
    while( s1[ i ] != '\0' ) {
        i++;
    } // end while
    // concatenate s2 to s1
    while ( s2[ j ] != '\0' ) {
        s1[ i ] = s2[ j ];
        i++; j++;
    } // end while

    return s1; // indicate termination successful
} /* end function strCat */
char * strNCat( char * s1, const char * s2, size_t n ) {
    size_t i = 0; // counter
    size_t j = 0; // counter
    // get the null character of s1 ...
    while ( s1[ i ] != '\0' )
        i++;
    // concatenate s2 to s1
    for ( ; j < n; j++, i++ ) {
        s1[ i ] = s2[ j ];
    } // end for

    return s1; // indicate termination successful
} /* end function strNCat */