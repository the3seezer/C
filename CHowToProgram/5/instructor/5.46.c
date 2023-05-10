/* 
 theBitRiddler
 5/10/2023
 4:06 PM
 What does it do?
*/
#include <stdio.h>
int main( void ) {
    int c = 0;

    if ( ( c = getchar() ) != EOF ) {
        main();
        printf_s( "%c", c );
    }

    return 0;
}