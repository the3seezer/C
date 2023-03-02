// theBitRiddler
// 12/22/2022
// 10:51 PM
// Exercises 6.8(f)
#include <stdio.h>
#define SIZE 99

int smallest(const float b[], size_t size);
int largest(const float b[], size_t size);
int main(void) {
	float w[SIZE] = {0};
	for (size_t i = 0; i < SIZE; ++i) {
		w[i] = i + 10;
	}
	w[55] = 100000;
	w[50] = 1;
	printf("smallest: %d\n", smallest(w, SIZE));
	printf("largest: %d\n", largest(w, SIZE));
}

int smallest(const float b[], size_t size) {
	int smallest = 100; // the largest possible value
	for (size_t i = 0; i < size; ++i) {
		if (b[i] < smallest) {
			smallest = b[i];
		}
	}
	return smallest;
}

int largest(const float b[], size_t size) {
	int largest = 0; // smallest possible value
	for (size_t i = 0; i < size; ++i) {
		if (b[i] > largest) {
			largest = b[i];
		}
	}
	return largest;
}
