#include <stdio.h>
#include <math.h>
double strTod( const char *, char ** );
long strTol( const char *, char **, int );
unsigned long strToul( const char *, char **, int );
long toBase( long, int );
void display( char * );
void concat( char, char * );
int main( void ) {
    char * string = " -bachu889.78ABC";
    char * sPtr = "";
    double number = 0;
    number = strTod( string, &sPtr );
    printf( "%s%.3f\n%s%s\n\n", "The number is ", number, "The endPointer: ", sPtr );

    char * string2 = " -bachu-88298789.78ABC";
    char * sPtr2 = "";
    long number2 = 0;
    number2 = strTol( string2, &sPtr2, 10 );
    printf( "%s%ld\n%s%s\n\n", "The number is ", number2, "The endPointer: ", sPtr2 );

    char * string3 = " -bachu2859.78ABC";
    char * sPtr3 = "";
    unsigned long number3 = 0;
    number3 = strToul( string3, &sPtr3, 16 );
    printf( "%s%lu\n%s%s\n\n", "The number is ", number3, "The endPointer: ", sPtr3 );

    return 0; // indicate termination successful
} /* end main */
double strTod( const char * s, char ** endPtr ) {
    int i = 0; // counter
    double num = 0.0; // a number to be extrated from a string
    int d = 0; // a decimal flag
    int di = 0; // a digit flag
    int neg = 0; // a negative flag
    endPtr = &s;

    // check if there is any digit, if not return an empty 'num'
    while ( s[ i ] != '\0' ) {
        if ( (int)s[i] >= 48 && (int)s[i] <= 57 ) {
            di = 1;
        } // end if
        i++;
    } // end while
    if (!di)
        return num;

    i = 0;
    while ( s[ i ] != '\0' ) {

        // Skip a string if it does'nt start with a digit character
        if ( !((int)s[ 0 ] >= 48 && (int)s[ 0 ] <= 57) && !num ) {
            // assign the pointer to a next location
            ++( *endPtr );
            i--; // prevent the location from double skipping
        } // end if

        // check for a negative sign
        if ( s[ 0 ] == '-' && (((int)s[1]) >= 48 && ((int)s[1]) <= 57) && !num )
            neg = 1;

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

    return neg ? -num : num;
} /* end function strTod */
long strTol( const char * s, char ** endPtr, int base ) {
    int i = 0; // counter
    long num = 0.0; // a number to be extrated from a string
    int di = 0; // a digit flag
    int neg = 0; // a negative flag
    endPtr = &s;

    // check if there is any digit, if not return an empty 'num'
    while ( s[ i ] != '\0' ) {
        if ( (int)s[i] >= 48 && (int)s[i] <= 57 ) {
            di = 1;
        } // end if
        i++;
    } // end while
    if (!di)
        return num;

    i = 0;
    while ( s[ i ] != '\0' ) {

        // Skip a string if it does'nt start with a digit character
        if ( !((int)s[ 0 ] >= 48 && (int)s[ 0 ] <= 57) && !num ) {
            // assign the pointer to a next location
            ++( *endPtr );
            i--; // prevent the location from double skipping
        } // end if

        // check for a negative sign
        if ( s[ 0 ] == '-' && (((int)s[1]) >= 48 && ((int)s[1]) <= 57) && !num )
            neg = 1;

        // check if it's a digit, if not break
        if( ((int)s[i]) >= 48 && ((int)s[i]) <= 57 ) {

            num *= 10;
            num += ((int)s[0] - 48 );

            // assign the pointer to a next location
            ++( *endPtr );
            i--; // prevent the location from double skipping
  
        } // end if
        else if( num ) {
            break; 
        } // end else if

       i++; 
    } // end while

    return neg ? -(toBase(num, base )) : toBase(num, base);
} /* end function strTol */
unsigned long strToul( const char *s, char ** endPtr, int base ) {
    int i = 0; // counter
    unsigned long num = 0.0; // a number to be extrated from a string
    int di = 0; // a digit flag
    endPtr = &s;

    // check if there is any digit, if not return an empty 'num'
    while ( s[ i ] != '\0' ) {
        if ( (int)s[i] >= 48 && (int)s[i] <= 57 ) {
            di = 1;
        } // end if
        i++;
    } // end while
    if (!di)
        return num;

    i = 0;
    while ( s[ i ] != '\0' ) {

        // Skip a string if it does'nt start with a digit character
        if ( !((int)s[ 0 ] >= 48 && (int)s[ 0 ] <= 57) && !num ) {
            // assign the pointer to a next location
            ++( *endPtr );
            i--; // prevent the location from double skipping
        } // end if

        // check for a negative sign
        if ( s[ 0 ] == '-' && (((int)s[1]) >= 48 && ((int)s[1]) <= 57) && !num )
            break;

        // check if it's a digit, if not break
        if( ((int)s[i]) >= 48 && ((int)s[i]) <= 57 ) {

            num *= 10;
            num += ((int)s[0] - 48 );

            // assign the pointer to a next location
            ++( *endPtr );
            i--; // prevent the location from double skipping
  
        } // end if
        else if( num ) {
            break;
        } // end else if

       i++; 
    } // end while

    return toBase( num, base );
} /* end function strToul */
// Utilities
long toBase( long n, int b ) {
	int rem = 0;   // number remainder
	long number = n;  // incase it's untorched
	int i = 0;		// digit position
    char x = ' ';   // alpha digits
    char numX[100];  // alpha string

	if ( b == 0 )
        return n;
	else if ( b == 1 )
		return 0;
	else if( b >= 2 && b <= 10 ) {
		rem = n % b; // get a remainder
		n /= b;		// get a number after division
		number = rem;
		while ( n ) {
			i++;          // get the digit position
			rem = n % b; // get a new remainder
			n /= b;		// get a new number after division
			number += rem * pow( 10, i ); 
		} // end while
	} // end else if
    else if ( b >= 11 && b <= 36 ) { // A - Z
		if (n < b) { // if a number is simply less than its base
            if (  n > 9 ) {
                x = 'A' + (n - 10); // from A to b: i.e 10 == A 16 == F
                numX[0] = x;  // store the number string
            } // end if
            else {
                x = '0' + n;
                numX[0] = x;
            } // end else
			n /= b;
		} // end if
		else {
			rem = n % b; // get a remainder
			n /= b;     // get a number after division
			if ( rem > 9 ) {
				x = 'A' + (rem - 10); // from A to b
                numX[ 0 ] = x;   // store the remainder string
			} // end if
            else {
                x = '0' + rem;  // get a digit
                numX[0] = x;   // store the remainder string
            } // end else	
		} // end else
        while ( n ) {
            rem = n % b; // get a new remainder
            n /= b;		// get a new number after division
            if ( rem > 9 ) {
                x = 'A' + (rem - 10); // from A to F
                // And the character infront of the previous result
                concat( x, numX );
            } // end if
            else {
                x = '0' + rem;  // Add a digit
                // And the character infront of the previous result
                concat( x, numX );
            } // end else
        } // end while
        printf( "The answer: %s\n", numX );
        return number;
    } // end else if
		
	return number; // indicate termination successful
} /* end function toBase */
void display( char * s ) {
    for ( size_t i = 0; s[ i ] != '\0'; i++ )
        printf( "%c", s[ i ] );
    
    printf( "%s", "\n" );
} /* end function display */
void concat( char c, char * s ) {
    char copy = ' ';
    char paste = c;
    // get the length of the string
    int i = 0;
    while( s[i] != '\0' ){
        i++; 
    };
    // extend the terminating null character
    s[i] = ' '; 
    s[ i + 1 ] = '\0';
    // concatenate a character before a string
    i = 0;
    while( s[ i ] != '\0' ) {
        copy = s[ i ];
        s[ i ] = paste;
        paste = copy;
        i++;
    } // end while

    return;
} /* end function concat */