#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define SUITS 4
#define FACES 13
#define HAND 5
#define DRAWCARDS 3

void sort( int *copyFace, size_t size );
void copy( int *copyFace, int *handFace );
void cardValue( int * handFace );
void twoPairDraw( int * handFace, int * draw, int level );
void lowCardDraw( int * handFace, int * draw , int j, int level ); 

int main( void ) {
    int handFace[ HAND ] = { 99, 99, 99, 4, 99};
    int level = 0;
    int drawArray[ DRAWCARDS ] = { -1, -1, -1 };
    int j = 2;

    for ( size_t i = 0; i < HAND; i++ )
        printf_s( "%d ", handFace[ i ] );
            puts("");
    lowCardDraw( handFace, drawArray, j, level );

    for ( size_t i = 0; i < 3; i++ )
        printf_s( "%d ", drawArray[ i ] );

} // end main

void lowCardDraw( int * handFace, int * draw , int j, int level ) {
    int smallest = 13; // to find the low card
    if ( ( level == 0 || level == 1 ) ?  j < 3 : ( level == 2 || level == 4 ) ? j < 1 : j < 2 ) {
        for ( size_t i = 0; i < HAND; i++ ) 
            if ( handFace[ i ] < smallest ) { // any card less than ten
            smallest = handFace[ i ];
            } // end for
        for ( size_t i = 0; i < HAND; i++ )
            if ( handFace[ i ] == smallest ) {
                if ( handFace[ i ] < 8 ) { // if the card is less than ten
                    draw[ j++ ] = i;
                } // end if
                handFace[ i ] = 99; // to avoid repetition
            } // end if

        lowCardDraw( handFace, draw, j, level );
    } // end if

    for ( size_t i = 0; i < HAND; i++ )
        printf_s( "%d ", handFace[ i ] );
            puts("");
} /* end function lowCard */

void twoPairDraw( int * handFace, int * draw, int level ) {
    int copyFace[ HAND ] = { 0 };
    int j = 0; // draw counter
    int same1 = 0;
    int same2 = 0;
    copy( copyFace, handFace );
    cardValue( copyFace );

    for ( size_t count1 = 0; count1 < HAND; count1++ ) {
        same1 = 0;
        same2 = 0;
        for ( size_t count2 = 0; count2 < HAND; count2++ ) {
            if ( copyFace[ count1 ] == copyFace[ count2 ] && count1 != count2 && copyFace[ count2 ] != 99 ) {
                same1++;
                if ( same1 == 1 ) {
                    copyFace[ count2 ] = 99;
                } // end if 
            } // end if
            if ( copyFace[ count1 ] == copyFace[ count2 ] && count1 != count2 && copyFace[ count2 ] != 99 ) {
                same2++;
                if ( same2 == 1 ) {
                    copyFace[ count2 ] = 99;
                } // end if
            } // end if
        } // end for
        if ( same1 )
            copyFace[ count1 ] = 99;
        if ( same2 )
            copyFace[ count1 ] = 99;
    } // end for

    for ( size_t i = 0; i < HAND; i++ )
        printf_s( "%d ", copyFace[ i ] );

        puts("");

} /* end function twoPairDraw */

void cardValue( int * handFace ) {
    for ( size_t i = 0; i < HAND; i++ ) {
        if ( handFace[ i ] == 0 ) 
            handFace[ i ] = 12;
        else 
            --handFace[ i ];
    } // end for 
} /* end function cardValue */

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