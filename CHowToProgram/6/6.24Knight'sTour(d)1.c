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
void reduceAccess(int, int, int, int, int acs_r[][SIZE]);
int nextAccessCheck(int, int, int, int, int nxt_acs[][SIZE]);
int nextAccessCompare(int, int, int, int, int nxt_acs[][SIZE]);
int nextValidMove(int xxC, int yyC, int nextXC, int nextYC);
int knightTour(int row, int column, int tour);

int main(void) {
	int complete[3] = {0};
	int tour = 1;
	for (size_t row = 0; row < SIZE; ++row) {
		for (size_t column = 0; column < SIZE; ++column) {
			if (row == 3 && column == 2) { // when row == 3 and column == 2, it simply doesn't run or debug!!!
				tour++;
				continue;
			}
			++complete[knightTour(row, column, tour)];
			tour++;
		}
	}
	printf("Complete tours are %d\nIncomplete Tours are %d", complete[2], complete[1]);
}

int knightTour(int row, int column, int tour) {
	int chess[SIZE][SIZE];
	enum ChessMove Status = CONTINUE;
	int currentRow = row;
	int currentColumn = column;
	int moveNumber = 0;
	int number = 0;
	int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	
	int inaccessibility = 9; // Find a square with minimum accessibility first
	int access_check = 0;
	
	int next_inaccessibility = 9; // Find a square with minimum accessibility first of the square with minimum accessibility
	int next_access_check = 0;
	
	int chess_access[SIZE][SIZE] = {{2, 3, 4, 4, 4, 4, 3, 2},
									{3, 4, 6, 6, 6, 6, 4, 3},
									{4, 6, 8, 8, 8, 8, 6, 4},
									{4, 6, 8, 8, 8, 8, 6, 4},
									{4, 6, 8, 8, 8, 8, 6, 4},
									{4, 6, 8, 8, 8, 8, 6, 4},
									{3, 4, 6, 6, 6, 6, 4, 3},
									{2, 3, 4, 4, 4, 4, 3, 2}};
									
	startChess(chess);
//	displayChess(chess, chess_access);
	
	chess[currentRow][currentColumn] = ++number;
	accessUpdate(chess, chess_access);
//	displayChess(chess, chess_access);
	
	while (Status == CONTINUE) {
		inaccessibility = 9; // Find a square with minimum accessibility first
		access_check = 0;
		
		next_inaccessibility = 9; // Find a square with minimum accessibility first of the square with minimum accessibility
		next_access_check = 0;

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
		for (moveNumber = 0; moveNumber < 8; ++moveNumber) { // Find minimum accessibility
			int valid_check = validMove(horizontal[moveNumber], vertical[moveNumber], currentColumn, currentRow);
			if (valid_check == 1) {
				if (chess[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]] == 0) {
					access_check = chess_access[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]];
					if (inaccessibility == access_check) {
						int thisAccess = nextAccessCheck(currentRow + vertical[moveNumber], currentColumn + horizontal[moveNumber], next_inaccessibility, next_access_check, chess_access);
						next_inaccessibility = thisAccess;
//						inaccessibility = access_check;
					}	
				}
			}
		}
		for (moveNumber = 0; moveNumber < 8; ++moveNumber) { // Move to the minimum accessible square
			int valid_check = validMove(horizontal[moveNumber], vertical[moveNumber], currentColumn, currentRow);
			if (valid_check == 1) {
				if (chess[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]] == 0) {
					access_check = chess_access[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]];
					int thisCheck = nextAccessCompare(currentRow + vertical[moveNumber], currentColumn + horizontal[moveNumber], next_inaccessibility, next_access_check, chess_access);
					next_access_check = thisCheck;
					if (inaccessibility == access_check && next_inaccessibility == next_access_check) {
						currentRow += vertical[moveNumber];
						currentColumn += horizontal[moveNumber];
						chess[currentRow][currentColumn] = ++number;
						accessUpdate(chess, chess_access);
						break;
					}
					else if (inaccessibility == access_check && nextAccessCompare(currentRow + vertical[moveNumber], currentColumn + horizontal[moveNumber], next_inaccessibility, next_access_check, chess_access) == -2) {
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
	printf("The Knight made %d moves, \nfrom square; chess[%d][%d]\nTour number %d\n",
	 number, row, column, tour);
	
	if (Status == STOP) {
		return 1;
	}
	else if (Status == END) {
		return 2;
	}
} /* end knightTour */

int nextAccessCompare(int nextRow, int nextColumn, int next_inaccessibility1, int next_access_check1, int nxt_acs[][SIZE]) {
		
	int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	
	for (size_t nextMoveNumber = 0; nextMoveNumber < 8; ++nextMoveNumber) {
		int otherNextRow = nextRow + vertical[nextMoveNumber];
		int otherNextColumn = nextColumn + horizontal[nextMoveNumber];
		if (nextValidMove(horizontal[nextMoveNumber], vertical[nextMoveNumber], nextColumn, nextRow) == 1 && nxt_acs[otherNextRow][otherNextColumn] != 0) {
			next_access_check1 = nxt_acs[otherNextRow][otherNextColumn];
			if (next_inaccessibility1 == next_access_check1) {
				return next_access_check1;
			}
		}
	}
	return -2;
} /* end nextAccessCompare */

int nextAccessCheck(int nextRowC, int nextColumnC, int next_inaccessibility1C, int next_access_check1C, int nxt_acsC[][SIZE]) {
	
	int horizontalC[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int verticalC[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	
	nxt_acsC[nextRowC][nextColumnC];
	
	for (size_t nextMoveNumberC = 0; nextMoveNumberC < 8; ++nextMoveNumberC) {
		int otherNextRowC = nextRowC + verticalC[nextMoveNumberC];
		int otherNextColumnC = nextColumnC + horizontalC[nextMoveNumberC];
		if (nextValidMove(horizontalC[nextMoveNumberC], verticalC[nextMoveNumberC], nextColumnC, nextRowC) == 1 && nxt_acsC[otherNextRowC][otherNextColumnC] != 0) {
			
			nxt_acsC[otherNextRowC][otherNextColumnC];
			
			next_access_check1C = nxt_acsC[otherNextRowC][otherNextColumnC];
			if (next_access_check1C < next_inaccessibility1C) {
				next_inaccessibility1C = next_access_check1C;
			}
		}
	}
	return next_inaccessibility1C;
} /* end nextAccessCheck */

void accessUpdate(int o[][SIZE], int acs[][SIZE]) {
	int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	// loop through original array
	for (size_t i = 0; i < SIZE; ++i) {
		for (size_t j = 0; j < SIZE; ++j) {
			if (o[i][j] != 0 && acs[i][j]) { /* Stop the enteruptions in the future */
				acs[i][j] = 0;
				
				/* look for the filled square and reduce the accessibility of squares accessing it */
				for (size_t moveAccess = 0; moveAccess < 8; ++moveAccess) {
					reduceAccess(horizontal[moveAccess], vertical[moveAccess], j, i, acs);
				}
			}
		}
	}
} /* end accessUpdate */

void reduceAccess(int x, int y, int thisX, int thisY, int acs_r[][SIZE]) {
//	int prevX = thisX; /* record previous column */
//	int prevY = thisY; /* record previous row */
	thisX += x;  /* column */
	thisY += y;  /* row */
	
	/* look for the filled square and reduce the accessibility of a square accessing it */
	if (thisX >= 0 && thisX <= 7 && thisY >= 0 && thisY <= 7 && acs_r[thisY][thisX]) {
		--acs_r[thisY][thisX];
	}
} /* end reduceAccess */

int nextValidMove(int xxC, int yyC, int nextXC, int nextYC) { // Row for y and Column for x;
	nextXC += xxC;
	nextYC += yyC;
	if (nextXC >= 0 && nextXC <= 7 && nextYC >= 0 && nextYC <= 7) {
		return 1;
	}
	return -1;
}

int validMove(int xx, int yy, int nextX, int nextY) { // Row for y and Column for x;
	nextX += xx;
	nextY += yy;
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
	for (size_t u = 0; u < SIZE; ++u) {
		printf("%4d", u);
		for (size_t v = 0; v < SIZE; ++v) {
			printf("%5d", b[u][v]);
		}
		puts("");
	}
	puts("\n");
}

void startChess(int b[][SIZE]) {
	for (size_t u = 0; u < SIZE; ++u) {
		for (size_t v = 0; v < SIZE; ++v) {
			b[u][v] = 0;
		}
	}
}
