/*
theBitRiddler
9/6/2023
5:54 PM

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle( int deck[][ 13 ]);
void deal( int deck[][ 13 ], char * face[], char *suit[]);

int main(void) {
    int card = 1;
    int deck[ 4 ][ 13 ] = { 0 };

    srand( time( NULL ) );

    char * suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    char * face[ 13 ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                          "Jack", "Queen", "King" };

    for ( size_t row = 0; row < 4; row++ ) {
        for ( size_t column = 0; column < 13; column++ ) {
            deck[ row ][ column ] = card++;
        } // end for
    } // end for

    shuffle( deck );
    deal( deck, face, suit );

    return 0;

} /* end main */

void shuffle( int deck[][13]) {
    int temp = 0;
    int randRow = 0;
    int randColumn = 0;

    for ( size_t row = 0; row < 4; row++ ) {
        for ( size_t column = 0; column < 13; column++ ) {
            randRow = rand() % 4;
            randColumn = rand() % 13;

            temp = deck[ row ][ column ];
            deck[ row ][ column ] = deck[randRow][randColumn];
            deck[randRow][randColumn] = temp;
        } // end for
    } // end for
} /* end function deal */

void deal( int deck[][ 13 ], char * face[], char *suit[]) {
    for ( int card = 1; card <= 52; card++ ) {
        for ( size_t row = 0; row <= 3; row++ ) {
            for ( size_t column = 0; column <= 12; column++ ) {
                if ( deck[ row ][ column ] == card ) {
                    printf_s( "%5s of %-8s", face[ column ], suit[ row ] ); 
                    card % 2 == 0 ? putchar('\n') : putchar('\t');
                    break;
                } // end if 
            } // end for
        } // end for
    } /* end function deal*/
}