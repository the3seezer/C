#include <stdio.h>
#include <string.h>
int main( void ) {
    char text[3][80] = {'\0'};
    char * temp = "";           // token pointer
    char words[100][20] = {'\0'};
    int count[100] = {0};   // words count
    int j = 0;              // counter

    printf( "%s\n", "Enter three lines of text" );
    for ( size_t i = 0; i <= 2; i++ ) {
        gets( &text[i][0] );
    } // end for

    // loop through all the lines
    for ( size_t i = 0; i < 3; i++ ) {

        temp = strtok( &text[i][0], ". \n" );

        while( temp != NULL ) {
            // loop through the word for comparison
            for ( j = 0; words[j][0] && strcmp( &words[j][0], temp ) != 0; j++ );

            ++count[j];

            // if temp wasn't found in words
            if ( !words[j][0] ) {
                strcpy( &words[j][0], temp);
            } // end if

            temp = strtok( NULL, ". \n" );
        } // end while

    } // end for

    // display the results
    for ( size_t i = 0; words[i][0] != '\0' && i <= 99; i++ ) {
        printf( "%s appeared %d time%s\n",
        words[i], count[i], count[i] == 1 ? "" : "s" ); 
    } // end for

    return 0; // indicate successful termination
} /* end main */