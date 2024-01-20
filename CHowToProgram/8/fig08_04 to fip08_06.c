/*
    theBitRiddler
    1/18/2024
    9:41 AM
    String-conversion functions
*/
#include <stdlib.h>
#include <stdio.h>
int main( void ) {

    /* fig08_04 
        strtod */

    const char *string = "51.2% are admitted";
    char *stringPtr = NULL;
    double d = strtod( string, &stringPtr );
    printf_s( "A string \"%s\" is converted to the\n", string );
    printf_s( "double value %.2f and a string \"%s\"\n\n", d, stringPtr );

    /* fig08_05
        strtol */

    const char * string2 = "-1234567abc";
    char * remainderPtr = NULL;

    long x = strtol( string2, &remainderPtr, 0 ); 

    printf_s( "%s\"%s\"\n%s%ld\n%s\"%s\"\n%s%ld\n\n",
    "The original string is ", string2,
    "The converted value is ", x,
    "The remainder of the original string is ", remainderPtr,
    "The converted value plus 567 is ", x + 567 );

    /* fig08_06 
        strtoul */

    const char * string3 = "1234567abc";
    char * remainderPtr3 = NULL;

    long x3 = strtoul( string3, &remainderPtr3, 0 );
    
    printf_s( "%s\"%s\"\n%s%lu\n%s\"%s\"\n%s%lu",
    "The original string is ", string3,
    "The converted value is ", x3,
    "The remainder of the original string is ", remainderPtr3,
    "The converted value minus 567 is ", x3 - 567 );
}