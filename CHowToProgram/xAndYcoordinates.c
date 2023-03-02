#include <stdio.h>
#define SIZE 50

int main(void) {
	int floor[SIZE][SIZE] = {0};
	// row == y; values along y lines
	for (size_t y = 0; y < SIZE; ++y) {
		// column == x; values along x lines
		for (size_t x = 0; x < SIZE; ++x) {
			if ((x == 20 || x == 31) && y >= 20 && y <= 31) {
				printf("%s", "*"); 
			}
			else if ((y == 20 || y == 31) && x >= 20 && x <= 31) {
				printf("%s", "*");
			}
			else {
				printf("%s", " ");
			}
		}
		puts("");
	}
}
