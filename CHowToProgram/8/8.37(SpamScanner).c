/*
    theBitRiddler
    3/6/2024
    7:23 PM
    8.37 (Spam Scanner)
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 150
#define SPAMS 30
int main( void ) {
    double spamScore = 0;
    char * spams[SPAMS] = {
        "are", "binance", "bound", "buy", "call", "cost", "email", "excited", "find", "follow", "get", "have", "invest",
        "limit", "miss", "mining", "never", "no", "opportunity", "offer",
        "profit", "reach", "register", "rich", "subscribe", "us", "welcome", "win", "won", "you"
    };

    // get the email message
    char email[SIZE] = "";
    do {
        printf( "%s %d: ", "Enter an email with letters not greater than", SIZE - 50 );
        gets(email);
    }
    while ( strlen( email ) > SIZE - 50 );
    
    // convert to lowercases
    for( size_t i = 0; i < SIZE; i++ ) {
        email[i] = tolower( email[i] );
    } // end for

    // look for spam words
    for ( size_t i = 0; i < SPAMS; i++ ) {
        if ( strstr( email, spams[i] ) != NULL ) {
            spamScore++;
        } // end if
    } // end for

    printf( "%s %lf percent\n", "Spam rate is: ", (spamScore / SPAMS) * 100 );

} /* end main */