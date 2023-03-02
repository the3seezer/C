// theBitRiddler
// 12/23/2022
// 9:02 AM
// 6.9
#include <stdio.h>
#define ROW 2
#define COL 5

int smallest(const int b[][COL], size_t rows, size_t columns);
void printFirstRow(const int b[][COL], size_t rows, size_t columns);
int totalOfTheFourthCol(const int b[][COL], size_t rows, size_t columns);
void printArray(const int b[][COL], size_t rows, size_t columns);

int main(void) {
	int t[ROW][COL] = {0}; // 6.9(a), t have 2 rows 6.9(b), t have 5 columns 6.9(c), t have rows * columns 10 elements 6.9(d)
	// t[1][0],t[1][1],t[1][2],t[1][3],t[1][4] 6.9(e)
	// t[0][2] and t[1][2] 6.9(f)
	t[0][1] = 0; // 6.9(g)
	t[0][0] = 0; t[0][1] = 0; t[0][2] = 0; t[0][3] = 0; t[0][4] = 0; // 6.9(h)
	t[1][0] = 0; t[1][1] = 0; t[1][2] = 0; t[1][3] = 0; t[1][4] = 0;
	
	for (size_t i = 0; i < ROW; ++i) { // 6.9(i)
		for (size_t j = 0; j < COL; ++j) {
			t[i][j] = 0;
		}
	}
	
	for (size_t i = 0; i < ROW; ++i) { // 6.9(j)
		for (size_t j = 0; j < COL; ++j) {
			scanf("%d", &t[i][j]);
		}
	}
	
	printf("smallest: %d\n", smallest(t, ROW, COL)); //6.9(k)
	
	printFirstRow(t, ROW, COL); // 6.9(l)
	
	printf("\nTotal of the fourth column: %d\n", totalOfTheFourthCol(t, ROW, COL)); // 6.9(m)
	
	printArray(t, ROW, COL);
}

int smallest(const int b[][COL], size_t rows, size_t columns) {
	int smallest = 100; // to highest possible value
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			if (b[i][j] < smallest) {
				smallest = b[i][j];
			}
		}
	}
	return smallest;
}

void printFirstRow(const int b[][COL], size_t rows, size_t columns) {
	printf("%s","First Row");		
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			if (i == 0) {
				printf("%3d", b[i][j]);
			}
		}
	}
}

int totalOfTheFourthCol(const int b[][COL], size_t rows, size_t columns) {
	int total = 0;
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			if (j == 3) {
				total += b[i][j];
			}
		}
	}
	return total;
}

void printArray(const int b[][COL], size_t rows, size_t columns) {
	puts("\n\nRows         Columns          \n       [0]  [1]  [2]  [3]  [4]");
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			if (j == 0) {
				printf("[%zu] ", i);
			}
			printf("%5d", b[i][j]);
		}
		puts("");
	}
}
