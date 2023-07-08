/*
theBitRiddler
7/8/2023
1:42 PM
Card shuffling and dealing. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13
#define SUITS 4

void shuffle( int deck[][ FACES ]);
void deal( int deck[][ FACES ], const char * suit[], const char * face[] );

int main( void ) {
    int deck[ SUITS ][ FACES ] = { 0 };

    srand( time( NULL ));
    shuffle( deck );

    const char * suits[ SUITS ] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const char * faces[ FACES ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight"
                                    , "Nine", "Ten", "Jack", "Queen", "King" };
    
    deal( deck, suits, faces );

} /* end main */

void shuffle( int deck[][ FACES ]) {

    for ( int card = 1; card <= CARDS; card++ ) {
        size_t row = 0;
        size_t column = 0;

        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } 
        while ( deck[ row ][ column ] != 0 );
        
        deck[ row ][column ] = card;
    } /* end for */

} /* end function shuffle */

void deal( int deck[][ FACES ], const char * suit[], const char * face[] ) {

    for ( int card = 1; card <= CARDS; card++ ) {
        for ( size_t row = 0; row < SUITS; row++ ) {
            for ( size_t column = 0; column < FACES; column++ ) {

                if ( deck[ row ][ column ] == card ) {
                    printf_s( "%5s of %-8s  %c", face[ column ], suit[ row ], card % 4 == 0 ? '\n' : ' ' );
                } /* end if*/
            } /* end for */
        } /* end for */
    } /* end for */
} /* end function deal */