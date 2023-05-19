 /* Exercise 6.20 Solution */
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

 enum Outcome { CONTINUE, WIN, LOSE };

 int rollDice( void ); /* function prototype */

 int main()
 { 
 enum Outcome gameStatus; /* game status indicator */
 int sum; /* sum of rolled dice */
 int myPoint; /* current point */
 int i; /* game counter */
 int roll; /* roll counter */
 int length = 0; /* average length of game */
 int wins[ 22 ] = { 0 }; /* wins per roll */
 int losses[ 22 ] = { 0 }; /* losses per roll */
 int winSum = 0; /* total wins */
 int loseSum = 0; /* total losses */

 srand( time( NULL ) );
 
 /* play 1000 times */
 for ( i = 1; i <= 1000; i++ ) { 
    sum = rollDice();
    roll = 1;

 /* test if game won or lost on first roll */
    switch ( sum ) { 

        case 7: 
        case 11:
        gameStatus = WIN;
        break; /* exit switch */
        
        case 2: 
        case 3: 
        case 12:
        gameStatus = LOSE;
        break; /* exit switch */
        
        default:
        gameStatus = CONTINUE;
        myPoint = sum;
        break; /* exit switch */
    } /* end switch */

    /* continue while game not won or lost */
    while ( gameStatus == 0 ) { 
        sum = rollDice();
        roll++;

    /* win on next roll */
        if ( sum == myPoint ) {
            gameStatus = WIN;
        } 
        else { /* lose on next roll */

            if ( sum == 7 ) {
                gameStatus = LOSE;
            } /* end if */

        } /* end else */

    } /* end while */
 
 /* if more than 21 rolls taken, set number of rolls to 21 */
    if ( roll > 21 ) {
        roll = 21;
    } /* end if */
 
 /* determine how many rolls were taken and increment
 corresponding counter in wins or losses array */
    if ( gameStatus == WIN ) { 
        wins[ roll ]++;
        winSum++;
    } /* end if */
    else { 
        losses[ roll ]++;
        loseSum++;
    } /* end else */

 } /* end for */
 
 printf( "Games won or lost after the 20th roll\n"
 "are displayed as the 21st roll.\n\n" );

 /* display number of games won and lost for each number of rolls */
 for ( i = 1; i <= 21; i++ ) {
    printf( "%3d games won and %3d games lost on roll %d.\n", 
    wins[ i ], losses[ i ], i );
 } /* end for */

 /* calculate chances of winning */
 printf( "\nThe chances of winning are %d/%d = %.2f%%\n", winSum,
 winSum + loseSum, 100.0 * winSum / ( winSum + loseSum ) );
 
 /* calculate average length of game */
 for ( i = 1; i <= 21; i++ ) {
    length += wins[ i ] * i + losses[ i ] * i;
 } /* end for */

 printf( "The average game length is %.2f rolls.\n", 
 length / 1000.0 );

 return 0; /* indicate successful termination */

 } /* end main */

 /* function to simulate dice rolling */
 int rollDice( void )
 { 
 int die1; /* first die */
 int die2; /* second die */
 int workSum; /* dice sum */

 die1 = 1 + rand() % 6;
 die2 = 1 + rand() % 6;
 workSum = die1 + die2;

 return workSum; /* return total of two dice */

 } /* end function rollDice */