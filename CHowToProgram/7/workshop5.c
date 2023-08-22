#include <stdio.h>
#define HAND 5
void onePair( int * handFace1, int *handFace2 );
void twoPair( int * handFace1, int * handFace2 );
void aHighCard( int *, int * );
int highCard( int * array , size_t size );
void sort( int *copyFace, size_t size );
void copy( int *copyFace, int *handFace );
void cardValue( int * handFace );
void threeOfAKind( int * handFace1, int * handFace2 );

int main( void ) {
    int copyFace1[ 5 ] = { 0, 0, 0, 5, 6 };
    int copyFace2[ 5 ] = { 0, 0, 0, 2, 3 };

    threeOfAKind(copyFace1, copyFace2);
    // printf_s( "%d", highCard( copyFace1, HAND ) );
    // printf_s( "kicker1: %d and kicker2: %d \n", kicker1, kicker2 );
    // printf_s( "pair1_1 :%d pair1_2: %d\n", pair1_1, pair1_2 );
    // printf_s( "pair2_1 :%d pair2_2: %d\n", pair2_1, pair2_2 );
    // for ( size_t i = 0; i < 5; i++ )
    //     printf_s( "%3d", copyFace1[ i ]); puts("");
    // for ( size_t i = 0; i < 5; i++ )
    //     printf_s( "%3d", copyFace2[ i ]); puts("");

} // end main

void threeOfAKind( int * handFace1, int * handFace2 ) {
    int same1 = 0;
    int same2 = 0;
    int trips1 = 0; // get the value the triple cards in hand one 
    int trips2 = 0; // get the value the triple cards in hand two
    int copyFace1[ HAND ] = { 0 };
    int copyFace2[ HAND ] = { 0 };
    copy( copyFace1, handFace1 );
    copy( copyFace2, handFace2 );

    for ( size_t count = 0; count < HAND; count++ ) {
        same1 = 0;
        same2 = 0;
        for ( size_t count2 = 0; count2 < HAND; count2++ ) {
            if ( count != count2 && copyFace1[ count ] == copyFace1[ count2 ] && copyFace1[ count2] != -1 ) {
                same1++;
                if ( same1 == 2 )
                     trips1 = copyFace1[ count ];
                copyFace1[ count2 ] = -1;
            } // end if
            if ( count != count2 && copyFace2[ count ] == copyFace2[ count2 ] && copyFace2[ count2 ] != -1 ) {
                same2++;
                if ( same2 == 2 )
                    trips2 = copyFace2[ count ];
                copyFace2[ count2 ] = -1;
            } // end if 
        } // end for
        if ( same1 )
            copyFace1[ count ] = -1;
        if ( same2 ) 
            copyFace2[ count ] = -1;
    } // end for 

    sort( copyFace1, HAND );
    sort( copyFace2, HAND );

    if ( trips1 > trips2 )
        printf_s( "%s", "Hand one is better than hand two\n");
    if ( trips1 < trips2 )
        printf_s( "%s", "Hand two is better than hand one\n");
    if ( trips1 == trips2 )
        aHighCard(copyFace1, copyFace2);

} /* end function threeOfAKind */

void twoPair( int * handFace1, int * handFace2 ) {
    int same1 = 0; // get similary cards in hand one
    int same2 = 0; // get similary cards in hand two
    int pairNumber1 = 0; // number of pairs in hand one
    int pairNumber2 = 0; // number of pairs in hand two
    int pair1_1 = 0, pair1_2 = 0; // get value of similary cards in hand one of pair one and pair two
    int pair2_1 = 0, pair2_2 = 0; // get value of similary cards in hand two of pair one and pair two
    int kicker1 = 0;
    int kicker2 = 0;
    int copyFace1[ HAND ] = { 0 };
    int copyFace2[ HAND ] = { 0 };
    
    copy( copyFace1, handFace1);
    copy( copyFace2, handFace2);

    // get the similary cards
    for ( size_t count = 0; count < HAND; count++ ) {
        same1 = 0;
        same2 = 0;
        for ( size_t count2 = 0; count2 < HAND; count2++ ) {
            if ( count != count2 && copyFace1[ count ] == copyFace1[ count2 ] && copyFace1[ count2 ] != -1 ) {
                same1++;
                if ( same1 == 1 && !pairNumber1 ) 
                    pair1_1 = copyFace1[ count ];
                if ( same1 == 1 && pairNumber1 )
                    pair1_2 = copyFace1[ count ];
                copyFace1[ count2 ] = -1;
            } // end if
            if ( count != count2 && copyFace2[ count ] == copyFace2[ count2 ] && copyFace2[ count2 ] != -1 ) {
                same2++;
                if ( same2 == 1 && !pairNumber2 )
                    pair2_1 = copyFace2[ count ];
                if ( same2 == 1 && pairNumber2 )
                    pair2_2 = copyFace2[ count ];
                copyFace2[ count2 ] = -1;
            } // end if
        } // end for 
        if ( same1 ) {
            pairNumber1++;
            copyFace1[ count ] = -1;
        } // end if 
        if ( same2 ) {
            pairNumber2++;
            copyFace2[ count ] = -1;
        } // end if 
    } // end for 

    if ( pair1_2 > pair2_2 )
        printf_s( "%s", "Hand one is better than hand two\n");
    if ( pair1_2 < pair2_2 )
        printf_s( "%s", "Hand two is better than hand one\n");
    if ( pair1_2 == pair2_2 ) {
        if ( pair1_1 > pair2_1 )
            printf_s( "%s", "Hand one is better than hand two\n");
        if ( pair1_1 < pair2_1 )
            printf_s( "%s", "Hand two is better than hand one\n");
        if ( pair1_1 == pair2_1 ) {
            kicker1 = highCard(copyFace1, HAND );
            kicker2 = highCard(copyFace2, HAND );
            if ( kicker1 > kicker2 ) 
                printf_s( "%s", "Hand one is better than hand two\n");
            if ( kicker1 < kicker2 )
                printf_s( "%s", "Hand two is better than hand one\n");
            if ( kicker1 == kicker2 )
                printf_s( "%s", "It's a tie\n");
        } // end else if
    } // end if 
    
} /* end function twoPair */

