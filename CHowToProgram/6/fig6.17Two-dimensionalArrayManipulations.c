// theBitRiddler
// 12/19/2022
// 5:06 PM
//  Two-dimensional array manipulations.
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

int minimum(const int grades[][EXAMS], size_t pupils, size_t tests);
int maximum(const int grades[][EXAMS], size_t pupils, size_t tests);
double average(const int setOfGrades[], size_t tests);
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests);

int main(void) {
	int studentGrades[STUDENTS][EXAMS] = 
	{{77, 68, 86, 73},
     {96, 87, 89, 78},
     {70, 90, 86, 81}};
     
     // Output array students grades
    puts("The array is:");
    printArray(studentGrades, STUDENTS, EXAMS);
     
     // determine smallest and largest grade values
    printf("\n\nLowest grade: %d\nHighest grade: %d\n",
	 minimum(studentGrades, STUDENTS, EXAMS),
	 maximum(studentGrades, STUDENTS, EXAMS));
	 
	 // calculate average grade for each student
	for (size_t student = 0; student < STUDENTS; ++student) {
	    printf("The average for student %zu is %.2f\n",
		student, average(studentGrades[student], EXAMS));
    }	 
}

int minimum(const int grades[][EXAMS], size_t pupils, size_t tests) {
	int lowGrade = 100; // initialize to highest possible grade
	// loop through grade row
	for (size_t row = 0; row < pupils; ++row) {
		// loop through grade column
		for (size_t column = 0; column < tests; ++column) {
			if (grades[row][column] < lowGrade) {
				lowGrade = grades[row][column];
			}
		}
	}
	
	return lowGrade; // return minimum grade
}

int maximum(const int grades[][EXAMS], size_t pupils, size_t tests) {
	int highGrade = 0; // initialize to lowest possible grade
	// loop through grade row
	for (size_t row = 0; row < pupils; ++row) {
		// loop through grade column
		for (size_t column = 0; column < tests; ++column) {
			if (grades[row][column] > highGrade) {
				highGrade = grades[row][column];
			}
		}
	}
	
	return highGrade; // return maximum grade
}

double average(const int setOfGrades[], size_t tests) {
	int total = 0;
	for (size_t test = 0; test < tests; ++test) {
		total += setOfGrades[test];
	}
	
	return (double) total / tests; // return average
}

void printArray(const int grades[][EXAMS], size_t pupils, size_t tests) {
	printf("%s", "                  [0]  [1]  [2]  [3]");
	// output grades in tabular form
	for (size_t row = 0; row < pupils; ++row) {
		printf("\nStudentGrades[%zu]  ", row);
		// output each students grades
		for (size_t column = 0; column < tests; ++column) {
			printf("%-5d", grades[row][column]);
		}
	}
}
