/* 
 theBitRiddler
 4/25/2023
 11:46 AM
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
	
	
	printf("%s", "Enter the letter grades. ");
	printf("%s", "Enter EOF to end input: \n");
	
	while ( (grade = getchar()) != EOF) {
		
		if (grade == 'A' || grade == 'a') {
			++aCount;
		}
		else if (grade == 'B' || grade == 'b') {
			++bCount;
		}
		else if (grade == 'C' || grade == 'c') {
			++cCount;
		}
		else if (grade == 'D' || grade == 'd') {
			++dCount;
		}
		else if (grade == 'F' || grade == 'f') {
			++fCount;
		}
		else if (grade == '\n' || grade == ' ' || grade == '\t') {
			;
		}
		else {
			printf("%s", "Incorrect letter grade entered. ");
			printf("%s", "Enter a new grade \n");
			
		}
			
		
	}
	
	printf("%s", "Total for each letter grade: \n");
	printf("A  %d\n", aCount);
	printf("B  %d\n", bCount);
	printf("C  %d\n", cCount);
	printf("D  %d\n", dCount);
	printf("F  %d\n", fCount);
}
