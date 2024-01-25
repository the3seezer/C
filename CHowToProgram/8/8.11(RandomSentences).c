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

int main( void ) {
    srand( time( NULL ) );

    char * article[SIZE1] = { "the", "a", "one", "some", "any" };
    char * noun[SIZE1] = { "boy", "girl", "dog", "town", "car" };
    char * verb[SIZE1] = { "drove", "jumped", "ran", "walked", "skipped" };
    char * preposition[SIZE1] = { "to", "from", "over", "under", "on" };
    char final[SIZE2] = ""; // The final sentence

    for ( int i = 0;i < 20; i++ ) {

        strcat( strcat( strcat( strcat( strcat( strcat( strcat( strcat( strcat( strcat( strcat( final, article[ rand() % 5 ] ), 
        " " ), noun[ rand() % 5 ] ), " " ),
        verb[ rand() % 5 ] ), " " ), preposition[ rand() % 5 ] ), " " ), article[ rand() % 5 ] ), " " ), noun[ rand() % 5 ] );

        final[ 0 ] = toupper( final[ 0 ]);
        strcat( final, "." );
        puts( final );
        memset( final, '\0', strlen( final ) );
    } // end while

    return 0;
    
} /* end main */