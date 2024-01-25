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

void sentence( char ** , char **, char **, char **, char *, size_t *, size_t *, int );

int main( void ) {
    srand( time( NULL ) );

    char * article[SIZE1] = { "the", "a", "one", "some", "any" };
    char * noun[SIZE1] = { "boy", "girl", "dog", "town", "car" };
    char * verb[SIZE1] = { "drove", "jumped", "ran", "walked", "skipped" };
    char * preposition[SIZE1] = { "to", "from", "over", "under", "on" };
    char final[SIZE2] = ""; // The final sentence
    size_t first = 0; // The first verse
    size_t third = 0; // The third verse

    for ( int i = 0;i < 100; i++ ) {
        
        printf( "%s", i && i % 5 == 0 ? "\n\n" : "\n" );
        sentence( article, noun, verb, preposition, final, &first, &third, i % 5 );
        
    } // end while

    return 0;
    
} /* end main */

void sentence( char ** art, char ** n, char ** v, char ** p, char * s, size_t * f, size_t * t, int line ) {

    // set the limes in verses
    line == 0 ? *f = rand() % 5 : line == 1 ? *f : line == 2 ? *t = rand() % 5 : line == 3 ? *t : *f;
    // make sure the first and third verses are not identical
    if ( *f == *t && ( line == 2 || line == 3 ) )
        if ( *t < 4 ) {
            ++( *t );
        } // end if
        else {
            *t = 0;
        } // end else

    strcat( strcat( strcat( strcat( strcat( strcat( strcat( strcat( strcat( strcat( strcat( s, art[ rand() % 5 ] ), 
    " " ), n[ rand() % 5 ] ), " " ),
    v[ rand() % 5 ] ), " " ), p[ rand() % 5 ] ), " " ), art[ rand() % 5 ] ), " " ), n[ ( line == 2 || line == 3 ) ? *t : *f ] );

    s[ 0 ] = toupper( s[ 0 ]);
    strcat( s, "." );
    printf( "%s", s );

    memset( s, '\0', strlen( s ) );
    return;

} /* end function sentence */