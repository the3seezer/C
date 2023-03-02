// TheBitRiddler
// 12/17/2022
// 10:05 AM
//nitializing multidimensional arrays.
#include <stdio.h>

void printArray(int b[][3]);

int main(void) {
	int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};
	puts("Values in array 1 by row are: ");
	printArray(array1);
	
	int array2[2][3] = {{1, 2, 3}, {4, 5}};
	puts("Values in array 2 by row are: ");
	printArray(array2);
	
	int array3[2][3] = {{1, 2} ,{4}};
	puts("Values in array 3 by row are: ");
	printArray(array3);
}

void printArray(int b[][3]) {
	// loop through rows
	for (size_t i = 0; i <= 1; ++i) {
		// loop through columns
		for (size_t j = 0; j <= 2; ++j) {
			printf("%3d", b[i][j]);
		}
		printf("%s", "\n");
	}
}
