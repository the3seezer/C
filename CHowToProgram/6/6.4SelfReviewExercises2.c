// theBitRiddler
// 12/21/2022
// 6:02 PM
// Self Review Exercises
#include <stdio.h>
#define SIZE 3

void printArray(const int b[][SIZE]);

int main(void) {
	int table[SIZE][SIZE] = {{1, 8}, {2, 4, 6}, {5}};
	printf("Number of elements: %d\n", sizeof(table) / 4); // 6.4(b) each integer element has 4 bytes
	printf("Number of elements: %d\n", SIZE * SIZE);
	
	// 6.4(c) 
	// loop through rows
//	for (size_t x = 0; x < SIZE; ++x) {
//		// loop through columns
//		for (size_t y = 0; y < SIZE; ++y) {
//			table[x][y] = x + y;
//		}
//	}
	
//	int table[SIZE][SIZE] = {{1, 8}, {2, 4, 6}, {5}};
//	table[0][0] = 1;
//	table[0][1] = 8;
//	
//	table[1][0] = 2;
//	table[1][1] = 4;
//	table[1][2] = 6;
//	
//	table[2][0] = 5;
//	
	printArray(table);
}

void printArray(const int b[][SIZE]) { // 6.4(d)
	for (size_t x = 0; x < SIZE; ++x) {
		for (size_t y = 0; y < SIZE; ++y) {
			printf("table[%zu][%zu] = %3d\n", x, y, b[x][y]);
		}
		puts("");
	}
}
