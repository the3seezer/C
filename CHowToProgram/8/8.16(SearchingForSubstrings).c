#include <stdio.h>
#include <string.h>
int main( void ) {
    char text[100] = { '\0' };  // line of text by user
    char search[30] = "";          // search string by user
    char *searchPtr = "";       // search pointer

    printf( "%s\n", "Enter a line of text: " );
    gets( text );
    printf( "%s", "Enter a search string: " );
    gets( search );

    searchPtr = strstr( text, search );

    while( searchPtr != NULL ) {
        
        // print the remainder of the line of text beginning with the search string.
        printf( "%s\n%s\n", "the remainder of the line of text beginning "
                        "with the search string: ", searchPtr );
        
        searchPtr = strstr( searchPtr + 1, search );

    } // end while

    return 0; // indicate termination successful
} /* end main */