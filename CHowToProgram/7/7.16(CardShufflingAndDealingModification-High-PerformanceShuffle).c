/*
theBitRiddler
9/6/2023
12/40 PM
 (Card Shuffling and Dealing Modification: High-Performance Shuffle) 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle( int deck[][ FACES] );
void deal( int deck[][ FACES ], const char * face[], const char * suit[] );

int main( void ) {
    srand( time( NULL ) );

    int deck[ SUITS ][ FACES ] = {  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 
                                   14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
                                   27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
                                   40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52 };
    shuffle( deck );

    const char *suit[ SUITS ] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const char * face[ FACES ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                   "Ten", "Jack", "Queen", "King" };
    
    deal( deck, face, suit );
   
} /* end main */

void deal( int deck[][ FACES ], const char * face[], const char * suit[] ) {
    int dealt = 0; // dealt flag
    for ( int card = 1; card <= CARDS; card++ ) {
        dealt = 0;
        for ( size_t row = 0; row < SUITS; row++ ) {
            for ( size_t column = 0; column < FACES; column++ ) {
                if ( deck[ row ][ column ] == card ) {
                    printf_s( "%5s of %-8s %c", face[ column ], suit[ row ], card % 5 ? ' ' : '\n' );
                    dealt = 1;
                    break;
                } // end if
            } // end for 
            if ( dealt )
                break;
        } // end for
    } // end for
} /* end function deal */

void shuffle( int deck[][ FACES ]) {
    int temp = 0;
    int randomRow = 0;
    int randomColumn = 0;

    for ( size_t row = 0; row < SUITS; row++ ) {
        for ( size_t column = 0; column < FACES; column++ ) {
            randomRow = rand() % SUITS;
            randomColumn = rand() % FACES;

            temp = deck[ row ][ column ];
            deck[ row ][ column ] = deck[ randomRow ][ randomColumn ];
            deck[ randomRow ][ randomColumn ] = temp;
        } // end for
    } // end for 
} /* end function shuffle */