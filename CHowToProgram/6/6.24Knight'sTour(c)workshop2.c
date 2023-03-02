// theBitRiddler
// 2/5/2023
// 10:10 AM
// The Knight's tour "accessibility heuristic"
#include <stdio.h>
#define SIZE 8

enum ChessMove {
	CONTINUE, END, STOP
};

void startChess(int b[][SIZE]);
int validMove(int, int, int, int);
void displayChess(const int b[][SIZE], const int d[][SIZE]);
void accessUpdate(int o[][SIZE], int acs[][SIZE]);
void reduceAccess(int, int, int, int, int acs_r[][SIZE], int o_r[][SIZE]);

int main(void) {
	int chess[SIZE][SIZE];
	enum ChessMove Status = CONTINUE;
	int currentRow = 0;
	int currentColumn = 0;
	int moveNumber = 0;
	int number = 0;
	int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	
	int chess_access[SIZE][SIZE] = {{2, 3, 4, 4, 4, 4, 3, 2},
									{3, 4, 6, 6, 6, 6, 4, 3},
									{4, 6, 8, 8, 8, 8, 6, 4},
									{4, 6, 8, 8, 8, 8, 6, 4},
									{4, 6, 8, 8, 8, 8, 6, 4},
									{4, 6, 8, 8, 8, 8, 6, 4},
									{3, 4, 6, 6, 6, 6, 4, 3},
									{2, 3, 4, 4, 4, 4, 3, 2}};
									
	startChess(chess);
	displayChess(chess, chess_access);
	
	chess[currentRow][currentColumn] = ++number;
	accessUpdate(chess, chess_access);
	displayChess(chess, chess_access);
	
	while (Status == CONTINUE) {
		int inaccessibility = 9; // Find a square with minimum accessibility first
		int access_check = 0;
		for (moveNumber = 0; moveNumber < 8; ++moveNumber) { // Find minimum accessibility
			int valid_check = validMove(horizontal[moveNumber], vertical[moveNumber], currentColumn, currentRow);
			if (valid_check == 1) {
				if (chess[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]] == 0) {
					access_check = chess_access[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]];
					if (access_check < inaccessibility) {
						inaccessibility = access_check;
					}	
				}
			}
		}
		for (moveNumber = 0; moveNumber < 8; ++moveNumber) { // Move to the minimum accessible square
			int valid_check = validMove(horizontal[moveNumber], vertical[moveNumber], currentColumn, currentRow);
			if (valid_check == 1) {
				if (chess[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]] == 0) {
					access_check = chess_access[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]];
					if (inaccessibility == access_check) {
						currentRow += vertical[moveNumber];
						currentColumn += horizontal[moveNumber];
						chess[currentRow][currentColumn] = ++number;
						accessUpdate(chess, chess_access);
						break;
					}	
				}
				else if (chess[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]] != 0 && moveNumber == 7) {
					Status = STOP;
				}
			}
		}
		if (number == 64) {
			Status = END;
		}
	}
	
	displayChess(chess, chess_access);
	printf("The Knight made %d moves", number);
} /* end main */

void accessUpdate(int o[][SIZE], int acs[][SIZE]) {
	int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	// loop through original array
	for (size_t i = 0; i < SIZE; ++i) {
		for (size_t j = 0; j < SIZE; ++j) {
			if (o[i][j] != 0) {
				acs[i][j] = 0;
			}
			else {
				/* look for a filled square and reduce the accessibility of squares accessing it */
				for (size_t moveAccess = 0; moveAccess < 8; ++moveAccess) {
					reduceAccess(horizontal[moveAccess], vertical[moveAccess], j, i, acs, o);
				}
			}
		}
	}
} /* end accessUpdate */

void reduceAccess(int x, int y, int thisX, int thisY, int acs_r[][SIZE], int o_r[][SIZE]) {
	int prevX = thisX; /* record previous column */
	int prevY = thisY; /* record previous row */
	thisX += x;  /* column */
	thisY += y;  /* row */
	
	/* look for a filled square and reduce the accessibility of a square accessing it */
	if (o_r[thisY][thisX] != 0 && thisX >= 0 && thisX <= 7 && thisY >= 0 && thisY <= 7 && acs_r[thisY][thisX]) {
		--acs_r[prevY][prevX];
	}
} /* end reduceAccess */

int validMove(int x, int y, int nextX, int nextY) { // Row for y and Column for x;
	nextX += x;
	nextY += y;
	if (nextX >= 0 && nextX <= 7 && nextY >= 0 && nextY <= 7) {
		return 1;
	}
	return -1;
}

void displayChess(const int b[][SIZE], const int d[][SIZE]) {	
	// Display accessibility 
	puts("Accessibility");
	printf("%s\n", "         [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]");
	for (size_t w = 0; w < SIZE; ++w) {
		printf("[%4d]", w);
		for (size_t z = 0; z < SIZE; ++z) {
			printf("%5d", d[w][z]);
		}
		puts("");
	}
	puts("\n");
	printf("%s", "Chessboard\n");
	printf("%s\n", "       [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]");
	for (size_t i = 0; i < SIZE; ++i) {
		printf("%4d", i);
		for (size_t j = 0; j < SIZE; ++j) {
			printf("%5d", b[i][j]);
		}
		puts("");
	}
	puts("\n");
}

void startChess(int b[][SIZE]) {
	for (size_t i = 0; i < SIZE; ++i) {
		for (size_t j = 0; j < SIZE; ++j) {
			b[i][j] = 0;
		}
	}
}
