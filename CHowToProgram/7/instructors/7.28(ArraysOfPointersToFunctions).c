/*
theBitRiddler
9/23/2023
9:38 AM
 (Arrays of Pointers to Functions) 
*/
#include <stdio.h>

#define STUDENTS 3
#define EXAMS 4

void printMenu(void);
void printArray( int [][ EXAMS ], int, int );
void minimum( int [][ EXAMS ], int, int );
void maxmum( int [][ EXAMS ], int, int );
void average( int [][EXAMS ], int, int );

int main(void) {

    void ( * processGrades[ 4 ] ) ( int [][ EXAMS ], int, int ) = { printArray, minimum, maxmum, average };

    int choice = 0;
    int studentGrades[ STUDENTS ][ EXAMS ] = { { 77, 68, 86, 73 },
                                               { 96, 87, 89, 78 },
                                               { 70, 90, 86, 81 } };

    while( choice != 4 ) {

        do {
            printMenu();
            scanf( "%d", &choice );
        } 
        while ( choice < 0 || choice > 4 );

        if ( choice != 4 ) {
            ( * processGrades[ choice ] ) ( studentGrades, STUDENTS, EXAMS );
        } // end if
        else {
            printf_s( "%s", "\n\tProgram ended" );
        } // end else 

    } // end while 

    return 0;                                     
} /* end main */

void maxmum( int grades[][ EXAMS ], int pupils, int tests ) {
    int highGrades = 0;
    for ( int i = 0; i < pupils; i++ ) {
        for ( int j = 0; j < tests; j++ ) {
            if ( highGrades < grades[ i ][ j ] ) {
                highGrades = grades[ i ][ j ];
            } // end if
        } // end for
    } // end for
    printf_s( "\n\tThe highiest grade is %d\n", highGrades );
}

void minimum( int grades[][ EXAMS ], int pupils, int tests ) {
    int lowGrade = 100;
    for ( int i = 0; i < pupils; i++ ) {
        for ( int j = 0; j < tests; j++ ) {
            if ( lowGrade > grades[ i ][ j ] ) {
                lowGrade = grades[ i ][ j ];
            } // end if 
        } // end for
    } // end for
    printf_s( "\n\tThe lowest grade is %d\n", lowGrade );
} /* end function minimum */

void average( int grades[][ EXAMS ], int pupils, int tests ) {
    int total = 0;
    printf_s( "%s", "\n" );
    for ( int i = 0; i < pupils; i++ ) {
        total = 0;
        for ( int j = 0; j < tests; j++ ) {
            total += grades[ i ][ j ];
        } // end for
        printf_s( "\tAverage for student %d is %.1f\n", 
        i + 1, ( double) total / EXAMS );
    } // end for
} /* end function average */

void printArray( int grades[][EXAMS], int pupils, int tests ) {
    printf_s( "%s", "\n\t                 [ 0 ] [ 1 ] [ 2 ] [ 3 ]" );
    for ( int i = 0; i < pupils; i++ ) {
        printf_s( "\n\tStudentGrades[ %d ]", i );
        for ( int j = 0; j < tests; j++ ) {
            printf_s( "%-7d", grades[ i ][ j ] );
        } // end for
        printf_s( "%s", "\n" );
    } // end for
} /* end function printArray */

void printMenu( void ) {
    printf_s( "%s", "\n\tEnter a choice:\n"
                        "\t0 Print the array of grades\n"
                        "\t1 Find the minimum grade\n"
                        "\t2 Find the maximum grade\n"
                        "\t3 Print the average on all"
                        " tests for each student\n"
                        "\t4 End program\n"
                        "\t? " );   
} /* end function printMenu */