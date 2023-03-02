// theBitRiddler
// 12/29/2022
// 11:35 AM
// Bubble Sort
#include <stdio.h>
#define SIZE 10

void printArray(const int b[], size_t size);
void bubbleSort(int b[], size_t size);

int main(void) {
	int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
	puts("Data items in original order");
	printArray(a, SIZE);
	puts("");
	bubbleSort(a, SIZE);
	puts("Data items in Ascending order");
	printArray(a, SIZE);
}

void printArray(const int b[], size_t size) {
	for (size_t i = 0; i < size; ++i) {
		printf("%4d", b[i]);
	}
	puts("");
}

void bubbleSort(int b[], size_t size) {
	int de = 1; // comparison decreaser
	// looping through nine passes
	for (int pass = 1; pass < size; ++pass) {
		// looping through the comparisons 
		for (size_t i = 0; i < size - de; ++i) {
			if (b[i] > b[i + 1]) {
				int hold = b[i];
				b[i] = b[i + 1];
				b[i + 1] = hold;
			}
		}
		de++; // to decrease the comparison; increment it by one
	}
}

