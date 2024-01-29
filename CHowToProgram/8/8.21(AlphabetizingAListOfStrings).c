#include <string.h>
#include <stdio.h>

#define TOWNS 15
int main( void ) {
    char * towns[15] = {
        "Dar es Salaam", "Morogoro", "Arusha", "Dodoma", "Tanga",
        "Zanzibar", "Mwanza", "Kigoma", "Tabora", "Lindi",
        "Mtwara", "Shinyanga", "Mbeya", "Bukoba", "Chake Chake"
    };
    size_t i = 0;      // path counter
    size_t j = 0;  // loop counter
    char * temp = "";  // pointet to a string in the array

    // display original strings
    printf( "%s\n", "The towns: ");
    for ( i = 0; i < TOWNS; i++ ) {
        puts(towns[i]);
    } // end for

    // alphabetize the towns by a comparing function
    for ( i = 1; i < TOWNS; i++ )
        for ( j = 0; j < TOWNS - i; j++ ) {
            if ( strcmp( towns[ j ], towns[ j + 1 ] ) == 1 ) {
                temp = towns[j];
                towns[j] = towns[j + 1];
                towns[j + 1] = temp;
            } // end if
        } // end for

    // display alphabetized strings
    printf( "\n%s\n", "The towns after alphabetizing: " );
    for ( i = 0; i < 15; i++ ) {
        puts(towns[i]);
    } // end for

    return 0; // indicate termination successful
} /* end main */