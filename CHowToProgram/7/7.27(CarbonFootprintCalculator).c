/* 
theBitRiddler
9/23/2023
4:13 PM
 (Carbon Footprint Calculator)
*/
#include <stdio.h>

void car( void );
void bicycle( void );
void building( void );
void printMenu( void );

int main(void){
    int choice = 0;
    void ( * choose[ 3 ] ) ( int ) = { car, bicycle, building };

    while( choice >= 0 && choice < 4 ) {
        do {
            printMenu();
            scanf( "%d", &choice );
        }
        while( choice < -1 || choice > 2 );
		
		if ( choice >= 0 )
        	( * choose[ choice ] ) ( choice );
        else
        	break;
        	
    } // end while
    return 0;

} /* end main */

void printMenu( void ) {
    printf_s( "%s", "\tTake a choice to calculate"
                    " carbon footprint\n"
                    "\t 0. Car\n"
                    "\t 1. Bicycle\n"
                    "\t 2. Building\n"
                    "\t -1 to end \n"
                    "\t ? " );
} /* end function printMenu */

void car( void ) {
    int driving = 0;
    int asset = 0; // miles

    printf_s( "%s", "\tChoose 0 not driving and 1 when driving\n"
                    "\tAnd Choose how many miles ");
    scanf( "%d%d", &driving, &asset );

    if ( driving ) {
        printf_s( "\tCarbon emission grams %d\n", 280 * asset );
    } // end if
    else {
        printf_s( "\tCarbon emission grams %d\n", 65 * asset );
    } // end else

} /* end function car */

void bicycle( void ) {
    int mile = 0;
    printf_s( "%s", "\tChoose how many miles " );
    scanf( "%d", &mile );
    printf_s( "\tCarbon emission grams %d\n", 33 * mile );
} /* end function bicycle */

void building( void ) {
    int sqMeters = 0;
    int structuralElement = 0;
    printf_s( "%s", "\tchoose how many square meters " );
    scanf( "%d", &sqMeters );
    printf_s( "%s", "\tChoose how many structural element square meters " );
    scanf( "%d", &structuralElement );
    printf_s( "\tCarbon emission in gram per year %d\n", 48870 * sqMeters + 6940 * structuralElement );
} /* end function building */
