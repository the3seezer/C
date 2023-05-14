/* 
 theBitRiddler
 5/11/2023
 12/25 PM
 Modify the craps Program
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { WON, LOST, CONTINUE };

void chatter( void );
enum Status craps( void );
int rollDice( void );

int main( void ) {
    srand( time( NULL ) );

    enum Status results = WON;
    int bankBalance = 1000;
    int wager = 0;

    printf_s( "You have $%d in the bank \n"
    "Place your wage. ", bankBalance );
    scanf_s( "%d", &wager );

    while ( wager < 0 || wager > 1000 ) {
        printf_s( "%s", "Please bet a valid amount: " );
        scanf_s( "%d", &wager );
    } /* end while */

    results = craps();

    if ( results == LOST ) {

        bankBalance -= wager;
        printf_s( "Your new bank balance is %d.\n", bankBalance );

        if ( bankBalance == 0 ) {
            printf_s( "%s", "Sorry. You are busted! Thank you for playing.\n" );
        } /* end if */

    } /* end if */

    else {

        bankBalance += wager;
        printf_s( "Your new bank balance is %d.\n", bankBalance );
    } /* end else if */

    return 0;
    
} /* end function main */

enum Status craps( void ) {
    int sum = 0;
    int myPoint = 0;

    enum Status gameStatus = WON;
    
    sum = rollDice();
    switch ( sum ) {
        case 7: 
        case 11: 
            gameStatus = WON;
            chatter();
            break;

        case 2: 
        case 3: 
        case 12: 
            gameStatus = LOST;
            chatter();
            break;

        default: 
            gameStatus = CONTINUE;
            myPoint = sum;
            printf_s( "Point is %d\n", myPoint );
            chatter();
            break;

    } /* end switch */

    while ( gameStatus == CONTINUE ) {
        sum = rollDice();
        chatter();

        if (sum == myPoint ) {
            gameStatus = WON;
        } /* end if */

        else if ( sum == 7 ) {
            gameStatus = LOST;
        } /* end else if */

    } /* end while */

    if ( gameStatus == WON ) {
        printf_s( "%s", "Player wins\n" );
    } /* end if */
    else {
        printf_s( "%s", "Player loses\n" );
    } /* end else if */

    return gameStatus;

} /* end function craps */

int rollDice( void ) {
    int die1 = 0;
    int die2 = 0;
    int workSum = 0;

    die1 = 1 + rand() % 6;
    die2 = 1 + rand() % 6;
    workSum = die1 + die2;

    printf_s( "Player rolled %d + %d = %d\n", die1, die2, workSum );

    return workSum;

} /* end function rollDice */


void chatter( void ) {
    int select = 0;
    select = 1 + rand() % 6;

switch ( select ) { 

 case 1:
 printf( "Oh, you're going for broke, huh?\n" );
 break; /* exit switch */

 case 2:
 printf( "Aw cmon, take a chance!\n" );
 break; /* exit switch */
 
 case 3:
 printf( "Hey, I think this guy is going to break the bank!!\n" );
 break; /* exit switch */
 
 case 4:
 printf( "You're up big. Now's the time to cash in your chips!\n" );
 break; /* exit switch */
 
 case 5:
 printf( "Way too lucky! Those dice have to be loaded!\n" );
 break; /* exit switch */
 
 case 6:
 printf( "Bet it all! Bet it all!\n" );
 break; /* exit switch */
 
 default:
 break; /* exit switch */
 } /* end switch */

} /* end function chatter */