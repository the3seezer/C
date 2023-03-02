// theBitRiddler
// 12/29/2022
// 11:59 AM
// Bubble Sort
#include <stdio.h>
#define SIZE 10

void bubbleSort(int b[], size_t size);
void printArray(const int b[], size_t size);

int main(void) {
	int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
	puts("Data items in original order");
	printArray(a, SIZE);
	puts("");
	bubbleSort(a, SIZE);
	puts("Data items in ascending order");
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
	// loop through the pass
	for (int pass = 1; pass < size; ++pass) {
		int flag = 0; // Find wheather swapping took place in a particular pass
		// loop through the comparison
		for (size_t i = 0; i < size - de; ++i) {
			if (b[i] > b[i + 1]) {
				int hold = b[i];
				b[i] = b[i + 1];
				b[i + 1] = hold;
				flag++;
			}
		}
		if (flag) {
			de++;
		}
		else {
			break;
		}
		// flag ? de++ : break; ;
	}
}