void cardValue( int * handFace ) {
    for ( size_t i = 0; i < HAND; i++ ) {
        if ( handFace[ i ] == 0 ) 
            handFace[ i ] = 12;
        else 
            --handFace[ i ];
    } // end for 
} /* end function cardValue */

int highCard( int * array , size_t size ) {
    int high = 0; // get the high card
    for ( size_t i = 0; i < size; i++ ) 
        if ( array[ i ] > high )
            high = array[ i ];

    return high;
} /* end function highCard */

void onePair( int * handFace1, int *handFace2 ) {
    int same1 = 0; // get similary cards in hand one
    int same2 = 0; // get similary cards in hand two
    int s1 = 0; // get value of similary cards in hand one
    int s2 = 0; // get value of similary cards in hand two
    
    // get the similar cards
    for ( size_t count = 0; count < HAND; count++ ) {
        same1 = 0;
        same2 = 0;
        for ( size_t count2 = 0; count2 < HAND; count2++ ) {
            if ( count != count2 && handFace1[ count ] == handFace1[ count2 ] && handFace1[ count2 ] != -1 ) {
                same1++;
                if ( same1 == 1) {
                    s1 = handFace1[ count ];
                    printf_s( "s1 %d\n", s1);
                } // end if
                handFace1[ count2 ] = -1; // eliminate the pairs, incase we look for the highiest kicker and avoid repetition
            } // end if
            if ( count != count2 && handFace2[ count ] == handFace2[ count2 ] && handFace2[ count2 ] != -1 ) {
                same2++;
                if ( same2 == 1 ) {
                    s2 = handFace2[ count ];
                    printf_s( "s2 %d\n", s2);
                } 
                handFace2[ count2 ] = -1; // eliminate the pairs, incase we look for the highiest kicker and avoid repetition
            } // end if
        } // end for
        if ( same1 ) 
            handFace1[ count ] = -1; // eliminate the pairs, incase we look for the highiest kicker and avoid repetition
        if ( same2 )
            handFace2[ count ] = -1; // eliminate the pairs, incase we look for the highiest kicker and avoid repetition
    } // end for 

    if ( s1 > s2 )
        printf_s( "%s", "Hand one is better than hand two\n");
    if ( s1 < s2 )
        printf_s( "%s", "Hand two is better than hand one\n");
    if ( s1 == s2 ) {
        sort( handFace1, HAND );
        sort( handFace2 , HAND );
        for ( size_t i = 0; i < HAND; i++ )
            printf_s( "%3d", handFace1[ i ]); puts("");
        for ( size_t i = 0; i < HAND; i++ )
            printf_s( "%3d", handFace2[ i ]); puts("");
        aHighCard( handFace1, handFace2 );
    } // end if
} /* end function onePair */

void aHighCard( int * handFace1, int * handFace2 ) {
    static int subscript = 4;
    if ( handFace1[ subscript ] == handFace2[ subscript ] ) {
        subscript--;
        aHighCard( handFace1, handFace2 );
    }
    else {
        if ( handFace1[ subscript ] > handFace2[ subscript ] && subscript >= 0) 
            printf_s( "%s", "Hand one is better than hand two\n" );
        else if ( handFace1[ subscript ] < handFace2[ subscript ] && subscript >= 0)
            printf_s( "%s", "Hand two is better than hand one\n" );
        else
            printf_s( "%s", "It's a tie!\n");
    } // end else 
    
} /* end function aHighCard */

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

void copy( int *copyFace, int *handFace ) {
    for ( size_t i = 0; i < HAND; i++ ) {
        copyFace[ i ] = handFace[ i ];
    } /* end for */
} /* end function copy */