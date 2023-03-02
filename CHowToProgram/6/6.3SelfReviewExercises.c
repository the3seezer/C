// theBitRiddler
// 12/21/2022
// 5:36 PM
// Self Review Exercises 6.3
#include <stdio.h>
#define SIZE 10 // 6.3(a)

void printArray(const double b[]);

int main(void) {
	double fractions[SIZE] = {0}; // 6.3(b)
	fractions[3]; // Refered 6.3(c)
	fractions[8] = 1.667; // 6.3(d)
	fractions[6] = 3.333; // 6.3(e)
	printf("%.2f %.2f\n", fractions[5], fractions[8]); // 6.3(f)
	printArray(fractions);
}

void printArray(const double b[]) { // 6.3(g)
	for (size_t x = 0; x < SIZE; ++x) {
		printf("element %zu = %3.2f\n", x + 1, b[x]);
	}
}
