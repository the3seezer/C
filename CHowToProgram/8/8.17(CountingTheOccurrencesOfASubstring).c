#include <stdio.h>
#include <string.h>
int main( void ) {
    char text[4][100] = { '\0' };    // text input by user
    char search[15] = "";   // search input by user
    char * searchPtr = "";  // search pointer
    int count = 0;          // search string counter
    int i = 0;              // loop counter

    // Enter lines of text
    printf( "%s\n", "Enter three lines of text: " );
    for ( i = 0; i <= 3; i++ ) {
        printf( "%s\n", "Enter a line of text..." );
        gets( text[ i ] );
    } // end for

    // Enter a search string
    printf( "%s", "Enter a search string: " );
    gets( search );

    for ( i = 0; i < 4; i++ ) {
        // Enter a line of text to strstr to search
        searchPtr = strstr( text[ i ], search );

        while ( searchPtr != NULL ) {
            count++;

            // print the remainder of the line of text beginning with the search string.
            printf( "\n%s\n%s\"%s\"\n%s\n",
                "The remainder to the line of text ",
                "beginning with the search string ", search, searchPtr );
            
            searchPtr = strstr( searchPtr + 1, search );
            
        } // end while
    } // end for

    if ( !count ) {
        printf( "\n\"%s\" %s\n", search, "is not found" );
    } // end if
    else if ( count == 1 ) {
        printf( "\n\"%s\" %s\n", search, "appeared only once" );
    } // end else if
    else {
        printf( "\n\"%s\" %s %d %s\n", search, "appeared", count, "times" );
    } // end else

    return 0; // indicate termination successful
} /* end main */