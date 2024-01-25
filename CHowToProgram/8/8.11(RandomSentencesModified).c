/*
    theBitRiddler
    1/23/2023
    9:26 AM
    8.11 (Random Sentences) 
    The order: article, noun, verb, preposition, article and noun.
    generate 20 sentences
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define SIZE1 5
#define SIZE2 35

void sentence( char ** , char **, char **, char **, char * );

int main( void ) {
    srand( time( NULL ) );

    char * article[SIZE1] = { "the", "a", "one", "some", "any" };
    char * noun[SIZE1] = { "boy", "girl", "dog", "town", "car" };
    char * verb[SIZE1] = { "drove", "jumped", "ran", "walked", "skipped" };
    char * preposition[SIZE1] = { "to", "from", "over", "under", "on" };
    char final[SIZE2] = ""; // The final sentence

    for ( int i = 0;i < 100; i++ ) {
        
        printf( "%s", i % 20 == 0 ? i ? "\n\t" : "\t" : " " );
        sentence( article, noun, verb, preposition, final );
        
    } // end while

    return 0;
    
} /* end main */

void sentence( char ** art, char ** n, char ** v, char ** p, char * s ) {

    strcat( strcat( strcat( strcat( strcat( strcat( strcat( strcat( strcat( strcat( strcat( s, art[ rand() % 5 ] ), 
    " " ), n[ rand() % 5 ] ), " " ),
    v[ rand() % 5 ] ), " " ), p[ rand() % 5 ] ), " " ), art[ rand() % 5 ] ), " " ), n[ rand() % 5 ] );

    s[ 0 ] = toupper( s[ 0 ]);
    strcat( s, "." );
    printf( "%s", s );
    memset( s, '\0', strlen( s ) );

    return;

} /* end function sentence */