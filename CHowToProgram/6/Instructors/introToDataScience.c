/*
 theBitRiddler
 5/13/2023
 12:03 PM
 mean, mode, and median
*/
#include <stdio.h>

#define SIZE 100

void mean( const int answer[] );
void mode( int freq[], const int answer[] );
void median( int answer[] );
void bubbleSort( int answer[] );
void printArray( const int answer[] );

int main( void ) {
    int frequency[10] = {0};

    int response[SIZE] = {
        6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
        7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
        6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
        7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
        6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
        7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
        5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
        7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
        7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
        4, 5, 6, 1, 6, 5, 7, 8, 7
    };

    mean( response );
    mode( frequency, response );
    median( response );

    return 0;

} /* end main */

void mean( const int answer[] ) {
    int total = 0;
    printf_s( "%s", "-----------Mean----------\n\n\n" );

    for ( size_t i = 0; i <= 100; i++ ) {
        total += answer[ i ];
    }

    printf_s("The mean is the average value of the data\n"
            "items. The mean is equal to the total of\n"
            "all the data items divided by the number\n"
            "of data items (%u). The mean value for\n"
            "this run is: %u / %u = %.4f\n\n",
            SIZE, total, SIZE, (double) total / SIZE);

} /* end function mean */

void median( int answer[] ) {
    printf_s( "%s", "----------Median----------\n\n" );
    printf_s( "%s", "Array before bubble sort\n" );
    printArray( answer );

    bubbleSort( answer );

    printf_s( "%s", "\nArray after bubble sort\n" );

    printArray( answer );

    printf("\n\nThe median is element %u of\n"
        "the sorted %u element array.\n"
        "For this run the median is %u\n\n",
        SIZE / 2, SIZE, answer[SIZE / 2]);

} /* end function median */

void mode( int freq[], const int answer[] ) {
    
    for ( size_t rating = 0; rating < 10; rating++ ) {
        freq[ rating ] = 0;
    } /* end for */

    for ( size_t j = 0; j < SIZE; j++ ) {
        ++freq[ answer[ j ] ];
    } /* end for */

    int largest = 0;
    int modeValue = 0;

    printf("%s%11s%19s\n\n%54s\n%54s\n\n",
            "Response", "Frequency", "Bar Chart\n",
            "1    1    2    2", "5    0    5    0    5");

    for ( size_t rating = 1; rating <= 9; rating++ ) {
        printf_s("%8zu%11d ", rating, freq[rating]);

        if ( freq[ rating ] > largest ) {
            largest = freq[ rating ];
            modeValue = rating;
        } /* end if */

        for ( int h = 1; h <= freq[ rating ]; h++ ) {
            printf_s( "%s", "*" );
        } /* end for */

        puts("");

    } /* end for */

    printf("\nThe mode is the most frequent value.\n"
        "For this run the mode is %d which occurred %d times.\n",
        modeValue, largest);

} /* end function mode */

void bubbleSort( int answer[] ) {

    for ( int i = 1; i < SIZE; i++ ) {
        for ( size_t j = 0; j < SIZE - 1; j++ ) {
            if ( answer[ i ] > answer[ i + 1 ] ) {
                int hold = answer[ i + 1 ];
                answer[ i + 1 ] = answer[ i ];
                answer[ i ] = hold;
            } /* end if */
        } /* end for */
    } /* end for */

} /* end function bubbleSort */

void printArray( const int answer[] ) {

    for ( size_t i = 0; i < SIZE; i++ ) {
        printf_s( "%4d", answer[ i ] );

        if ( i % 20 == 0 ) {
            printf_s( "%s", "\n" );
        }
    }
}
