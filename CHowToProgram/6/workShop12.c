#include <stdio.h>
void loop(int);
int main( void ) {
    for ( int i = 0; i < 8; i++ ) {
        printf_s( "%d", i );
    }
    puts("");

    int i = 0;
    loop( i );
}

void loop( int i ) {
    if ( i < 8) {
        printf_s( "%d", i );
        loop( ++i );
    }
}