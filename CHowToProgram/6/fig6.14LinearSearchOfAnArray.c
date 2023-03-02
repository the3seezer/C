// theBitRiddler
// 12/12/2022
// 3:21 PM
//  Linear search of an array.
#include <stdio.h>
#define SIZE 100

int linearSearch(const int array[], int key, size_t size);

int main(void) {
	int a[SIZE] = {0};
	
	for (size_t j = 0; j < SIZE; ++j) {// assinging some value
		a[j] = j * 2;
	}
	
	printf("Enter integer search key: ");
	int searchKey = 0;// value to locate in array a
	scanf("%d", &searchKey);
	
	// Attempt to locate search key in array a
	int subcript = linearSearch(a, searchKey, SIZE);
	
	if (subcript != -1) {
		printf("found value at subcript %d\n", subcript);
	}
	else {
		printf("%s","Value not found");
	}
}

int linearSearch(const int array[], int key, size_t size) {
	// loop through an array
	for (size_t n = 0; n < size; ++n) {
		if (array[n] == key) {
			return n;
		}
	}
	return -1;
}
