#include <stdio.h>
#include <math.h>
double strTod( const char *, char ** );
long strTol( const char *, char **, int );
unsigned long strToul( const char *, char **, int );
int main( void ) {
    char * string = " bachu8827899.778ABC";
    char * sPtr = "";
    double number = 0;
    number = strTod( string, &sPtr );
    printf( "%s%.4f\n%s%s\n", "The number is ", number, "The endPointer: ", sPtr );

    return 0; // indicate termination successful
} /* end main */
double strTod( const char * s, char ** endPtr ) {
    int i = 0; // counter
    double num = 0; // a number to be extrated from a string
    int d = 0; // a decimal flag
    endPtr = &s;

    while ( s[ i ] != '\0' ) {

        // Skip a string if it does'nt start with a digit character
        if ( !((int)s[ 0 ] >= 48 && (int)s[ 0 ] <= 57) && !num ) {
            // assign the pointer to a next location
            ++( *endPtr );
            i--; // prevent the location from double skipping
        } // end if

        // check if it's a digit
        if( ((int)s[i]) >= 48 && ((int)s[i]) <= 57 ) {
            if ( d == 0 ) {
                num *= 10;
                num += ((int)s[0] - 48 );

                // assign the pointer to a next location
                ++( *endPtr );
                i--; // prevent the location from double skipping
            } // end if
            else {
                num += ( ((int)s[0] - 48 ) / pow( 10, d++ ) );

                // assign the pointer to a next location
                ++( *endPtr );
                i--; // prevent the location from double skipping
            } // end if
  
        } // end if
        else if( num && s[0] == '.' && d == 0 ) {
            d = 1;

            // assign the pointer to a next location
            ++( *endPtr );
            i--; // prevent the location from double skipping
        } // end else if

       i++; 
    } // end while

    return num ? num : 0.00;
} /* end function strTod */
long strTol( const char * s, char ** endPtr, int base ) {

} /* end function strTol */
unsigned long strToul( const char *s, char ** endPtr, int base ) {

} /* end function strToul */