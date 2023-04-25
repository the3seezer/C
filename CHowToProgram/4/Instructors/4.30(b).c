/* 
 theBitRiddler
 4/25/2023
 4:39 PM
 Grades
*/
#include <stdio.h>
int main(void) {
	int grade = 0;
	int aCount = 0;
	int bCount = 0;
	int cCount = 0;
	int dCount = 0;
	int fCount = 0;
	
	
	printf( "Enter the letter grades." );
    printf( " Enter the EOF character to end input:\n" );
	
	while ( (grade = getchar()) != EOF) {
		
		if (grade == 'A' || grade == 'a') {
			++aCount;	
		}
		
		if (grade == 'B' || grade == 'b') {
			++bCount;
		}
		
		if (grade == 'C' || grade == 'c') {
			++cCount;
		}
		
		if (grade == 'D' || grade == 'd') {
			++dCount;
		}
		
		if (grade == 'F' || grade == 'f') {
			++fCount;
		}
		
		if (grade == '\n' || grade == ' ' || grade == '\t') {
			;
		}
		
		if (grade != 'A' && grade != 'a' &&
		    grade != 'B' && grade != 'b' &&
			grade != 'C' && grade != 'c' &&
			grade != 'D' && grade != 'd' &&
			grade != 'F' && grade != 'f' &&
			grade != '\n' && grade != ' ' &&
			grade != '\t') {
				
				printf( "Incorrect letter grade entered." );
			    printf( " Enter a new grade.\n" );
				
			}
		
	}
	
	
	printf("%s", "Total for each letter grade: \n");
	printf("A  %d\n", aCount);
	printf("B  %d\n", bCount);
	printf("C  %d\n", cCount);
	printf("D  %d\n", dCount);
	printf("F  %d\n", fCount);
}
