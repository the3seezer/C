/*
    theBitRiddler
    1/28/2024
    10:55 AM
    my own character-handling functions
*/
#include <stdio.h>
int isBlank( int );
int isAlpha( int );
int isDigit( int );
int isAlNum( int );
int isXDigit( int );
int isLower( int );
int isUpper( int );
int toLower( int );
int toUpper( int );
int isSpace( int );
int isCntrl( int );
int isPunct( int );
int isPrint( int );
int isGraph( int );
int main( void ) {
    char c = ' ';  // character input by user
    printf( "\n%s", "Enter a character: ");
    scanf( "%c", &c );

    printf( "The character '%c'\nThe Code: %d\n", c, c );
    printf( "%s%d\n", "isBlank( c ) == ", isBlank( c ) );
    printf( "%s%d\n", "isAlpha( c ) == ", isAlpha( c ) );
    printf( "%s%d\n", "isDigit( c ) == ", isDigit( c ) );
    printf( "%s%d\n", "isAlNum( c ) == ", isAlNum( c ) );
    printf( "%s%d\n\n", "isXDigit( c ) == ", isXDigit( c ) );

    printf( "%s%d\n", "isLower( c ) == ", isLower( c ) );
    printf( "%s%d\n", "isUpper( c ) == ", isUpper( c ) );
    printf( "%s%d\n", "toLower( c ) == ", toLower( c ) );
    printf( "%s%d\n", "toUpper( c ) == ", toUpper( c ) );
    printf( "%s%d\n\n", "isSpace( c ) == ", isSpace( c ) );

    printf( "%s%d\n", "isCntrl( c ) == ", isCntrl( c ) );
    printf( "%s%d\n", "isPunct( c ) == ", isPunct( c ) );
    printf( "%s%d\n", "isPrint( c ) == ", isPrint( c ) );
    printf( "%s%d\n", "isGraph( c ) == ", isGraph( c ) );
    
    return 0; // indicate termination successful
} /* end main */
int isBlank( int c ) {
    return (c == 32 || c == 9) ? 1 : 0;
} /* end function isBlank */
int isAlpha( int c ) {
    return ( isUpper( c ) ) ? 1 : ( isLower( c ) ) ? 2 : 0; 
} /* end function isAlpha */
int isDigit( int c ) {
    return ( c >= 48 && c <= 57 ) ? 1 : 0; // 0 - 9
} /* end function isDigit */
int isAlNum( int c ) {
    return ( isUpper( c ) ) ? 1 : ( isLower( c ) ) ? 2 : ( isDigit( c ) ) ? 4 : 0;
} /* end function isaAlNum */
int isXDigit( int c ) {
    return ( isDigit( c ) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102) ) ? 128 : 0; // 0 - 9, A - F and a - f
} /* end function isXDigit */
int isLower( int c ) {
    return ( c >= 97 && c <= 122 ) ? 2 : 0; // a - z
} /* end function isLower */
int isUpper( int c ) {
    return ( c >= 65 && c <= 90 ) ? 1 : 0; // A - Z
} /* end function isUpper */
int toLower( int c ) {
    return isUpper( c ) ? c + 32 : c; 
} /* end function toLower */
int toUpper( int c ) {
    return isLower( c ) ? c - 32 : c; 
} /* end function toUpper */
int isSpace( int c ) { 
    return ( (c >= 9 && c <= 13) || c == 32 ) ? 8 : 0; // horizontal tab ('\t'): 9, newline ('\n'), vertical tab ('\v'), form feed ('\f'), carriage return ('\r'): 13 or space (' '): 32 
} /* end function isSpace */
int isCntrl( int c ) { 
    return ( (c >= 0 && c <= 31) || c == 127) ? 32 : 0; // ...,  backspace ('\b'): 8, horizontal tab ('\t'), newline ('\n'), vertical tab ('\v'), form feed ('\f'), carriage return ('\r'): 13, alert ('\a'): * and others—
} /* end function isCntrl */
int isPunct( int c ) { 
    return ( isAlNum( c ) == 0 && isSpace( c ) == 0 ) ? 16 : 0; /* 33-47 ! " # $ % & ‘ ( ) * + , - . / */ /* 58-64 : ; < = > ? @  */ /* 91-96 [ \ ] ^ _ ’ */    /* 123-126 { | } ~  */ 
} /* end function isPunct */
int isPrint( int c ) {
    return (isPunct(c)) ? 16 : (isUpper(c)) ? 1 : (isLower(c)) ? 2 : ( c == 32 ) ? 64 : (isDigit(c)) ? 4 : 0; /* 33-47 ! " # $ % & ‘ ( ) * + , - . / */ /* 58-64 : ; < = > ? @  */   /* 91-96 [ \ ] ^ _ ’ */    /* 123-126 { | } ~  */ 
} /* end function isPrint */
int isGraph( int c ) {
    return (isPunct(c)) ? 16 : (isUpper(c)) ? 1 : (isLower(c)) ? 2 : (isDigit(c)) ? 4 : 0; /* 33-47 ! " # $ % & ‘ ( ) * + , - . / */ /* 58-64 : ; < = > ? @  */   /* 91-96 [ \ ] ^ _ ’ */    /* 123-126 { | } ~  */ 
} /* end function isGraph */