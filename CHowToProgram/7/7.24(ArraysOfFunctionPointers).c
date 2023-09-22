/*
theBitRiddler
9/21/2023
4:53 AM
 (Arrays of Function Pointers)
*/
#include <stdio.h>

#define STUDENTS 3
#define EXAMS 4

void maximum( const int grades[][ EXAMS ], size_t pupils, size_t tests );
void minimum( const int grades[][ EXAMS ], size_t pupils, size_t tests );
void average( const int grades[][ EXAMS ], size_t pupils, size_t tests );
void printArray( const int grades[][ EXAMS ], size_t pupils, size_t tests );

int main( void ) {
    int choice = 0; // create a choice variable
    void ( * processGrades[ 4 ] ) ( const int[][ EXAMS ], size_t, size_t ) = { printArray, minimum, maximum, average };
    int studentGrades[STUDENTS][EXAMS] = 
                     {{77, 68, 86, 73},
                     {96, 87, 89, 78},
                     {70, 90, 86, 81}};
    
    do {
        printf_s( "%s", "\n\n\nEnter a choice:\n"
                "0 Print the array of grades\n"
                "1 Find the minimum grade\n"
                "2 Find the maximum grade\n"
                "3 Print the average on all tests for each student\n"
                "4 End program\n\n\n" );
        scanf_s( "%d", &choice );
        ( * processGrades[ choice ] ) ( studentGrades, STUDENTS, EXAMS );
    }
    while ( choice != 4 );

    return 0;
    
} /* end main */

void average( const int grades[][ EXAMS ], size_t pupils, size_t tests ) {
    int total = 0;
    for ( size_t student = 0; student < pupils; student++) {
        printf_s( "average of Student %zu is ", student );
        total = 0;
        for ( size_t result = 0; result < tests; result++ ) {
            total += grades[ student ][ result ]; 
        } // end for
        printf_s( "%.2f\n", (float) total / tests );
    } // end for
} /* end function average */

void printArray( const int grades[][ EXAMS ], size_t pupils, size_t tests ) {
    printf_s( "%8s%s\n", "Grades", "[ 0 ] [ 1 ] [ 2 ] [ 3 ]" );
    for ( size_t row = 0; row < pupils; row++ ) {
        printf_s("%-9s", "Students" );
        for ( size_t col = 0; col < tests; col++ ) {
            printf_s( "%-6d", grades[ row ][ col ] );
        } // end for
        puts("");
    } // end for
} /* end function printArray */

void maximum( const int grades[][ EXAMS ], size_t pupils, size_t tests ) {
    int max = 0; // create a maximum variable
    for ( size_t row = 0; row < pupils; row++ ) {
        for ( size_t col = 0; col < tests; col++ ) {
            if ( max < grades[ row ][ col ])
                max = grades[ row ][ col ];
        } // end for
    }// end for
    printf_s("The maximum grades are %d\n", max );
} /* end function maximum */

void minimum( const int grades[][ EXAMS ], size_t pupils, size_t tests ) {
    int min = 100; // create a minimum variable
    for ( size_t row = 0; row < pupils; row++ ) {
        for ( size_t col = 0; col < tests; col++ ) {
            if ( min > grades[ row ][ col ] )
                min = grades[ row ][ col ];
        } // end for
    } // end for
    printf_s("The minimum grades are %d\n", min );
} /* end function minimum */

