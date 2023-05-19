/*
 theBitRiddler
 5/19/2023
 9:21 AM
 Game of craps, 1000 times
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Outcome { CONTINUE, WIN, LOSE };

int rollDice( void );

int main( void ) {
    srand( time( NULL ) );
    enum Outcome gameStatus = WIN;
    int roll = 0;
    int sum = 0;
    int myPoint = 0;
    int length = 0;
    int wins[ 22 ] = {0};
    int losses[ 22 ] = {0};
    int winSum = 0;
    int loseSum = 0;

    for ( size_t i = 0; i < 1000; i++ ) {
        sum = rollDice();
        roll = 1;

        switch( sum ) {
            case 7:
            case 11:
                gameStatus = WIN;
                break;
            
            case 2:
            case 3:
            case 12:
                gameStatus = LOSE;
                break;
            
            default:
                gameStatus = CONTINUE;
                myPoint = sum;
                break;
        } /* end switch */

        while( gameStatus == CONTINUE ) {
            sum = rollDice();
            roll++;

            if ( myPoint == sum ) {
                gameStatus = WIN;   
            } /* end if */
            else if ( sum == 7 ) {
                gameStatus = LOSE;
            } /* end else if */

        } /* end while */

        if ( roll > 21 ) {
            roll = 21;
        } /* end if */

        if ( gameStatus == WIN ) {
            ++wins[ roll ];
            ++winSum;
        } /* end if */
        else {
            ++losses[ roll ];
            ++loseSum;
        } /* end else */

    } /* end for */

    printf_s( "%s", "Games won or lost after the 20th roll\n"
                 "are displayed as the 21st roll.\n\n" );

    for ( size_t i = 1; i <= 21; i++ )
        printf_s( "%3d games lost and %3d games won on roll %d\n", losses[ i ], wins[ i ], i );

    printf_s( "The chances of winning are %d / %d = %.2f%%\n", winSum, loseSum + winSum, 100.0 * winSum / ( loseSum + winSum ) );

    for ( size_t i = 1; i <= 21; i++ )
        length += wins[ i ] * i + losses[ i ] * i;

    printf_s( "The average game length is %.2f rolls.\n",
        length / 1000.0 );

    return 0;

} /* end main */

int rollDice( void ) {
    int die1 = 0;
    int die2 = 0;
    int workSum = 0;

    die1 = 1 + rand() % 6;
    die2 = 1 + rand() % 6;
    workSum = die1 + die2;

    return workSum;
} /* end function rollDice */
