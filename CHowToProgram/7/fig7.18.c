/*
theBitRiddler
7/10/2023
12:35 AM
Demonstrating an array of pointers to functions.
*/
#include <stdio.h>

void function1( int a );
void function2( int b );
void function3( int c );

int main( void ) {
    void ( *f[ 3 ])( int ) = { function1, function2, function3 };

    printf_s( "%s", "Enter a number between 0 and 2, 3 to end ");
    int choice = 0;
    scanf_s( "%d", &choice );

    while ( choice >= 0 && choice < 3 ) {

        ( * f[ choice ])( choice );

        printf_s( "%s", "Enter a number between 0 and 2, 3 to end ");
        scanf_s( "%d", &choice );

    }

    puts( "program execution complete ");

}

void function1( int a ) {
    printf_s( "You entered %d so function1 was called \n", a );
}

void function2( int b ) {
    printf_s( "You entered %d so function2 was called \n", b );
}

void function3( int c ) {
    printf_s( "You entered %d so function3 was called \n", c );
}