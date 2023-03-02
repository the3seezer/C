// theBitRiddler
// 1/1/2023
// 1:34 PM
// Array Recursive Reversive display Function
#include <stdio.h>
#define SIZE 10

void printArray(const int b[], size_t start, size_t size);

int main(void) {
	int a[SIZE] = {8, 3, 1, 2, 6, 0, 9, 7, 4, 5};
	
	printArray(a , 0, SIZE);
}

void printArray(const int b[], size_t start, size_t size) {
	if (start < size) {
		printArray(b, start + 1, size);
		printf("%4d", b[start]);
	}
}
