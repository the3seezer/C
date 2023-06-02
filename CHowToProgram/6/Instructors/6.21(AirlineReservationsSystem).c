/* 
 theBitRiddler
 5/23/2023
 9:59 PM
  (Airline Reservations System)
*/
#include <stdio.h>
#include <ctype.h>

int main( void ) {
    int i = 0;
    int firstClass = 1;
    int economy = 6;
    int choice = 0;
    int plane[ 11 ] = { 0 };
    char response[ 2 ] = { '0' };

    while ( i < 10 ) {
        printf_s( "\n%s\n%s", "Please type 1 for \'first class \' ",
        "Please type 2 for \'economy\' " );
        scanf_s( "%d", &choice );

        if ( choice == 1 ) {

            if ( !plane[ firstClass ] && firstClass <= 5 ) {
                printf_s( "Your seat assignment is %d\n", firstClass );
                plane[ firstClass++ ] = 1;
                i++;
            }
            else if ( firstClass > 5 && economy <= 10 ) {

                printf_s( "%s", "First Class section is full \n" );
                printf_s( "%s", "Would you like sit on the economy class " );
                printf_s( "%s", " section ( Y or N ) " );
                scanf_s( "%s", response );

                if ( toupper( response[ 0 ] ) == 'Y' ) {
                    printf_s( "Your seat assignment is %d\n", economy );
                    plane[ economy++ ] = 1;
                    i++;
                }
                else {
                    printf_s ( "%s", "The next flight lives in 3 hours. \n" );
                }

            }
            else {
                printf_s( "%s", "The next flight lives in 3 hours. \n" );
            }
        } /* end if */
        else {
            if ( !plane[ economy ] && economy <= 10 ) {
                printf_s( "Your seat assignment is %d\n", economy );
                plane[ economy++ ] = 1;
                i++;
            }
            else if ( economy > 10 && firstClass <= 5 ) {

                printf_s( "%s", "First Class section is full \n" );
                printf_s( "%s", "Would you like sit on the economy class " );
                printf_s( "%s", " section ( Y or N ) " );
                scanf_s( "%s", response );

                if ( toupper( response[ 0 ] ) == 'Y' ) {
                    printf_s( "Your seat assignment is %d\n", firstClass );
                    plane[ firstClass++ ] = 1;
                    i++;
                }
                else {
                    printf_s( "%s", "The next flight lives in 3 hours. \n" );
                }

            }
            else {
                printf_s( "%s", "The next flight lives in 3 hours. \n" );
            }    
        } /* end else */

    } /* end while */

    printf_s( "%s", "\nAll seats for this flight are sold. \n" );

}