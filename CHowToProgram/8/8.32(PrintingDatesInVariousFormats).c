/*
    theBitRiddler
    2/6/2024
    11:06 PM
    8.32 (Printing Dates in Various Formats)
    07/21/2003 TO July 21, 2003
*/
#include <stdio.h>
int main( void ) {
    char date[11] = "";    // date input by user
    char *months[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int month = 0;
    int day = 0;
    int year = 0;

    printf( "%s\n", "Enter a date in this format: month/ day/ year: --/--/----: ");
    fgets( date, 11, stdin );

    size_t i = 0;   // date string controller
    sscanf( date, "%d", &month );
    // reallocate
    while( date[i] != '/' ) 
        i++; i++;
    sscanf( &date[i], "%d", &day );
    // reallocate
    while( date[i] != '/' ) 
        i++; i++;
    sscanf( &date[i], "%d", &year );

    printf( "\nDate is:\n%s %d, %d\n", months[month - 1], day, year );

    return 0; // indicate termination successful
} /* end main */