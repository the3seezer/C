/*
    theBitRiddler
    1/18/2024
    11/19 AM
    Standard input / output library functions
        fgets and putchar
*/
#include <stdio.h> 

#define SIZE 80
void reverse( const char * const sPtr );
int main( void ) {

   char sentence[SIZE] = "";

   puts( "Enter a line of text: ");
   fgets( sentence, SIZE, stdin );

   printf( "%s", "The line printed backward is: ");
   reverse( sentence );
   puts("");

} /* end main */

void reverse( const char * const sPtr ) {

    if ( sPtr[ 0 ] == '\0' ) {
        return;
    } // end if
    else {
        reverse( &sPtr[ 1 ] );
        putchar( sPtr[ 0 ] );
    } // end else

} /* end function reverse */