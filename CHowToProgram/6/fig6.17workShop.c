// theBitRiddler
// 12/20/2022
// 11:53 AM
// Two-dimensional Array Manipulations
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

int minimum(const int grades[][EXAMS], size_t pupils, size_t tests);
int maximum(const int grades[][EXAMS], size_t pupils, size_t tests);
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests);
double average(const int setOfGrades[], size_t tests);

int main(void) {
	int studentGrades[STUDENTS][EXAMS] = 
	{{77, 68, 86, 73},
     {96, 87, 89, 78},
     {70, 90, 86, 81}};
     
     // output students grades
     puts("The array value is:");
     printArray(studentGrades, STUDENTS, EXAMS);
     
     printf("\n\nThe lowest value is %d\nThe highest value is %d",
	 minimum(studentGrades, STUDENTS, EXAMS),
	 maximum(studentGrades, STUDENTS, EXAMS));
	 
	 for (size_t student = 0; student < STUDENTS; ++student) {
	 	printf("\nThe average for student %zu is %.2f\n",
		student, average(studentGrades[student], EXAMS));
	 }
}

void printArray(const int grades[][EXAMS], size_t pupils, size_t tests) {
	printf("%s", "                      [0]  [1]  [2]  [3]");
	for (size_t row = 0; row < pupils; ++row) {
		printf("\nThe studentGrade[%zu]   ", row);
		for (size_t column = 0; column < tests; ++column) {
			printf("%-5d", grades[row][column]);
		}
	}
}

int minimum(const int grades[][EXAMS], size_t pupils, size_t tests) {
	int lowGrade = 100;
	for (size_t row = 0; row < pupils; ++row) {
		for (size_t column = 0; column < tests; ++column) {
			if (grades[row][column] < lowGrade) {
				lowGrade = grades[row][column];
			}
		}
	}
	
	return lowGrade;
}

int maximum(const int grades[][EXAMS], size_t pupils, size_t tests) {
	int highGrade = 0;
	for (size_t row = 0; row < pupils; ++row) {
		for (size_t column = 0; column < tests; ++column) {
			if (grades[row][column] > highGrade) {
				highGrade = grades[row][column];
			}
		}
	}
	
	return highGrade;
}

double average(const int setOfGrades[], size_t tests) {
	int total = 0;
	for (size_t test = 0; test < tests; ++test) {
		total += setOfGrades[test];
	}
	
	return (double) total / tests;
}
