// theBitRiddler
// 1/22/2023
// 9:00 PM
// Knight's Tour
#include <stdio.h>
#define SIZE 8

enum ChessMove {
	CONTINUE, END, STOP
};

void startChess(int b[][SIZE]);
int validMove(int, int, int, int);
void displayChess(const int b[][SIZE]);

int main(void) {
	int chess[SIZE][SIZE];
	enum ChessMove Status = CONTINUE;
	int currentRow = 0;
	int currentColumn = 0;
	int moveNumber = 0;
	int number = 0;
	int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	
	startChess(chess);
	displayChess(chess);
	
	chess[currentRow][currentColumn] = ++number;
	while (Status == CONTINUE) {
		for (moveNumber = 0; moveNumber < 8; ++moveNumber) {
			int valid_check = validMove(horizontal[moveNumber], vertical[moveNumber], currentColumn, currentRow);
			if (valid_check == 1) {
				if (chess[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]] == 0) {
					currentRow += vertical[moveNumber];
					currentColumn += horizontal[moveNumber];
					chess[currentRow][currentColumn] = ++number;
					break;	
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
	
	displayChess(chess);
	printf("The Knight made %d moves", number);
}

int validMove(int x, int y, int nextX, int nextY) { // Row for y and Column for x;
	nextX += x;
	nextY += y;
	if (nextX >= 0 && nextX <= 7 && nextY >= 0 && nextY <= 7) {
		return 1;
	}
	return -1;
}

void displayChess(const int b[][SIZE]) {
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
