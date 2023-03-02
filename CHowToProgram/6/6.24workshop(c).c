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
int knightTour(int row, int column, int tour);

int main(void) {
	int complete[3] = {0};
	int tour = 1;
	for (size_t row = 3; row < 4; ++row) {
		for (size_t column = 0; column < SIZE; ++column) {
			++complete[knightTour(row, column, tour)];
			if (complete[99]) { // when row == 3 and column == 2, it simply doesn't run or debug!!!
				tour++;
				continue;
			}
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
	
	int forloop = 0;
	int forloop1 = 0;
	int forloop2 = 0;
	
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
		
		int inaccessibility = 9; // Find a square with minimum accessibility first
		int access_check = 0;
		for (moveNumber = 0; moveNumber < 8; ++moveNumber) { // Find minimum accessibility
			forloop = 1;
			forloop1++;
			
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
			forloop = 2;
			forloop2++;
			
			int valid_check = validMove(horizontal[moveNumber], vertical[moveNumber], currentColumn, currentRow);
			
			if (valid_check == 1) {
				
					access_check = chess_access[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]];
				if (chess[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]] == 0) {
					
					if (inaccessibility == access_check) {
						currentRow += vertical[moveNumber];
						currentColumn += horizontal[moveNumber];
						chess[currentRow][currentColumn] = ++number;
						
						accessUpdate(chess, chess_access);
						
						int inaccessibility = 9; // Find a square with minimum accessibility first
						int access_check = 0;
						
						break;
					}	
				}
				else if (chess[currentRow + vertical[moveNumber]][currentColumn + horizontal[moveNumber]] != 0 && moveNumber != 7) {
//							puts("\n\n\nEnds here!!!!!!");
//							printf("\ncurrentRow %d currentColumn %d\n", currentRow, currentColumn);
//							printf("moveNumber:%d, %d forloop %d: number:%d\n\n\n", moveNumber, (forloop == 1) ? forloop1: (forloop == 2) ? forloop2 : 0, (forloop == 1) ? 1: (forloop == 2) ? 2 : 0,  number);
//							return 99;
						if (row == 3 && column == 2) {
							puts("\n\n\nEnds here!!!!!!");
							printf("\ncurrentRow %d currentColumn %d\n", currentRow, currentColumn);
							printf("moveNumber:%d, %d forloop %d: number:%d\n\n\n", moveNumber, (forloop == 1) ? forloop1: (forloop == 2) ? forloop2 : 0, (forloop == 1) ? 1: (forloop == 2) ? 2 : 0,  number);
							return 99;
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
