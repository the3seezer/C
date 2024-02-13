/*
    theBitRiddler
    2/9/2024
    3:29 PM
    8.34(WordEquivalentOfACheckAmount)
*/
#include <stdio.h>
int main( void ) {
    double check = 0.0;     // check input by user
    char *ones[10] = { "", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
    char *elevens[10 ] = { "", "ELEVEN", "TWELVE", "THIRTEEN", "FORTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINTEEN" };
    char *tens[ 10 ] = { "", "", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINTY" };
    int integer = 0;        // check in integer
    int decimal = 0;      // check in decimal
    int number = 0;         // a number template

    // Enter a check
    printf( "%s", "Enter a check: less than or equal to 99999.99: ");
    scanf( "%lf", &check );

    printf( "%s ", "The check is:" );
    integer = check; // get integer digits
    decimal = ( check - integer ) * 100; // get the decimal part and filter to two decimal places, then conver to integer

    // process into words
    if ( !integer )
        printf( " %s", "ZERO" );
    while( integer ) {
        if ( integer / 1000 ) // if integer is in thousands
            number = integer / 1000;
        else if ( integer / 100 ) // if integer is below thousand and in hundreds
            number = integer / 100;
        else 
            number = integer;

        // process the number to words
        if ( number >= 1 && number <= 19 ) // number is btn 1 and 19
            if ( number >= 1 && number <= 9 )
                printf( " %s", ones[number] );
            else if( number >= 11 && number <= 19 )
                printf( " %s", elevens[number - 10] );
            else 
                printf( " %s", "TEN");
        else if ( number >= 20 && number <= 99 ) { // else if number is btn 20 and 99
            if ( number / 10 )
                printf( " %s", tens[ number / 10 ] );
            if ( number % 10 )
                printf( " %s", ones[ number % 10 ] );
        } // end else if        

        if ( integer / 1000 ) {
            printf( " %s", "THOUSAND" ); // display thousand
            integer %= 1000;
            if ( !( integer / 100 ) && integer % 100 )
                printf( " %s", "AND" );
        } // end if 
        else if ( integer / 100 ) {
            printf( " %s", "HUNDRED" );
            integer %= 100;
            if ( !(integer / 10) && integer % 10 )
                printf( " %s", "AND" );
        } // end else if
        else if ( integer % 100 )
            integer %= number;
        
    } // end while

    printf( " and %d / 100", decimal );

    return 0; // indicate successful termination
} /* end main */