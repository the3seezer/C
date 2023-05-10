/* 
 theBitRiddler
 5/10/2023
 11:49 AM
 Advanced Computer Assisted Instructor, Add Grade levels
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randValue( int );
void multiplication( void );
void correctAnswer( void );
void incorrectAnswer( void );

int main( void ) {
    srand( time( NULL ) );
    multiplication();
    return 0;
} /* end main */

int randValue( int level ) {

    switch ( level )
    {
        case 1:
            return rand() % 10;
            break;
        
        case 2:
            return rand() % 100;
            break;

        case 3:
            return rand() % 1000;
            break;

        default:
            return rand() % 10;
            break;
    } /* end switch */

} /* end function randValue */

void multiplication( void ) {
    int x = 0;
    int y = 0;
    int right = 0;
    int wrong = 0;
    unsigned int responce = 0;
    int gradeLevel = 0;

    do {
        printf( "%s", "Enter the grade level ( 1 to 3): ");
        scanf_s( "%d", &gradeLevel );
    }
    while ( gradeLevel < 1 || gradeLevel > 3); /* end do while */

    for ( int i = 1; i <= 10; i++ ) {
        x = randValue( gradeLevel );
        y = randValue( gradeLevel );

        printf( "How much is %d times %d\n?", x, y );
        scanf_s( "%u", &responce );

        while (responce != x * y ) {
            ++wrong;
            ++i;
            incorrectAnswer();
            scanf_s( "%u", &responce );
        } /* end while */

        ++right;
        correctAnswer();

    } /* end for */

    if ( ( double ) right / ( right + wrong ) < .75 ) {
        printf( "%s", "Please ask your instructor for extra help: \n" );
    }

    printf_s( "%s", "That all for now. Bye.\n" );
    
} /* end function multiplication */

void incorrectAnswer( void ) {
	
	switch ( rand() % 4 ) {
		case 0:
			printf( "%s", "No. Please try again.\n?" );
			break;
		
		case 1: 
			printf( "%s", "Wrong. Try once more.\n?" );
			break;
			
		case 2:
			printf( "%s", "Don't give up.\n?" );
			break;
			
		case 3:
			printf( "%s", "No. Keep trying.\n?" );
			break;
	} /* end switch */	
} /* end function incorrectAnswer */

void correctAnswer( void ) {
	
	switch ( rand() % 4 ) {
		case 0:
			printf( "%s", "Very Good!\n\n" );
			break;
			
		case 1:
			printf( "%s", "Excellent!\n\n" );
			break;
			
		case 2:
			printf( "%s", "Nice work!\n\n" );
			break;
			
		case 3:
			printf( "%s", "Keep up the good work!\n\n" );
			break;
	} /* end switch */	
} /* end function correctAnswer */