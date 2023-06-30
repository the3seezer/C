/* 
theBitRiddler
6/29/2023
6:16 PM
Palindromes
*/
#include <stdio.h>

#define MAX 100

int palindrome(char [], size_t, size_t );

int main( void ) {
    char expression[MAX] = {' '};
    char copyExpres[MAX] = {' '};
    char c = ' ';
    int count = 0;
    int copyCount = 0;

    printf_s( "%s", "Enter a sentense\n");

    while( (c = getchar() ) != '\n' && count < MAX ) {
        expression[ count++ ] = c;
    } /* end while */

    expression[ count ] = '\0';

   for ( copyCount = 0, count = 0; expression[ count ] != '\0' ; count++ ) {
        if ( expression[ count ] != ' ') {
            copyExpres[ copyCount++ ] = expression[ count ];
        } /* end if */
   } /* end for */

   if ( palindrome(copyExpres, 0, copyCount - 1) ) {
        printf_s( "%s", "is a palindrome\n");
   } /* end if */
   else {
        printf_s( "%s", "is not a palindrome\n");
   } /* end if */
} /* end main*/

int palindrome(char array[], size_t left, size_t right) {

    if ( right == left || left > right ) {
        return 1;
    } /* end if */
    else if (array[ right ] != array[left]) {
        return 0;
    } /* end else if */
    else {
        return palindrome(array, left + 1, right - 1);
    }
}