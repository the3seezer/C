// theBitRiddler
// 12/16/2022
// 9:18 AM
// 6.15 binary search of a sorted array
#include <stdio.h>
#define SIZE 15

int binarySearch(const int b[], int key, size_t low, size_t high);
void printHeader(void);
void printRow(const int b[], size_t low, size_t mid, size_t high);

int main(void) {
	int a[SIZE] = {0};
	for (size_t i = 0; i < SIZE; ++i) {
		a[i] = 2 * i;
	}
	
	printf("%s", "Enter a value to find a subscript: ");
	int key = 0;
	scanf("%d", &key);
			
	printHeader();
	
	int result = binarySearch(a, key, 0, SIZE - 1);
	
	if (result != -1) {
		printf("The subscript of %d is %d", key, result);
	}
	else {
		printf("The subscript of %d not found", key);
	}
}

int binarySearch(const int b[], int key, size_t low, size_t high) {
	//int middle = (low + high) / 2;
	
	while (low <= high) {
		int middle = (low + high) / 2;
		
		printRow(b ,low ,middle ,high);
		
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
	return -1;
}

void printHeader(void) {
	puts("\nSubscripts");
	for (int j = 0; j < SIZE; ++j) {
		printf("%3d ", j);
	}
	puts("");
	for (int j = 0; j < 4 * SIZE; ++j) {
		printf("%s", "-");
	}
	puts("");
}

void printRow(const int b[], size_t low, size_t mid, size_t high) {
	for (size_t i = 0; i < SIZE; ++i) {
		if (i < low || i > high) {
			printf("%s","    ");
		}
		else if (i == mid) {
			printf("%3d*", b[i]);
		}
		else {
			printf("%3d ", b[i]);
		}
		//puts("");
	}
	puts("");
}
