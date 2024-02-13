/*
    theBitRiddler
    2/2/2024
    10:39 PM
    functions in Fig. 8.22 for searching strings
*/
#include <stdio.h>
char * strChr( const char *, int );
size_t strCSpn( const char *, const char * );
size_t strSpn( const char *, const char * );
char * strPbrk( const char *, const char * );
char * strRChr( const char *, int );
char * strStr( const char *, const char * );
char * strTok( char *, const char * );
int main( void ) {
    char c = 'l';
    char *s = "Bachu Ally";
    printf( "The string: %s\nThe character %c\nThe remainder: %s\n\n", s, c, strChr( s, c ) );
    char *s1 = "Bachu";
    char *s2 = "Ally u";
    printf( "There are %zu: characters in \"%s\"\nbefore finding any character in \"%s\"\n\n", strCSpn( s, s2 ), s, s2 );
    printf( "There are %zu: characters in \"%s\"\nonly found in \"%s\"\n\n", strSpn( s, s1 ), s, s1 );
    char *s3 = "Bachu Ally Chamani";
    char *s4 = "Ally";
    printf( "Character found at \"%s\" in \"%s\"\nFrom \"%s\"\n\n", strPbrk( s3, s4 ), s3, s4 );

    printf( "The last occurence of '%c' in \"%s\"\nIs found at \"%s\"\n\n", c, s, strRChr( s, c ) );
    char *s5 = "Ally";
    printf( "The strings:s: \"%s\" and s5: \"%s\"\nstrStr( s, s5) == '%s'\n\n", s, s5, strStr( s, s5 ) );

    char *s6 = "My,;? name is Bachu Ally.";
    char * tokenPtr = "";   // token pointer
    tokenPtr = strTok( s6, " ,;" );
    printf( "The token: '%s'\n", tokenPtr );

    return 0; // indicate termination successful
} /* end main */
char * strChr ( const char * s, int c ) {
    while( *s != '\0' && *s != c ) {
        s++;
    } // end while
    // check if c was never found
    if ( *s == '\0')
        return NULL;

    return s; // indicate character found
} /* end function strChr */
size_t strCSpn( const char * s1, const char * s2 ) {
    int flag = 0; // a character is found flag
    size_t i = 0;   // counter
    size_t j = 0;   // counter

    while ( s1[i] != '\0' ) {
        j = 0;
        while( s2[j] != '\0' ) {
            if ( s1[i] == s2[j] ) { // get the flag and break if a character was found
                flag = 1;
                break;
            } // end if
            j++;
        } // end while
        // break if a character was found
        if ( flag )
            break;
        i++;
    } // end while

    return i; // number of character so far before finding any character
} /* end function strCSpn */
size_t strSpn( const char * s1, const char * s2 ) {
    int flag = 0; // a character is found flag
    size_t i = 0;   // counter
    size_t j = 0;   // counter

    while ( s1[i] != '\0' ) {
        j = 0;
        while( s2[j] != '\0' ) {
            if ( s1[i] == s2[j] ) { // break if a character was found
                flag = 1;
                break;
            } // end if
            j++;
        } // end while
        if ( flag ) { // Move on if the character was found
            flag = 0;
            i++;
        } // end if    
        else
            break;

    } // end while

    return i; // number of character always found
} /* end function strSpn */
char * strPbrk( const char * s1, const char * s2 ) {
    size_t flag = 0;
    for ( ; *s1 != '\0'; s1++ ) {
        size_t i = 0; // counter
        while( s2[i] != '\0' ) {
            if ( *s1 == s2[ i ] ) {
                flag = 1;
                break;
            } // end if
            i++;
        } // end while
        if ( flag ) 
            break;
    } // end for

    if( flag )
        return s1;
    else
        return NULL;
} /* end function strPbrk */
char * strRChr( const char * s, int c ) {
    size_t i = 0;   // counter
    int flag = 0;   // a flag when c is found
    // get the length of the string
    // locate to the length of the string 
    while( *s != '\0' ) {
        s++; i++;
    } // end while

    while( i ) {
        if ( *s == c ) {
            flag = 1;
            break;
        }
        s--; i--;
    } // end while

    if ( flag )
        return s;
    else
        return NULL;
} /* end function strRChr */
char * strStr( const char * s1, const char * s2 ) {
    int flag = 0;   // a flag when s2 if found
    // get length of s2
    size_t j = 0;   // s2 character counter
    while ( s2[j] != '\0' )
        j++;

    while ( *s1 != '\0' ) {
        if ( j > 1 ) { // if a string is more than one character
            for ( size_t i = 0; s1[i] == s2[i]; i++ ) {
                if ( s2[i] == '\0' ) { // if s2 was found in s1
                    flag = 1;
                } // end if
            } // end while
        } // end if    
        else if ( j ) { // if s2 is just one character
            if ( *s1 == *s2 ) {
                flag = 1;
            } // end if
        }   // end else if    
        // if s2 is found, break the loop
        if ( flag )
            break;

        s1++;
    } // end while

    if ( flag )
        return s1;
    else
        return NULL; 
} /* end function strStr */
char * strTok( char * s1, const char * s2 ) {
    int flag = 0;   // a flag when a delimiter is found / s2
    char *s3 = s1;
    char *s4 = "";
    char s[100] = "";
    // get length of s1 and length of s2
    size_t l = 0;   // s2 character counter
    size_t i = 0;   // s3 character counter

    // get the number of delimiters
    while ( s2[l] != '\0' )
        l++;

    while (  *s3 != '\0' ) {
        for ( size_t j = 0; j < l; j++ ) {
            if ( *s3 == s2[j] ) { // if s2 was found in s1
                flag = 1;
                break;
            } // end if
        } // end for
        if ( flag )
            break;
        s3++; i++;
    } // end for
    // assign some values from the beginning position in s1 to the array; s
    for ( size_t j = 0; j < i; j++ ) {
        s[j] = s1[j];
    } // end for
    // assign the values found in s to s4
    s4 = s;

    if ( flag ) // return a token
        return s4;
    else
        NULL;

} /* end function strTok */