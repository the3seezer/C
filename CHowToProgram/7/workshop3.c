/*
theBitRiddler
7/10/2023
7:21 PM
(Project: Card Shuffling and Dealing—Which Poker Hand is Better?)
    Hand ranks and the return value I gave them in the handRanking Function:
    1. royal_flush = 22;
    2. straight_flush = 21;
    3. four_of_a_kind = 20;
    4. full_house = 19;
    5. flush = 18;
    6. straight = 17;
    7. three_of_a_kind = 16;
    8. two_pair = 15;
    9. pair = 14;
    10. a high card 
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
void betterHand( int *handFace1, int * handSuit1, int *handFace2, int *handSuit2, int ( *handRankingP) ( int *handFace, int *handSuit ) );
int handRanking( int *handFace, int * handSuit );
void tieCheck( int *, int *, int );
int highCard( int * , size_t size );
int getRoyal( int * );
int noStraight(int * , int );
int noFlush( int *, size_t );
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

                    if ( subscript2 == 5 ) {
                        betterHand(handFace, handSuit, handFace2, handSuit2, handRanking );
                    } /* end if */
                } /* end if */
            } /* end for */
        } /* end for */
    } /* end for */  
} /* end function deal */

void tieCheck( int * handFace1, int * handFace2, int rank ) {
    // prototypes
    void straightFlush( int *, int * );
    void fourOfAKind( int * , int *);
    void fullHouse( int *, int * );
    void flush( int *, int * );
    void straight( int *, int * );
    void threeOfAKind( int *, int * );
    void twoPair(int *, int * );
    void onePair( int *, int * );
    void aHighCard( int *, int * );

    // get the array to copy the original 
    int copyFace1[ HAND ] = { 0 };
    int copyFace2[ HAND ] = { 0 };

    if ( rank < 14 )
        rank = 0;
    else  
        rank -= 13;

    void ( * betterTie[ 9 ]) (int * handFace1, int * handFace2 ) = { aHighCard, onePair, twoPair, threeOfAKind, straight, flush,
                                                   fullHouse, fourOfAKind, straightFlush };

    if ( rank == 0 ) {
        copy( copyFace1, handFace1);
        copy( copyFace2, handFace2);
        sort( copyFace1, HAND ); sort( copyFace2, HAND );
        (* betterTie[ rank ] ) ( copyFace1, copyFace2 );
    } /* end if */

} /* end function tieCheck */

void aHighCard( int * handFace1, int * handFace2 ) {
    int subscript = 4;
    if ( handFace1[ subscript ] == handFace2[ subscript ] && subscript >= 0 ) {
        subscript--;
        aHighCard( handFace1, handFace2 );
    }
    if ( subscript >= 0 ) {
        if ( handFace1[ subscript ] > handFace2[ subscript ] ) 
            printf_s( "%s", "Hand one is better than hand two\n" );
        if ( handFace1[ subscript ] < handFace2[ subscript ] )
            printf_s( "%s", "Hand two is better than hand one\n" );
        return ;
    }
    printf_s( "%s", "It's a tie!\n" );
    return ;
} /* end function aHighCard */

void onePair( int * handFace1, int *handFace2 ) {

} /* end function onePair */

void twoPair( int * handFace1, int * handFace2 ) {

} /* end function twoPair */

void threeOfAKind( int * handFace1, int * handFace2 ) {

} /* end function threeOfAKind */

void straight( int * handFace1, int * handFace2 ) {

} /* end function straight */

void flush( int * handFace1, int * handFace2 ) {

} /* end function flush */

void fullHouse( int * handFace1, int * handFace2 ) {

} /* end function fullHouse */

void fourOfAKind( int * handFace1, int * handFace2 ) {

} /* end function fullHouse */

void straightFlush( int * handFace1, int * handFace2 ) {

} /* end function straightFlush */

void betterHand( int *handFace1, int * handSuit1, int *handFace2, int *handSuit2, int ( *handRankingP ) ( int *handFace, int *handSuit ) ) {
    int rank1 = 0;
    int rank2 = 0;
    void (* tie ) ( int * , int * , int ) = tieCheck;
    
    // High card to be found in the handRanking Function
    rank1 = ( * handRankingP ) ( handFace1, handSuit1 );
    rank2 = ( * handRankingP ) ( handFace2, handSuit2 );
    if ( rank1 > rank2 ) {
        printf_s("Hand one: %d is better than hand two: %d\n", rank1, rank2);
    }
    else if ( rank1 < rank2 ) {
        printf_s("Hand two: %d is better than hand one: %d\n", rank2, rank1 );
    }
    else if ( rank1 == rank2 ) {
        if ( rank1 == 22 )
            printf_s("It's a tie: %d\n", rank1 );
        else
            ( * tie ) ( handFace1, handFace2, rank1);
    }// end else if 

    puts("");

} // end function betterhand

