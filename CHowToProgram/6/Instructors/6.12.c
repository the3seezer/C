/* 
 theBitRiddler
 5/15/2023
 11:50 AM
 Single statements
*/
#include <stdio.h>
int main( void ) {
    /* 6.12(a)*/
    int count[ 10 ] = {0};
    for ( size_t i = 0; i < 10; i++ )
        count[ i ] = 0;

    /* 6.12(b): Add one to each element of the array bonus */
    int bonus[ 15 ] = {0};
    for ( size_t i = 0; i < 15; i++ )
        ++bonus[ i ];

    /* 6.12(c)*/
    float monthlyTempelature[ 12 ] = {0};
    for ( size_t i = 0; i < 12; i++ )
        scanf_s( "%f", &monthlyTempelature[ i ] );

    /* 6.12(d): print in column format */
    int bestScores[ 5 ] = { 11, 45, 99, 20, 50 };
    for ( size_t i = 0; i < 5; i++ )
        printf_s( "%d\t", bestScores[ i ] );

}