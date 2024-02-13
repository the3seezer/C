#include <stdio.h>
int main( void ) {
    char *digit[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
    char *teens[10] = { "TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FORTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINTEEN" };
    char *tens[10] = { "", "TEN", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINTY" };
    int dollar = 0; // check dollar amount
    int cents = 0; // check cents amount
    int digit1 = 0; // ones digit
    int digit2 = 0; // tens digit

    printf( "%s", "Enter check amount 0.00 to 99.99: " );
    scanf( "%d.%d", &dollar, &cents );
    printf( "\n%s", "Check amount in words is: " );

    if ( dollar < 10 ) {
        printf( "%s ", digit[dollar] );
    } // end if
    else if ( dollar < 20 ) {
        printf( "%s ", teens[dollar] );
    } // end else if
    else {
        digit1 = dollar % 10; // ones digit
        digit2 = dollar / 10; // tens digit

        if ( !digit1 ) {
            printf( "%s ", tens[dollar] );
        } // end if
        else {
            printf( "%s-%s", tens[digit2], digit[digit1] );
        } // end else
    } // end else

    printf( " and %d/100\n", cents );

} /* end main */