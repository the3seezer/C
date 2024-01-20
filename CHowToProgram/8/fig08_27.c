/*
    theBitRiddler
    1/19/2024
    2:22 PM
    Other functions of the String-Handling Library
        strlen
*/
#include <stdio.h>
#include <string.h>
int main( void ) {
    const char * string1 = "abcdefghijklmnopqrstuvwxyz";
    const char * string2 = "four";
    const char * string3 = "Boston";

    printf( "%s\"%s\"%s%zu\n%s\"%s\"%s%zu\n%s\"%s\"%s%zu\n",
    "The length of ", string1, " is ", strlen( string1 ),
    "The length of ", string2, " is ", strlen( string2 ),
    "The length of ", string3, " is ", strlen( string3 ) );
} /* end main */