/*
 theBitRidder
 02/04/2023
 12:27
 Average Grade
*/
#include <stdio.h>
int main(void) {
	int grade = 0;
	int aCount = 0;
	int bCount = 0;
	int cCount = 0;
	int dCount = 0;
	int fCount = 0;
	double averageGrade = 0;
	
	printf("%s", "Enter the letter grades.\n");
	printf("%s", "Enter the EOF character to end input.\n");
	
	while ((grade = getchar()) != EOF) {
		
		switch (grade) {
			case 'A':
			case 'a':
				++aCount;
				break;
				
			case 'B':
			case 'b':
				++bCount;
				break;
				
			case 'C':
			case 'c':
				++cCount;
				break;
				
			case 'D':
			case 'd':
				++dCount;
				break;
				
			case 'F':
			case 'f':
				++fCount;
				break;
				
			case '\n':
			case '\t':
			case ' ':
				break;
				
			default:
				printf("%s", "Incorrect letter grade entered. ");
				printf("%s", "Enter a new grade.\n");
				break;
		}
	}
	
	printf("%s", "The totals for each letter grade are: \n");
	printf("A: %d\n", aCount);
	printf("B: %d\n", bCount);
	printf("C: %d\n", cCount);
	printf("D: %d\n", dCount);
	printf("F: %d\n", fCount);
	
	averageGrade = (4 * aCount + 3 * bCount + 2 * cCount + dCount) /
				   (aCount + bCount + cCount + dCount + fCount);
				   
	if (averageGrade > 3.4) {
		printf("%s", "Average grade is A\n");
	}
	else if (averageGrade > 2.4) {
		printf("%s", "Average grade is B\n");
	}
	else if (averageGrade > 1.4) {
		printf("%s", "Average grade is C\n");
	}
	else if (averageGrade > 0.4) {
		printf("%s", "Average grade is D\n");
	}
	else {
		printf("%s", "Average grade is F\n");
	}
}
