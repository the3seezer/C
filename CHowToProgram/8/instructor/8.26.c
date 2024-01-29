#include <stdio.h>
int isDigit( int );
int isAlpha( int );
int isAlNum( int );
int isLower( int );
int isUpper( int );
int toLower( int );
int toUpper( int );
int isSpace( int );
int isPunct( int );
int isPrint( int );
int isGraph( int );
int main( void ) {
    int v = 0;
    char array[2] = {'\0'};

    printf( "%s", "Enter a character: " );
    scanf( "%c", &array[0] );

    v = isDigit( ( int ) array[0] );
    printf( "%s", "According to isDigit: " );
    v ? printf( "%c is a digit \n", array[0] ) :
        printf( "%c is not a digit \n", array[0] );

    v = isAlpha( ( int ) array[0] );
    printf( "%s", "According to isAlpha: ");
    v ? printf( "%c is a letter \n", array[0] ) :
        printf( "%c is not a letter \n", array[0] );
    
    v = isAlNum( ( int ) array[0] );
    printf( "%s", "According to isAlNum; ");
    v ? printf( "%c is a letter or digit\n", array[0] ) :
        printf( "%c is not a letter or digit\n", array[0] );
    
    v = isLower( ( int ) array[0] );
    printf( "%s", "According to isLower: ");
    v ? printf( "%c is a lowercase letter\n", array[0] ):
        printf( "%c is not a lowercase letter\n", array[0] );

    v = isUpper( ( int ) array[0] );
    printf( "%s", "According to isUpper: ");
    v ? printf( "%c is an uppercase letter\n", array[0] ) :
        printf( "%c is not an uppercase letter\n", array[0] );

    v = toLower( ( int ) array[0] );
    printf( "%s", "According to toLower: ");
    !(v > (int)array[0]) ? printf( "%c is unchanged\n", array[0] ) :
             printf( "%c has been changed from uppercase\n", v );

    v = toUpper( ( int ) array[0] );
    printf( "%s", "According to toUpper: " );
    !(v < (int)array[0]) ? printf( "%c is unchanged\n", array[0] ) :
             printf( "%c has been changed from lowercase\n", v );

    v = isSpace( ( int ) array[0] );
    printf( "%s", "According to isSpace: " );
    v == 0 ? printf( "%c is not a space character\n", array[0]) :
             printf( "%c is a space character\n", array[0]);
    
    v = isPunct( (int ) array[0] );
    printf( "%s", "According to isPunct: ");
    v == 0 ? printf( "%c is not a punctuation \n", array[0]) :
             printf( "%c is a punctuation\n", array[0] );
    
    v = isPrint( ( int ) array[0]);
    printf( "%s", "According to isPrint: ");
    v == 0 ? printf( "%c is not a printing character\n", array[0]):
             printf( "%c is a printing character\n", array[0]);

    v = isGraph( (int) array[0] );
    printf ( "%s", "According to isGraph: ");
    v == 0 ? printf( "%c is not a graph\n", array[0] ):
             printf( "%c is a graph\n", array[0]);

    return 0; // indicate termination successful
} /* end main */
int isDigit( int c ) {
    return ( c >= 48 && c <= 57 ) ? 1 : 0;
} /* end function isDigit */
int isAlpha( int c ) {
    return ( ( c >= 65 && c <= 90 ) || ( c >= 97 && c <= 122 ) ) ? 1 : 0;
} /* end function isAlpha */
int isAlNum( int c ) {
    return (isDigit( c ) == 1 || isAlpha( c ) == 1) ? 1 : 0;
} /* end function isAlNum*/
int isLower( int c ) {
    return ( c >= 97 && c <= 122 ) ? 1 : 0;
} /* end function isLower */
int isUpper( int c ) {
    return ( c >= 65 && c <= 90 ) ? 1 : 0;
} /* end function isUpper*/
int toLower( int c ) {
    return ( isUpper( c ) == 1 ) ? c + 32 : c;
} /* end function toLower */
int toUpper( int c ) {
    return ( isLower( c ) == 1 ) ? c - 32 : c;
} /* end function toUpper*/
int isSpace( int c ) {
    return ( (c >= 9 && c <= 13) || c == 32 ) ? 1 : 0;
} /* end function isSpace */
int isPunct( int c ) {
    return ( isAlNum( c ) == 0 && isSpace( c ) == 0 ) ? 1 : 0;
} /* end function isPunct */
int isPrint( int c ) {
    return ( c >= 32 && c <= 126 ) ? 1 : 0;
} /* end function isPrint */
int isGraph( int c ) {
    return ( c >= 33 && c <= 126 ) ? 1 : 0;
} /* end function isGraph */