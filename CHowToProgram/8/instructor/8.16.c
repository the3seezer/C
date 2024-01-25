#include <stdio.h>
#include <string.h>
int main( void ) {
    char text[80] = {'\0'}; // line of text
    char search[15] = "";   // search string
    char * searchPtr = "";  // pointer to a search string

    // Enter a line of text from user
    printf( "%s\n", "Enter a line of text: " );
    gets( text );

    // Enter a search string from user
    printf( "%s", "Enter a search string: " );
    gets( search );

    searchPtr = strstr( text, search );

    if ( searchPtr ) {
        printf( "%s\n%s\"%s\"\n%s\n",
        "The remainder to the line of text ",
        "beginning with the search string ", search, searchPtr );
        
        searchPtr = strstr( searchPtr + 1, search );

        if ( searchPtr ) {

            printf( "%s\n%s\"%s\"\n%s\n",
            "The remainder to the line of text ",
            "beginning with the search string ", search, searchPtr );

        } // end if
        else {
            printf( "%s\n", "The search string appeared only once." );
        } // end else

    } // end if
    else {
        printf( "\"%s\" %s\n", search, "is not found" );
    } // end else

    return 0; // indicate termination successful
} /* end main */