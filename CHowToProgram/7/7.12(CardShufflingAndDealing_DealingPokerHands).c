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

void hand( int *handFace, int *handSuit, size_t subscript, int column, int row, const char *face[], const char *suit[] );
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
    int handSuit[HAND] = { 0 };
    size_t subscript = 0;   
    

    for ( int card = 1; card <= CARDS; card++ ) {
        for ( size_t row = 0; row < SUITS; row++ ) {
            for ( size_t column = 0; column < FACES; column++ ) {
                if ( deck[ row ][ column] == card ) {
                    printf_s( "%5s of %-8s %c", face[ column ], suit[ row ], card % 5 == 0 ? '\n' : ' ' );
                    if ( subscript == 5)
                        subscript = 0;
                    hand( handFace, handSuit, subscript++, column, row, face, suit );
                } /* end if */
            } /* end for */
        } /* end for */
    } /* end for */

} /* end function deal */

void hand(int *handFace, int *handSuit, size_t subscript, int column, int row, const char *face[], const char *suit[] ) {
    void sort( int *handFace, size_t size );
    void copy( int *copyFace, int * handFace);

    handFace[ subscript ] = column;
    handSuit[ subscript ] = row;
    int same = 0;
    int pair = 0, pCard = 0, s1 = 0, s2 = 0;
    int pairNumber = 0; // number of pairs
    int three = 0, tCard = 0, s3 = 0;
    int four = 0, fCard = 0, s4 = 0;
    int noFlush = 0;
    int noStraight = 0;

    if ( subscript % 4 == 0 && subscript != 0 ) { 
        int copyFace[ HAND ] = {0};
        copy( copyFace, handFace );
        
        sort( copyFace, HAND );

        for ( size_t i = 0; i < subscript; i++ ) {
            if( copyFace[ i ] == copyFace[ i + 1 ] || copyFace[ i ] == (copyFace[ i + 1 ] - 1) ) {
                ;
            } /* end if */
            else 
                noStraight = 1;
        } /* end for */

        for ( size_t count = 0 ; count < HAND; count++ ) {
            same = 0;
            pair = 0;
            three = 0;
            four = 0;

            for ( size_t count2 = 0; count2 < HAND; count2++) {
                if ( count != count2 && handFace[count] == handFace[ count2 ] && handFace[count2] != 99 ) {
                    same++;
                    if ( same == 1 ) {
                        pair = handFace[ count ];
                        s1 = handSuit[ count ];
                        s2 = handSuit[ count2 ];
                    }
                    else if ( same == 2 ) {
                        three = handFace[ count ];
                        s3 = handSuit[ count2 ];
                    }
                    else if ( same == 3 ) {
                        four = handFace[ count ];
                        s4 = handSuit[ count2 ];
                    }
                    handFace[ count2 ] = 99; // just to avoid repetetion
                } /* end if */
            } /* end for */
            handFace[ count ] = 99; // just to avoid repetetion

            if (pairNumber && same )
                printf_s( "%s", " and ");

            if ( same == 1 ) {
                pCard = 1;
                printf_s( "A pair: %ss of %s and %s", face[ pair ], suit[ s1 ], suit[ s2 ] ); 
            } /* end if */ 
            else if ( same == 2 ) {
                tCard = 1;
                printf_s( " Three: %ss of %s, %s and %s", face[ three ], suit[ s1 ], suit[ s2 ], suit[ s3 ] ); 
            }  /* end else if */  
            else if ( same == 3 ) {
                fCard = 1;
                printf_s( " Four: %ss of %s, %s, %s and %s", face[ four ], suit[ s1 ], suit[ s2 ], suit[ s3 ], suit[ s4 ] ); 
            } /* end else if */

            if (same)
                pairNumber++;

        } /* end for */

        if (pairNumber > 1 )
            printf_s( "; %d pairs \n", pairNumber );
        else if ( pairNumber) {
            if ( pCard ) 
                printf_s( "; one pair \n");
            else if ( tCard )
                printf_s( "; triple \n");
            else if ( fCard )
                printf_s( "; Fours \n");
        } /* end else if */

        for ( size_t i = 0; i < subscript; i++ ) {
            if ( handSuit[ i ] != handSuit[ i + 1]) {
                noFlush = 1;
            } /* end if */
        } /* end for */

        if ( !noFlush || !noStraight ) {
            printf_s( "%s", "a ");
            if ( !noFlush )
                printf_s( "%s", "flushy ");
            if ( !noStraight )
                printf_s( "%s", "straight ");
            printf_s( "%s", "hand\n");
        } /* end if */
        
        puts("");   
    } /* end if */

} /* end function hand */

void copy( int *copyFace, int *handFace ) {
    for ( size_t i = 0; i < HAND; i++ ) {
        copyFace[ i ] = handFace[ i ];
    } /* end for */
} /* end function copy */

void sort( int *copyFace, size_t size ) {

    for ( int pass = 1; pass < size; pass++ ){
        for ( size_t i = 0; i < size - pass; i++ ) {
            if ( copyFace[ i ] > copyFace[ i + 1 ]) {
                int hold = copyFace[ i ];
                copyFace[ i ] = copyFace[ i + 1 ];
                copyFace[ i + 1 ] = hold;
            } /* end if */
        } /* end for */
    } /* end for */
} /* end function sort */

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

    } /* end for */
} /* end function shuffle */
