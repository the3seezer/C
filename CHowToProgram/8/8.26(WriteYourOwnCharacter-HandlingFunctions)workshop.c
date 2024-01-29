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
    if (c == 32 || c == 9)
        return 1; 
    else
        return 0;
} /* end function isblank */

int isAlpha( int c ) {
    if ( c >= 65 && c <= 90 ) // A - Z 
        return 1;
    else if ( c >= 97 && c <= 122 ) // a - z
        return 2;
    else
        return 0;
} /* end function isalpha */

int isDigit( int c ) {
    if ( c >= 48 && c <= 57 ) // 0 - 9
        return 1;
    else
        return 0;
} /* end function isdigit */

int isAlNum( int c ) {
    if ( c >= 65 && c <= 90 ) // A - Z
        return 1;
    else if ( c >= 97 && c <= 122 ) // a - z
        return 2;
    else if ( c >= 48 && c <= 57 ) // 0 - 9
        return 4;
    else  
        return 0;
} /* end function isalnum */
int isXDigit( int c ) {
    if ( (c >= 48 && c <= 57) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102) ) // 0 - 9, A - F and a - f
        return 128;
    else 
        return 0;
} /* end function isxdigit */

int isLower( int c ) {
    if ( c >= 97 && c <= 122 ) // a - z
        return 2;
    else 
        return 0;
} /* end function islower */
int isUpper( int c ) {
    if ( c >= 65 && c <= 90 ) // A - Z
        return 1;
    else  
        return 0;
} /* end function isupper */
int toLower( int c ) {
    if ( c >= 65 && c <= 90 ) // A - Z
        return c + 32;
    else 
        return c;
} /* end function tolower */
int toUpper( int c ) {
    if ( c >= 97 && c <= 122 ) // a - z
        return c - 32;
    else 
        return c;
} /* end function toupper */
int isSpace( int c ) { 
    if ( (c >= 9 && c <= 13) || c == 32 ) // horizontal tab ('\t'): 9, newline ('\n'), vertical tab ('\v'), form feed ('\f'), carriage return ('\r'): 13 or space (' '): 32 
        return 8;
    else 
        return 0;
} /* end function isspace */
int isCntrl( int c ) { 
    if ( (c >= 0 && c <= 31) || c == 127) // ...,  backspace ('\b'): 8, horizontal tab ('\t'), newline ('\n'), vertical tab ('\v'), form feed ('\f'), carriage return ('\r'): 13, alert ('\a'): * and others—
        return 32;
    else
        return 0;
} /* end function iscntrl */
int isPunct( int c ) { //  $, #, (, ), [, ], {, }, ;, : or %
    if ( (c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126) ) /* 33-47 ! " # $ % & ‘ ( ) * + , - . / */ /* 58-64 : ; < = > ? @  */ /* 91-96 [ \ ] ^ _ ’ */    /* 123-126 { | } ~  */ 
        return 16;
    else
        return 0;
} /* end function ispunct */
int isPrint( int c ) {
    if ( (c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126) ) /* 33-47 ! " # $ % & ‘ ( ) * + , - . / */ /* 58-64 : ; < = > ? @  */   /* 91-96 [ \ ] ^ _ ’ */    /* 123-126 { | } ~  */ 
        return 16;
    else if ( c >= 65 && c <= 90 ) // A - Z
        return 1;
    else if ( c >= 97 && c <= 122 ) // a - z
        return 2;
    else if ( c == 32 ) // space (' '): 32 
        return 64;
    else if ( c >= 48 && c <= 57 ) // digit
        return 4;
    else
        return 0;
} /* end function isprint */
int isGraph( int c ) {
    if ( (c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126) ) /* 33-47 ! " # $ % & ‘ ( ) * + , - . / */ /* 58-64 : ; < = > ? @  */   /* 91-96 [ \ ] ^ _ ’ */    /* 123-126 { | } ~  */ 
        return 16;
    else if ( c >= 65 && c <= 90 ) // A - Z
        return 1;
    else if ( c >= 97 && c <= 122 ) // a - z
        return 2;
    else if ( c >= 48 && c <= 57 ) // digit
        return 4;
    else
        return 0;
} /* end function isgraph */