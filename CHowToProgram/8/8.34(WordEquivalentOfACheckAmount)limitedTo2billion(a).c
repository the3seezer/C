/*
    theBitRiddler
    2/9/2024
    3:29 PM
    8.34(WordEquivalentOfACheckAmount)
    NOTE: This can be modified easily to any number
*/
#include <stdio.h>
#define MILLION 1000000
#define THOUSAND 1000
#define HUNDRED 100
#define TEN 10
int main( void ) {
    double check = 0.0;     // check input by user
    char *ones[10] = { "", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
    char *elevens[10 ] = { "", "ELEVEN", "TWELVE", "THIRTEEN", "FORTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINTEEN" };
    char *tens[ 10 ] = { "", "", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINTY" };
    int integer = 0;        // check in integer
    int decimal = 0;      // check in decimal
    int number = 0;         // a number template

    // Enter a check
    printf( "%s", "Enter a check (to a limit of millions): ");
    scanf( "%lf", &check );

    printf( "%s ", "The check is:" );
    integer = check; // get integer digits
    decimal = ( check - integer ) * 100; // get the decimal part and filter to two decimal places, then conver to integer

    // process into words
    if ( !integer )
        printf( " %s", "ZERO" );
    while( integer ) {
        if ( integer / MILLION )
            number = integer / MILLION;
        else if ( integer / THOUSAND ) // if integer is in thousands
            number = integer / THOUSAND;
        else if ( integer / HUNDRED ) // if integer is below thousand and in hundreds
            number = integer / HUNDRED;
        else 
            number = integer;
        
        if ( number >= 100 ) { // if number is in hundreds
            printf( " %s", ones[number / 100]);
            printf( " %s", "HUNDRED"); 
            if( number % 100 ) {
                if ( !( ( number % 100 ) / 10 ) && number % 10 )
                    printf( "%s", " AND");
                number %= 100;
            } // end if
                
        } // end if

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

        if ( integer / MILLION ) {
            printf( " %s", "MILLION" );
            if ( !( (integer % MILLION) / (MILLION/10) ) && integer % MILLION ) // If a number before millions is zero and after that there is a positive value; i.e 1,050,000
                printf( " %s", "AND" );
            integer %= MILLION;
        } // end if
        else if ( integer / THOUSAND ) {
            printf( " %s", "THOUSAND" ); // display thousand
            integer %= THOUSAND;
            if ( !( integer / (THOUSAND/10) ) && integer % (THOUSAND/10) ) // if a number before a thousand is zero and there is a positive value after it; i.e 1005
                printf( " %s", "AND" );
        } // end if 
        else if ( integer / HUNDRED ) {
            printf( " %s", "HUNDRED" );
            integer %= HUNDRED;
            if ( !(integer / TEN ) && integer % TEN ) // If a number before a hundred is zero and there is a positive value after it; i.e 105
                printf( " %s", "AND" );
        } // end else if
        else if ( integer % 100 )
            integer %= number;
        
    } // end while

    if ( decimal )
        printf( " and %d / 100", decimal );

    return 0; // indicate successful termination
} /* end main */