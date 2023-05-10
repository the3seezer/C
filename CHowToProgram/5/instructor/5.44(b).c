/*
 theBitRiddler
 5/10/2023
 1:00 PM
 Advanced Computer Assisted Instructor, Add Grade levels two
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arithmetic( void );
void correctAnswer( void );
void incorrectAnswer( void );
int menu( void );

int main( void ) {
    srand( time( NULL ) );
    arithmetic();
    return 0;
} /* end main */

void arithmetic( void ) {
    int x = 0;
    int y = 0;
    int right = 0;
    int wrong = 0;
    int response = 0;
    int selection = 0;
    int type = 0;
    int problemMix = 0;
    int answer = 0;
    char operatorV = '0';

    selection = menu();
    type = selection;

    for ( int i = 0; i <= 10; i++ ) {
        x = rand() % 10;
        y = rand() % 10;

        if ( selection == 5 ) {
            problemMix = 1 + rand() % 4;
            type = problemMix;
        }

        switch ( type )
        {
        case 1:
            operatorV = '+';
            answer = x + y;
            break;

        case 2:
            operatorV = '-';
            answer = x - y;
            break;

        case 3: 
            operatorV = '*';
            answer = x * y;
            break;

        case 4:
            operatorV = '/';
            
            /* eliminate divide by zero problem */
            if ( y == 0 ) {
                y = 1;
                answer = x / y;
            }
            else {
                /* create 'fine' division */
                x *= y;
                answer = x / y;
            }

            break;
        
        } /* end switch */

        printf( "How much is %d %c %d?\n", x, operatorV, y );
        scanf_s( "%d", &response );

        while ( response  != answer ) {
            ++wrong;
            incorrectAnswer();
            ++i;
            scanf_s( "%d", &response );
        } /* end while */

        ++right;
        correctAnswer();

    } /*end for */

    if ( (double) right / ( right + wrong ) < .75 ) {
        printf( "%s", "Pleae ask for instructor for extra help." );
    } /* end if */

    printf_s( "%s", "Thats all for now. Bye. ");

} /* end function arithmetic */

int menu( void ) {
    int choice = 0;

    do {
        printf_s( "%s", "Choose type of problem to study\n"
        "Enter: 1 for Addition, 2 for Substraction\n"
        "Enter: 3 for Multiplication, 4 for Division\n"
        "Enter: 5 for a combination of 1 through 4\n?" );
        scanf_s( "%d", &choice );
    }
    while ( choice < 1 || choice > 5 );

    return choice;
} /* end function menu */

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
