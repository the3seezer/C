// theBitRiddler
// 12/20/2022
// 12:41 PM
//  Using variable-length arrays in C99.
#include <stdio.h>

void print1DArray(size_t size, int array[size]);
void print2DArray(size_t row, size_t column, int array[row][column]);

int main(void) {
	printf("%s", "Enter size of one dimensional array: ");
	int arraySize = 0; // size of 1-D array
	scanf("%d", &arraySize);
	
	int array[arraySize]; // declare 1-D variable-length array
	
	printf("%s", "Enter number of rows and column in a 2-D array: ");
	int row1 = 0;
	int col1 = 0;
	scanf("%d %d", &row1, &col1);
	
	int array2D1[row1][col1]; // declare 2-D variable-length array
	
	printf("%s", "Enter number of rows and column in another 2-D array: ");
	int row2 = 0;
	int col2 = 0;
	scanf("%d %d", &row2, &col2);
	
	int array2D2[row2][col2]; // declare 2-D variable-length array
	
	// test size of operator in VLA (variable length array)
	printf("\n\nsizeof(array) yields array size of %zu bytes\n\n", sizeof(array));
	
	// assign elements to D-1 VLA
	for (size_t i = 0; i < arraySize; ++i) {
		array[i] = i * i;
	}
	
	// assign elements to first D-2 VLA
	for (size_t i = 0; i < row1; ++i) {
		for (size_t j = 0; j < col1; ++j) {
			array2D1[i][j] = i + j;
		}
	}
	
	// assign elements to second D-2 VLA
	for (size_t i = 0; i < row2; ++i) {
		for (size_t j = 0; j < col2; ++j) {
			array2D2[i][j] = i + j;
		}
	}
	
	puts("\nOne-dimentional array");
	print1DArray(arraySize, array); // pass 1-D VLA to function
	
	puts("\nFirst two-dimentional array");
	print2DArray(row1, col1, array2D1);
	
	puts("\nSecond two-dimentional array");
	print2DArray(row2, col2, array2D2);
}

void print1DArray(size_t size, int array[size]) {
	// Output content of array
	for (size_t i = 0; i < size; ++i) {
		printf("array[%zu] = %d\n", i, array[i]);
	}
}

void print2DArray(size_t row, size_t column, int array[row][column]) {
	// output content of array
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < column; ++j) {
			printf("%5d", array[i][j]);
		}
		puts("");
	}
}
