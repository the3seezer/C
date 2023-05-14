/* 
 theBitRiddler
 5/13/2023
 9:25 PM
 Binary Search
*/
#include <stdio.h>

#define SIZE 15

int binarySearch( int a[], int k, size_t low, size_t high );
void header( void );
void printArray( int a[], size_t low, size_t mid, size_t high );

int main( void ) {
    int array[ SIZE ] = {0};
    int key = 0;
    int result = 0;

    for (size_t i = 0; i < SIZE; i++)
    {
        array[ i ] = 2 * i;
    } /* end for */

    printf_s( "Print value between 0 and 28: " );
    scanf_s( "%d", &key );

    header();
    result = binarySearch( array, key, 0, SIZE - 1 );

    if ( result != -1 ) {
        printf_s( "%d found at subscrip %d\n", key, result );
    } /* end if */
    else {
        printf_s( "%d not found\n", key );
    } /* end else */

    return 0;
    
} /* end main */

int binarySearch( int a[], int k, size_t low, size_t high ) {
    int middle = 0;

    while ( low <= high ) {
        middle = ( low + high ) / 2;

        printArray( a, low, middle, high );

        if ( k == a[ middle ] ) {
            return middle;
        }
        else if ( k < a[ middle ] ) {
            high = middle - 1;
        }
        else if ( k > a[ middle ] ) {
            low = middle + 1;
        }
    }

    return -1;

}

void header( void ) {
    puts( "\nSubscripts:" );
    
    for ( int i = 0; i < SIZE; i++ ) {
        printf_s( "%3d ", i );
    } /* end for */

    puts( "" );

    for ( int j = 1; j < SIZE * 4; j++ ) {
        printf_s( "%s", "-" );
    } /* end for */

    puts( "" );

} /* end function header */

void printArray( int a[], size_t low, size_t mid, size_t high ) {

    for ( size_t i = 0; i < SIZE; i++ ) {

        if ( i < low || i > high ) {
            printf_s( "%s", "    " );
        } /* end if */
        else if ( i == mid ) {
            printf_s( "%3d*", a[ i ] );
        } /* else if */
        else {
            printf_s( "%3d ", a[ i ] );
        }
    }

    puts( "" );

}

