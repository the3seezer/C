/*
theBitRiddler
7/10/2023
7:21 PM
(Card Shuffling and Dealing: Dealing Poker Hands) 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define SUITS 4
#define FACES 13
#define HAND 5

int hand( int *handFace, int subscriptFace, int column );
void shuffle( int deck[][ FACES ]);
void deal(int deck[][FACES], const char * suit[], const char *face[]);

int main( void ) {
    srand( time( NULL ));

    int deck[SUITS][FACES] = { 0 };

    shuffle( deck );

    const char *suit[ SUITS ] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    const char *face[ FACES ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                  "Jack", "Queen", "King" };

    deal( deck, suit, face );

} /* end main */

void deal( int deck[][FACES], const char * suit[], const char * face[]) {
    int handFace[HAND] = { 0 };
    int subscriptFace = 0;

    for ( int card = 1; card <= CARDS; card++ ) {
        for ( size_t row = 0; row < SUITS; row++ ) {
            for ( size_t column = 0; column < FACES; column++ ) {
                if ( deck[ row ][ column] == card ) {
                    printf_s( "%5s of %-8s %c", face[ column ], suit[ row ], card % 5 == 0 ? '\n' : ' ' );
                    if ( subscriptFace == 5)
                        subscriptFace = 0;
                    hand( handFace, subscriptFace++, column );
                }
            }
        }
    }
} /* end function deal */

int hand(int *handFace, int subscriptFace, int column ) {
    
    handFace[ subscriptFace ] = column;
    if ( subscriptFace % 4 == 0 && subscriptFace != 0 ) {
        putchar('\n');
        for ( size_t count = 0; count < HAND; count++ ) {
            printf_s( "%4d", handFace[ count ] );
        }
        putchar('\n');   
    }

} /* end function hand */

void shuffle( int deck[][FACES]) {

    for ( int  card = 1; card <= CARDS; card++ ) {
        size_t row = 0;
        size_t column = 0;

        do{
            row = rand() % SUITS;
            column = rand() % FACES;
        }
        while( deck[ row ][ column ] != 0 );

        deck[ row ][ column ] = card;

    }
} /* end function shuffle */
