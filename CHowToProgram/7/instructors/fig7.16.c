/*
theBitRiddler
7/8/2023
2:48 PM
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13
#define SUITS 4

void shuffle( int deck[][ FACES ]);
void deal( int deck[][FACES], const char * face[], const char * suit[]);

int main( void ) {
    int deck[ SUITS ][ FACES ] = { 0 };

    srand( time( NULL ));

    shuffle( deck );

    const char * suit[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    const char * face[FACES] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                "Jack", "Queen", "King" };
    
    deal( deck, face, suit );
}

void shuffle( int deck[][ FACES]) {

    for ( int card = 1; card <= CARDS; card++ ) {

        size_t row = 0;
        size_t column = 0;

        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        }
        while( deck[ row ][ column ] != 0 );

        deck[ row ][ column ] = card;
    } 
} /* end function shuffle */

void deal( int deck[][FACES], const char * face[], const char * suit[]) {

    for ( int card = 1; card <= CARDS; card++ ) {

        for ( size_t row = 0; row < SUITS; row++ ) {
            for ( size_t column = 0; column < FACES; column++ ) {

                if ( deck[row][column] == card ) {

                    printf_s( "%5s of %-8s  %c", face[ column ], suit[ row ], card % 4 == 0 ? '\n' : ' ' );

                }
            }
        }
    }
}