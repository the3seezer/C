// theBitRiddler
// 1/1/2023
// 10:47 AM
// duplicate Elimination
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void dup_Elim(int b[], size_t size); // duplicate elimination
void printArray(const int b[], size_t size);

int main(void) {
	srand(time(NULL));
	int num[SIZE] = {0};
	
	for (size_t i = 0; i < SIZE; ++i) {
		num[i] = 10 + rand() % 91;
	}
	// Display Oringinal Array
	puts("Original Array");
	printArray(num, SIZE);
	puts("\n");
	dup_Elim(num, SIZE);
	printArray(num, SIZE);
}

void dup_Elim(int b[], size_t size) {
	// loop through element one
	for (size_t i = 0; i < size; ++i) { 
		int flag = 0; 
		// loop through element two
		for (size_t j = 0; j < size; ++j) {
			// compare element one and two
			if (b[i] == b[j] && i != j) {
				b[j] = 0; // eliminate two
				++flag;
			}
		}
		if (flag) {
			b[i] = 0;
		}
	}
}

void printArray(const int b[], size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if (i % 10 == 0) {
			puts("");
		}
		printf("%5d", b[i]);
	}
}
