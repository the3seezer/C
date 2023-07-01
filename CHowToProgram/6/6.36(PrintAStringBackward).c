/* 
theBitRiddler
7/1/2023
9:00 AM
Print a strigh Backward
*/
#include <stdio.h>

#define SIZE 11

void reverseString( char string[], size_t );

int main( void ) {
    char name[ SIZE ] = { ' ' };

    printf_s( "%s", "Enter your name: ");
    gets( name );
    // scanf_s( "%10s", name, 11); its less efficient on spaces

    printf_s( "%s", "\nYour name printed backward\n");
    reverseString( name, 0);

    return 0;
} /* end main */

void reverseString( char string[], size_t n) {
    if ( string[ n ] == '\0' ) {
        return;
    }
    reverseString( string, n + 1 );
    printf_s( "%c", string[ n ]);
}
