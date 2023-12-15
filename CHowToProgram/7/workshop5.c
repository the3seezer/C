#include <stdio.h>

#define SIZE 1000

int cCount( char * s );
int input( int i, double memory[], int len, char * s );
int output( int i, double memory[] );
int main( void ) {
    int i = 10;
    double memory[ SIZE ];
    char string[ 100 ];

    // gets( string );
    // string[ 0 ] = 'B'; string[ 1 ] = 'a'; string[ 2 ] = 'c'; string[ 3 ] = 'h'; string[ 4 ] = 'u';
    // string[ 5 ] = ' '; string[ 6 ] = 'A'; 
    int count = 0;
    while ( string[ count ] != '\0' ) {
        scanf( "%c" , &string[ count++ ]);
    } // end while

    int len = cCount( string );

    input( i, memory, len, string );
    output( i, memory );

} /* end main */

int output( int i, double memory[] ) {
    int len = 0;
    int temp = 0;

    len = memory[ i ] / 1000;

    temp = ( int ) memory[ i ] % 1000;
    putchar( ( char ) temp );

    i++; len--; // move to the other location and reduce the string length

    // Output the characters
    while( len ) {
        temp = ( int ) memory[ i ] / 1000;
        if ( ( char ) temp != '\0' ) {
            putchar( ( char ) temp );
            len--;
        } // end if
        temp = ( int ) memory[ i ] % 1000; 
        if ( ( char ) temp != '\0' ) {
            putchar( ( char ) temp );
            len--;
        } // end if
        i++;
    } // end len
    return 0;
} /* end function output */

int input( int i, double memory[], int len, char * s ) {

    memory[ i ] = len * 1000; // introduce the size of the string
    memory[ i ] += ( int ) * s;
    s++; len--; i++; // move to the other location of pointer, reduce the string length and move to the other location

    for ( ; len ; i++ ) {
        if ( *s != '\0' ) {
            memory[ i ] = 1000 * ( int ) * s;
            s++; len--;
        } // end if
        if ( *s != '\0' ) {
            memory[ i ] += ( int ) * s;
            s++; len--;
        } // end if  
    } // end while
    return 0;
} /* end function input */

int cCount( char * s ) {
    int x = 0;
    for ( x = 0; *s != '\0'; s++ ) {
        ++x;
    } // end for
    return x;
} /* end function cCount */