// theBitRiddler
// 12/12/2022
// 4:54 PM
// linear Search Of an Array
#include <stdio.h>
#define SIZE 100

int linearSearch(const int array[], int key, size_t size);

int main(void) {
	int a[SIZE] = {0};
	
	for (size_t j = 0; j < SIZE; ++j) {
		a[j] = j * 2;
	}
	
	int searchKey = 0;
	printf("Enter a value to search in array a: ");
	scanf("%d", &searchKey);
	
	int subscript = linearSearch(a, searchKey, SIZE);
	
	if (subscript != -1) {
		printf("Found the value at subscrit %d\n", subscript);
	}
	else {
		printf("%s","Value not found\n");
	}
}

int linearSearch(const int array[], int key, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if (array[i] == key) {
			return i;
		}
	}
	return -1;
}
