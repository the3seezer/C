<<<<<<< HEAD
/* theBitRiddler
  2/24/2023 
  5:19 	PM
  Knight Tour Brute-Force Approach
  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

int knight(int, int ch[][SIZE]); // move the knight piece
int valid(int, int, int, int, int ch_o[][SIZE]); // check the move validity
void display(int array[][SIZE]);

int main(void) {
	srand(time(NULL));
	int chess[SIZE][SIZE] = {0};
	static int number = 1;
	int knight_reply = 0;
	while (number <= 64) {
		knight_reply = knight(number, chess);
		if (knight_reply == 2) {
			break;
		}
		else if (knight_reply == 3) {
			break;
		}
	}
	display(chess);
} /* end main */

int knight(int numb, int ch[][SIZE]) {
	int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	
	int currentRow = 0;
	int currentColumn = 0;
	
	int valid_reply = 0;
	int randomMoveNumber = 0;
	while (valid_reply != 2 || valid_reply != 3 || valid_reply != -1) {
		randomMoveNumber = rand() % 8;
		valid_reply = valid(currentColumn, currentRow, horizontal[randomMoveNumber], vertical[randomMoveNumber], ch);
		if (valid_reply == 2) {
			ch[currentRow][currentColumn] = numb;
			numb++;
			break;
		}
		else if (valid_reply == 3) {
			currentRow += vertical[randomMoveNumber];
			currentColumn += horizontal[randomMoveNumber];
			ch[currentRow][currentColumn] = numb;
			numb++;
			break;
		}
	}
	
	if (numb < 64 && valid_reply == -1) { // check if the tour isn't complete
		return 2;
	}
	else if (numb == 64 && valid_reply == -1) {
		return 3;
	}
} /* end knight */

int valid(int row, int column, int x, int y, int ch_o[][SIZE]) {
	if (row >= 0 && row <= 7 && column >= 0 && column <= 7) {
		if (ch_o[row][column] == 0) {
			return 2;
		}
	}
	else if (ch_o[row][column] != 0) {
		row += y;
		column += x;
		if (row >= 0 && row <= 7 && column >= 0 && column <= 7) {
			if (ch_o[row][column] == 0) {
				return 3;
			}
		}
	}
	return -1;
} /* end valid */

void display(int array[][SIZE]) {
	// display row
	for (size_t i = 0; i < 8; ++i) {
		// display column 
		for (size_t j = 0; j < 8; ++j) {
			printf("%5d", array[i][j]);
		}
		puts("");
	}
} /* end display */
=======
/* theBitRiddler
  2/24/2023 
  5:19 	PM
  Knight Tour Brute-Force Approach
  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

int knight(int, int ch[][SIZE]); // move the knight piece
int valid(int, int, int, int, int ch_o[][SIZE]); // check the move validity
void display(int array[][SIZE]);

int main(void) {
	srand(time(NULL));
	int chess[SIZE][SIZE] = {0};
	static int number = 1;
	int knight_reply = 0;
	while (number <= 64) {
		knight_reply = knight(number, chess);
		if (knight_reply == 2) {
			break;
		}
		else if (knight_reply == 3) {
			break;
		}
	}
	display(chess);
} /* end main */

int knight(int numb, int ch[][SIZE]) {
	int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	
	int currentRow = 0;
	int currentColumn = 0;
	
	int valid_reply = 0;
	int randomMoveNumber = 0;
	while (valid_reply != 2 || valid_reply != 3 || valid_reply != -1) {
		randomMoveNumber = rand() % 8;
		valid_reply = valid(currentColumn, currentRow, horizontal[randomMoveNumber], vertical[randomMoveNumber], ch);
		if (valid_reply == 2) {
			ch[currentRow][currentColumn] = numb;
			numb++;
			break;
		}
		else if (valid_reply == 3) {
			currentRow += vertical[randomMoveNumber];
			currentColumn += horizontal[randomMoveNumber];
			ch[currentRow][currentColumn] = numb;
			numb++;
			break;
		}
	}
	
	if (numb < 64 && valid_reply == -1) { // check if the tour isn't complete
		return 2;
	}
	else if (numb == 64 && valid_reply == -1) {
		return 3;
	}
} /* end knight */

int valid(int row, int column, int x, int y, int ch_o[][SIZE]) {
	if (row >= 0 && row <= 7 && column >= 0 && column <= 7) {
		if (ch_o[row][column] == 0) {
			return 2;
		}
	}
	else if (ch_o[row][column] != 0) {
		row += y;
		column += x;
		if (row >= 0 && row <= 7 && column >= 0 && column <= 7) {
			if (ch_o[row][column] == 0) {
				return 3;
			}
		}
	}
	return -1;
} /* end valid */

void display(int array[][SIZE]) {
	// display row
	for (size_t i = 0; i < 8; ++i) {
		// display column 
		for (size_t j = 0; j < 8; ++j) {
			printf("%5d", array[i][j]);
		}
		puts("");
	}
} /* end display */
>>>>>>> 78d99489bc9fd084c8e4baa79a5431b5829ff12e
