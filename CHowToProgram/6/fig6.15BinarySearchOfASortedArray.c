// theBitRiddler
// 12/15/2022
// 5:57 PM
// Imprementing Binary Search
#include <stdio.h>
#define SIZE 15

int binarySearch(const int b[], int key, size_t low, size_t high);
void printHeader(void);
void printRow(const int b[], size_t low, size_t mid, size_t high);

int main(void) {
	int a[SIZE] = {0};
	
	for (size_t i = 0; i < SIZE; ++i) {
		a[i] = i * 2;
	}
	
	printf("%s","Enter a number btn zero and 28: ");
	int key = 0;
	scanf("%d",&key);
	
	printHeader();
	
	int result = binarySearch(a, key, 0, SIZE - 1);
	
	if (result != -1) {
		printf("\n%d found at subscript %d\n", key, result);
	}
	else {
		printf("%d not found", key);
	}
}

// function to perform binary search of an array
int binarySearch(const int b[], int key, size_t low, size_t high) {
	// loop until low subscript is greater than high subscript
	while (low <= high) {
		size_t middle = (low + high) / 2;
		
		// display subarray used in this loop iteration
		printRow(b, low, middle, high);
		
		// if key matches return middle subscript
		if (key == b[middle]) {
			return middle;
		}
		else if (key < b[middle]) {
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}
	
	return -1;// search key not found
}

void printHeader(void) {
	puts("\nSubscripts: ");
	
	// output column heads
	for (int i = 0; i < SIZE; ++i) {
		printf("%3d ", i);
	}
	puts("");
	for (int i = 1; i <= 4 * SIZE; ++i) {
		printf("%s","-");
	}
	puts("");
}

void printRow(const int b[], size_t low, size_t mid, size_t high) {
	for (size_t i = 0; i < SIZE; ++i) {
		if (i < low || i > high) {
			printf("%s", "    ");
		}
		else if (i == mid) {
			printf("%3d*", b[i]);// mark middle value
		}
		else {
			printf("%3d ", b[i]);// display other elements
		}
	}
	
	puts("");
}