int handRanking( int *handFace, int * handSuit ) {
    int same = 0; // similary cards
    int pair = 0, pCard = 0, s1 = 0, s2 = 0; // pair for the value of the face, pCard for a pair of similary cards, s1 and s2 the value of the suit of first and second similary cards
    int similaryNumber = 0; // number of group of similary cards
    int pairNumber = 0; // number of pairs
    int three = 0, tCard = 0, s3 = 0; // tCard for triple similary cards, s3 to keep track of a third similary card
    int four = 0, fCard = 0, s4 = 0; // fCard for four similary cards, s4 to  keep track of a four similary card
    int no_flush = 0; // to get a flush hand we need a no flush flag
    int no_straight = 0; // to get a straight hand we need a no straight flag 
    int royal = 0; // get a royal hand
    int my_rank = 0; // a rank to be returned 
    int copyFace[ HAND ] = { 0 }; // copy the original array to manipulate the copy

    copy(copyFace, handFace);
    sort(copyFace, HAND );

    royal = getRoyal( copyFace );

    no_flush = noFlush( handSuit, HAND - 1 );

    no_straight = noStraight(copyFace, HAND - 1 );

    // find the number of similary cards
    copy(copyFace, handFace);
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

        if ( same == 1 ) {
            pCard = 1;
        } /* end if */ 
        else if ( same == 2 ) {
            tCard = 1;
        }  /* end else if */  
        else if ( same == 3 ) {
            fCard = 1;
        } /* end else if */

        if ( same )
            similaryNumber++;
            
        if ( same == 1 )
            pairNumber++;

    } /* end for */
    // get the royal flush
    if ( !no_flush && royal )
        my_rank = 22;
    // get the straight flush
    else if ( !no_straight && !no_flush )
        my_rank = 21;
    // get Four of a kind
    else if ( fCard )
        my_rank = 20;
    // get full house 
    else if ( pCard && tCard )
        my_rank = 19;
    // get flush
    else if ( !no_flush ) 
        my_rank = 18;
    // get straight
    else if ( !no_straight ) 
        my_rank = 17;
    // get three of a kind
    else if ( tCard && similaryNumber == 1 )
        my_rank = 16;
    // get two pair
    else if ( pairNumber == 2 )
        my_rank = 15;
    // get a pair
    else if ( pairNumber == 1 )
        my_rank = 14;
    // get a high card 
    else if ( my_rank < 14 ) 
        my_rank = highCard( handFace, HAND );
    // return the rank
    return my_rank;  
} /* end function handRanking */

int highCard( int * array , size_t size ) {
    int high = 0; // get the high card
    for ( size_t i = 0; i < size; i++ ) 
        if ( array[ i ] > high )
            high = array[ i ];

    return high;
} /* end function highCard */

int getRoyal( int * array ) {
    // get the royal hand
        if ( array[ 0 ] == 0 && array[ 1 ] == 9 && array[ 2 ] == 10 && array[ 3 ] == 11 && array[ 4 ] == 12 )
            return 1;
        return 0;
} // end function no royal

// find a straight hand 
int noStraight( int * array , int subscript) {

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

int noFlush( int * array, size_t size ) {
    for ( size_t i = 0; i < size; i++ ) { // get the flush hand 
            if ( array[ i ] != array[ i + 1]) {
                return 1;
            } /* end if */
        } /* end for */

        return 0;
} // end function no flush

void hand(int *handFace, int *handSuit, size_t subscript, int column, int row, const char *face[], const char *suit[] ) {

    handFace[ subscript ] = column;
    handSuit[ subscript ] = row;
    int same = 0; // similary cards
    int pair = 0, pCard = 0, s1 = 0, s2 = 0; // pair for the value of the face, pCard for a pair of similary cards, s1 and s2 the value of the suit of first and second similary cards
    int similaryNumber = 0; // number of group of similary cards
    int pairNumber = 0; // number of pairs
    int three = 0, tCard = 0, s3 = 0; // tCard for triple similary cards, s3 to keep track of a third similary card
    int four = 0, fCard = 0, s4 = 0; // fCard for four similary cards, s4 to  keep track of a four similary card
    int no_flush = 0; // to get a flush hand we need a no flush flag
    int no_straight = 0; // to get a straight hand we need a no straight flag 
    int royal = 0; // get a royal hand

    if ( subscript % 4 == 0 && subscript != 0 ) { 
        handFace[ 0 ] = 0; handFace[ 1 ] = 1; handFace[ 2 ] = 2; handFace[ 3 ] = 3; handFace[ 4 ] = 6;
        // check your hand
        for ( size_t i = 0; i < 5; i++ ) {
            printf_s( "%5s of %-8s %c", face[ handFace[ i ] ], suit[ handSuit[ i ] ], i < 5 == 0 ? ' ' : ' ' );
        } /* end for */
        puts("");

        // make an array to copy, sort and find a straight hand
        int copyFace[ HAND ] = {0};
        copy( copyFace, handFace );

        sort( copyFace, HAND );
        
        no_straight = noStraight(copyFace, subscript );

        royal = getRoyal( copyFace );

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

            if ( same )
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

        no_flush = noFlush(handSuit, subscript );

        if ( !no_flush || !no_straight || royal ) {
            printf_s( "%s", "a ");
            if ( royal && !no_flush )
                printf_s( "%s", "royal flush\n");
            else if ( !no_straight && !no_flush )
                printf_s( "%s", "straight flush\n");
            else if ( !no_straight )
                printf_s( "%s", "straight \n");
            else if ( !no_flush )
                printf_s( "%s", "flush \n");
        } /* end if */
        
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