// theBitRiddler
// 12/6/2022
// 10:14am
/* Static local Arrays and Automatic Local Arrays
  Static arrays are initialized to zero if not explicitly initialized. */
#include <stdio.h>
int staticArrayInit(void);
int automaticArrayInit(void);

int main(void) {
	puts("First call to each function: ");
	staticArrayInit();
	automaticArrayInit();
	
	puts("\n\nSecond call to each function: ");
	staticArrayInit();
	automaticArrayInit();
	puts("");
}

int staticArrayInit(void) {
	static int array1[3];
	
	puts("\nValues on Entering staticArrayInit: ");
	for (size_t i = 0; i <= 2; ++i) {
		printf("array1[%zu] = %d ", i, array1[i]);
	}
	
	puts("\nValues on Exiting staticArrayInit: ");
	for (size_t i = 0; i <= 2; ++i) {
		printf("array1[%zu] = %d ", i, array1[i] += 5);
	}
}

int automaticArrayInit(void) {
	int array2[3] = {1, 2, 3};
	
	puts("\nValues on Entering automaticArrayInit: ");
	for (size_t i = 0; i <= 2; ++i) {
		printf("array2[%zu] = %d ", i, array2[i]);
	}
	
	puts("\nValues on Exiting automaticArrayInit: ");
	for (size_t i = 0; i <= 2; ++i) {
		printf("array2[%zu] = %d ", i, array2[i] += 5);
	}
}
