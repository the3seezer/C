/* 
 theBitRiddler
 5/9/2023
 3:04 PM
 Can Main be incremented?
*/
#include <stdio.h>
int main( void ) {
    static int i = 0;

    printf( "%d\n", i );
    i++;
    
    main();

    return 0;
}