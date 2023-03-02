// theBitRiddler
// 1/22/2023
// 9:00 PM
// Knight's Tour
#include <stdio.h>
#define SIZE 8

int chess[SIZE][SIZE] = {0};

int nextRow(int, int);
int nextColumn(int, int);
void printChess(int b[][SIZE]);
int solve(int, int, int);

int main(void) {
	printChess(chess);
	solve(0, 0, 0);
	printChess(chess);
}
int solve(int currentRow, int currentColumn, int number) {
	int moveNumber = 0;
	
	if (number == 64) {
		return -1;
	}
	if (chess[currentRow][currentColumn] == 0) {
		while (moveNumber < 8) {
			if (nextRow(currentRow, moveNumber) != -1 && nextColumn(currentColumn, moveNumber) != -1) {
				chess[currentRow][currentColumn] = number;
				if (solve(nextRow(currentRow, moveNumber), nextColumn(currentColumn, moveNumber), number + 1)) {
					return 1;
				}
			}
			++moveNumber;
		}
		chess[currentRow][currentColumn] = 0;
	}
	return 0;	
}

int nextRow(int currentRow, int moveNumber) {
	int vertical[8] = {0};
	vertical[0] = -1;
	vertical[1] = -2;
	vertical[2] = -2;
	vertical[3] = -1;
	vertical[4] = 1;
	vertical[5] = 2;
	vertical[6] = 2;
	vertical[7] = 1;
	
	if (moveNumber == 0) {
		currentRow += vertical[moveNumber];
	}
	else if (moveNumber == 1) {
		currentRow += vertical[moveNumber];
	}
	else if (moveNumber == 2) {
		currentRow += vertical[moveNumber];
	}
	else if (moveNumber == 3) {
		currentRow += vertical[moveNumber];
	}
	else if (moveNumber == 4) {
		currentRow += vertical[moveNumber];
	}
	else if (moveNumber == 5) {
		currentRow += vertical[moveNumber];
	}
	else if (moveNumber == 6) {
		currentRow += vertical[moveNumber];
	}
	else if (moveNumber == 7) {
		currentRow += vertical[moveNumber];
	}
	
	if (currentRow < 0 || currentRow > SIZE - 1) {
		return -1;
	}
	else {
		return currentRow;
	}
}

int nextColumn(int currentColumn, int moveNumber) {
	int horizontal[8] = {0};
	horizontal[0] = 2; 
	horizontal[1] = 1; 
	horizontal[2] = -1; 
	horizontal[3] = -2; 
	horizontal[4] = -2; 
	horizontal[5] = -1; 
	horizontal[6] = 1; 
	horizontal[7] = 2; 
	
	if (moveNumber == 0) {
		currentColumn += horizontal[moveNumber];
	}
	else if (moveNumber == 1) {
		currentColumn += horizontal[moveNumber];
	}
	else if (moveNumber == 2) {
		currentColumn += horizontal[moveNumber];
	}
	else if (moveNumber == 3) {
		currentColumn += horizontal[moveNumber];
	}
	else if (moveNumber == 4) {
		currentColumn += horizontal[moveNumber];
	}
	else if (moveNumber == 5) {
		currentColumn += horizontal[moveNumber];
	}
	else if (moveNumber == 6) {
		currentColumn += horizontal[moveNumber];
	}
	else if (moveNumber == 7) {
		currentColumn += horizontal[moveNumber];
	}
	
	if (currentColumn < 0 || currentColumn > SIZE - 1) {
		return -1;
	}
	else {
		return currentColumn;
	}
}

void printChess(int b[][SIZE]) {
	for (size_t i = 0; i < SIZE; ++i) { // row
		for (size_t j = 0; j < SIZE; ++j) { // column
			printf("%5d", b[i][j]);
		}
		puts("");
	}
	puts("\n\n");
}
