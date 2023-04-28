/* 
 theBitRiddler
 4/25/2023
 11:42 PM
 Calendar
*/
#include <stdio.h>
int main(void) {
	int year = 0;
	int leapyear = 0;
	int days = 0;
	int month = 0;
	int space = 0;
	int dayPosition = 0;
	int dayNum = 0;
	
	do {
		printf("%s", "Enter a calendar year between 1994 and 1999: ");
		scanf("%d", &year);
	}
	while (year < 1994 || year > 1999);
	
	switch (year) {
		case 1994:
			dayPosition = 7;
			break;
			
		case 1995:
			dayPosition = 1;
			break;
			
		case 1996:
			dayPosition = 2;
			break;
			
		case 1997:
			dayPosition = 4;
			break;
			
		case 1998:
			dayPosition = 5;
			break;
			
		case 1999:
			dayPosition = 6;
			break;
			
	} /* end switch */
	
	if (year % 400 == 0) {
		
		leapyear = 1;
		
	}
	else if (year % 4 == 0 && year % 100 != 0) {
		
		leapyear = 1;
		
	}
	else {
		
		leapyear = 0;
		
	}
	
	// loop throught months to display the calendar 
	
	for (month = 1; month <= 12; ++month) {
		
		switch (month) {
			
			case 1:
				printf("\n\nJanuary  %d\n", year);
				days = 31;
				break;
				
			case 2:
				printf("\n\nFebruary  %d\n", year);
				days = leapyear == 1 ? 29 : 28;
				break;
				
			case 3:
				printf("\n\nMarch  %d\n", year);
				days = 31;
				break;
				
			case 4:
				printf("\n\nApril  %d\n", year);
				days = 30;
				break;
				
			case 5:
				printf("\n\nMay  %d\n", year);
				days = 31;
				break;
				
			case 6:
				printf("\n\nJune  %d\n", year);
				days = 30;
				break;
				
			case 7:
				printf("\n\nJuly  %d\n", year);
				days = 31;
				break;
				
			case 8:
				printf("\n\nAugust  %d\n", year);
				days = 31;
				break;
				
			case 9:
				printf("\n\nSeptember  %d\n", year);
				days = 30;
				break;
				
			case 10:
				printf("\n\nOctober  %d\n", year);
				days = 31;
				break;
				
			case 11:
				printf("\n\nNovember  %d\n", year);
				days = 30;
				break;
				
			case 12:
				printf("\n\nDecember  %d\n", year);
				days = 31;
				break;	
		} /* end switch */
		
		printf("%s", " S   M   T   W   T   F   S \n");
		
		/* move to proper space to printing month */
		
		for (space = 1; space < dayPosition; space++) {
			
			printf("%s", "    ");
			
		} /* end for loop */
		
		/* print days of the month */
		
		for (dayNum = 1; dayNum <= days; ++dayNum) {
			
			printf("%2d  ", dayNum);
			
			/* if end of the week start a new line */
			if (dayPosition % 7 == 0) {
				
				printf("%s", "\n");
				dayPosition = 1; // reset the day position
				
			}
			else {
				dayPosition++;
			}
			
		} /* end for loop */
		
	} /* end for loop */
}
