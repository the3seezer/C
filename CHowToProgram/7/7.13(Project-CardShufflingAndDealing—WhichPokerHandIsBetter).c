/*
theBitRiddler
7/22/2023
8:39 PM
(Project: Card Shuffling and Dealing—Which Poker Hand is Better?)
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
void betterHand( int *handFace, int * handSuit, int *handFace2, int *handSuit2 );
int no_royal( int *, int );
int no_straight(int * , int );
int no_flush( int *, int );
void sort( int *handFace, size_t size );
void copy( int *copyFace, int * handFace);

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
    // first hand 
    int handFace[HAND] = { 0 };
    int handSuit[HAND] = { 0 };
    size_t subscript = 0; 
    // second hand
    int handFace2[HAND] = { 0 };
    int handSuit2[HAND] = { 0 };
    size_t subscript2 = 0;
    
    for ( int card = 1; card <= CARDS; card++ ) {
        for ( size_t row = 0; row < SUITS; row++ ) {
            for ( size_t column = 0; column < FACES; column++ ) {
                if ( deck[ row ][ column] == card ) {
                    if ( subscript == 5)
                        subscript = 0;
                    if ( subscript2 == 5 )
                        subscript2 = 0;
                    card % 2 ? hand( handFace, handSuit, subscript++, column, row, face, suit ) :
                    hand( handFace2, handSuit2, subscript2++, column, row, face, suit );

                   // find a better hand if subscrpt2 == 5

                } /* end if */
            } /* end for */
        } /* end for */
    } /* end for */
    
} /* end function deal */

void betterHand( int *handFace, int * handSuit, int *handFace2, int *handSuit2 ) {

} // end function betterhand

int no_royal( int * array, int subscript ) {
    for ( size_t i = 1; i < subscript; i++ ) {
            if( array[ i ] == (array[ i + 1 ] - 1) && array[ 0 ] == 0 && array[ 1 ] == 9 ) { 
                ;
            } /* end if */
            else 
                return 1;
        } /* end for */

        return 0;
} // end function no royal

// find a straight hand 
int no_straight( int * array , int subscript) {

        for ( size_t i = 0; i < subscript; i++ ) {
            // get the straight hand cards 
            if( array[ i ] == (array[ i + 1 ] - 1) ) { 
                ;
            } /* end if */
            else 
                return 1;
        } /* end for */

        return 0;
} // end function no straingt

int no_flush( int * array, int subscript ) {
    for ( size_t i = 0; i < subscript; i++ ) { // get the flush hand 
            if ( array[ i ] != array[ i + 1]) {
                return 1;
            } /* end if */
        } /* end for */

        return 0;
} // end function no flush

void hand(int *handFace, int *handSuit, size_t subscript, int column, int row, const char *face[], const char *suit[] ) {

    handFace[ subscript ] = column;
    handSuit[ subscript ] = row;
    int same = 0;
    int pair = 0, pCard = 0, s1 = 0, s2 = 0; // pair for the value of the face, pCard for a pair of similary cards, s1 and s2 the value of the suit of first and second similary cards
    int similaryNumber = 0; // number of group of similary cards
    int pairNumber = 0; // number of pairs
    int three = 0, tCard = 0, s3 = 0; // tCard for triple similary cards, s3 to keep track of a third similary card
    int four = 0, fCard = 0, s4 = 0; // fCard for four similary cards, s4 to  keep track of a four similary card
    int noFlush = 0; // to get a flush hand we need a no flush flag
    int noStraight = 0; // to get a straight hand we need a no straight flag 
    int noRoyal = 0; // get a no royal flag

    if ( subscript % 4 == 0 && subscript != 0 ) { 

        // check your hand
        for ( size_t i = 0; i < 5; i++ ) {
            printf_s( "%5s of %-8s %c", face[ handFace[ i ] ], suit[ handSuit[ i ] ], i < 5 == 0 ? ' ' : ' ' );
        } /* end for */
        puts("");

        // make an array to copy, sort and find a straight hand
        int copyFace[ HAND ] = {0};
        copy( copyFace, handFace );

        sort( copyFace, HAND );
        
        noStraight = no_straight(copyFace, subscript );

        noRoyal = no_royal( copyFace, subscript );

        // Reuse the copyFace array to copy and find similary cards
        copy( copyFace, handFace );

        // find the number of similary cards
        for ( size_t count = 0 ; count < HAND; count++ ) { 
            same = 0;
            pair = 0;
            three = 0;
            four = 0;

            for ( size_t count2 = 0; count2 < HAND; count2++) {
                if ( count != count2 && copyFace[count] == copyFace[ count2 ] && copyFace[count2] != 99 ) {
                    same++;
                    if ( same == 1 ) {
                        pair = copyFace[ count ]; // record the similary face
                        s1 = handSuit[ count ];  // record the similary face's first suit
                        s2 = handSuit[ count2 ]; // record the similary face's second suit
                    }
                    else if ( same == 2 ) {
                        three = copyFace[ count ]; // record the third similary face
                        s3 = handSuit[ count2 ]; // record the similary face's  third suit
                    }
                    else if ( same == 3 ) {
                        four = copyFace[ count ]; // record the fourth similary face
                        s4 = handSuit[ count2 ]; // record the similary face's fourth suit
                    }
                    copyFace[ count2 ] = 99; // asign maybe 99 just to avoid repetetion
                } /* end if */
            } /* end for */
            copyFace[ count ] = 99; // just to avoid repetetion

            if (similaryNumber && same )
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

            if (same )
                similaryNumber++;
            
            if ( same == 1 )
                pairNumber++;

        } /* end for */

        if (pairNumber == 2 )
            printf_s( "; two pairs \n" ); // two pairs
        else if ( similaryNumber) {
            if ( pCard && similaryNumber == 1 ) 
                printf_s( "; one pair \n");
            else if ( tCard && similaryNumber == 2 )
                printf_s( "; full house \n" );           
            else if ( tCard )
                printf_s( "; three of a kind \n");
            else if ( fCard )
                printf_s( "; Four of a kind \n");
        } /* end else if */

        noFlush = no_flush(handSuit, subscript );

        if ( !noFlush || !noStraight || !noRoyal ) {
            printf_s( "%s", "a ");
            if ( !noRoyal /*&& !noFlush*/ )
                printf_s( "%s", "royal *flush");
            if ( !noStraight && !noFlush )
                printf_s( "%s", "straight flush");
            else if ( !noStraight )
                printf_s( "%s", "straight ");
            else if ( !noFlush )
                printf_s( "%s", "flush ");
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