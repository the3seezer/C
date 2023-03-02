// theBitRiddler
// 2/24/2023
// 2:10 PM
// Knight tour 
#include <stdio.h>

#define SIZE 8

int knight(int, int);
int knightMove(int o[][SIZE], int n, int currentRow, int currentColumn);
int valid(int, int, int, int, int valid_o[][SIZE]);
void display(int array[][SIZE]);

int main(void) {
	int tour[5] = {0};
	int i = 0;
	int j = 0;
	for (i = 0; i < 8; ++i) {
		for (j = 0; j < 8; ++j) {
			++tour[knight(i, j)];
		}
	}
	printf("incomplete tours: %d\n"
	 "complete tours: %d\n", tour[2], tour[3]);
} /* end main */

int knight(int i, int j) {
	static int row = 0;
	row = i;
	row = 0;
	static int column = 0;
	column = j;
	column = 0;
	int chess[SIZE][SIZE] = {0};
	
	static int number = 1;
	int move = 0;
	
	while (number < 64) {
		move = knightMove(chess, number, row, column);
		if (move == 2) { // incomplete tour
			display(chess);
			return 2;
		}
		if (move == 3) { // complete tour
			display(chess);
			return 3;
		}
	}
	
} /* end knight */

int knightMove(int o[][SIZE], int n, int currentRow, int currentColumn) {
	int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	
	for (int moveNumber = 0; moveNumber < 8; moveNumber++) {
		if (o[currentRow][currentColumn] == 0) {
			o[currentRow][currentColumn] = n;
			n++;
			break;
		}
		else if (valid(horizontal[moveNumber], vertical[moveNumber], currentRow, currentColumn, o)) {
			currentRow += vertical[moveNumber];
			currentColumn += horizontal[moveNumber];
			o[currentRow][currentColumn] = n;
			n++;
			break;
		}
		else {
			if (n < 64) {
				return 2; // incomplete tour
			}
			else {
				return 3; // complete tour
			}
		}
	}
} /* end knightMove */

int valid(int hrzntl, int vrticl, int crrntRw, int crrntClmn, int valid_o[][SIZE]) {
	int nextRow = vrticl + crrntRw;
	int nextColumn = hrzntl + crrntClmn;
	if (valid_o[nextRow][nextColumn] == 0 && nextRow >= 0 && nextRow <= 7 && nextColumn >= 0 && nextColumn <= 7) {
		return 1;
	}
	return -1;
} /* end valid */

void display(int array[][SIZE]) {
	for (size_t n = 0; n < SIZE; n++) {
		for (size_t m = 0; m < SIZE; m++) {
			printf("%5d", array[n][m]);
		}
		puts("");
	}
}
