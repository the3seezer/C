// theBitRiddler
// 1/1/2023
// 12:37 PM
// the order in which they are set to zero
#include <stdio.h>
#define COL 5

void oder(int b[][COL]);

int main(void) {
	int sales[3][5] = {0};
	oder(sales);
}

void oder(int b[][COL]) {
	puts("The oder in which the 3 by 5 array is set to zero");
	int od = 0;
	printf("%s\n%s\n", "        ----- Column -----", "       [1]  [2]  [3]  [4]  [5]");
	for (size_t row = 0; row <= 2; ++row) {
		printf("row:%d", 1 + row);
 		for (size_t column = 0; column <= 4; ++column) {
 			b[row][column] = 0;
 			printf("%5d", od);
 			++od;
 		}
 		puts("");
	}
}
