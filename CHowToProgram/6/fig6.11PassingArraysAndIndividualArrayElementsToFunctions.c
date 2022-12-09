// theBitRiddler
// 12/7/2022
// 8:51am
/*
 Difference btn passing an entire array and passing an array element 
  Passing arrays and individual array elements to functions.
*/
#include <stdio.h>
#define SIZE 5

void modifyArray(int b[], size_t size);
void modifyElement(int e);

int main(void) {
	int a[SIZE] = {0, 1, 2, 3, 4};
	
	puts("Effects of passing an entire array by reference\n\nValue of the original array are:");
	for (size_t j = 0; j < SIZE; ++j) {
		printf("%3d", a[j]);
	}
	puts("");
	
	modifyArray(a, SIZE);
	puts("Values of modified array are:");
	for (size_t i = 0; i < SIZE; ++i) {
		printf("%3d", a[i]);
	}
	puts("");
	
	printf("\n\n\nEffects of passing an array element " "by value\n\nThe value of a[3] is %d\n", a[3]);
	modifyElement(a[3]);
	printf("The value of a[3] is %d\n", a[3]);
}

void modifyArray(int b[], size_t size) {// Passed by reference
	for (size_t i = 0; i < SIZE; ++i) {
		b[i] *= 2;
	}
}

void modifyElement(int e) {// Passed by Value; like any other variables; we've learned so far(int, char, float
	e *= 2;
	printf("The value of a[3] in modifyElement is %d\n", e);
}
