// theBitRiddler
// 1/12/2023
// 8:24 AM
// Turtle Graphics
#include <stdio.h>
#include <unistd.h>

#define HEIGHT 50
#define WIDTH 50
#define SIZE 10

enum Status { 
	UP, DOWN, CONTINUE, STOP
};

int execute(int b[][WIDTH], char instruction[]);
void printGraphicFloor(const int b[][WIDTH], int center);
int trackCenter(int x, int y); // row == y values and column == x values

int main(void) {
	enum Status Simulation = CONTINUE;
	puts("\nEnter commands: write 'help' to see list of commands");
	
	int floor[HEIGHT][WIDTH] = {0};	
	char command[SIZE] = "";
	
	while(Simulation == CONTINUE){
		if (execute(floor, gets(command)) == 2) {
			Simulation = STOP;
		}
	}
}


int execute(int b[][WIDTH], char instruction[]) {
	int move = 0;
	int move_flag_forward_col = 0;
	int move_flag_reverse_col = 0;
	int move_flag_forward_row = 0;
	int move_flag_reverse_row = 0;
	// track the pen, the row, the column and the turn
	static int pen = 0;
	
	static int row = 1;
	static int column = 2;
	static int turn = 3;
	
	// for Tracking the current position
		// Turtle previous position
	static int fro_row_position = 0; 
	static int fro_column_position = 0;
		// turtle current position
	static int row_position = 0;
	static int column_position = 0;
	
	
	char hold[5] = "";
	for (size_t i = 0; i < SIZE; ++i) { // reading the commands
		if (instruction[i] != 0) {
			if (instruction[i] == ' ') {
				continue;
			}
			for (size_t j = 0; j < 5; ++j) {
				if (hold[j] == 0) { // get empty hold element; assigned to zero
					hold[j] = instruction[i];
					break;
				}
			}
		}
	}
	
	// uterizing the commands
	switch (hold[0]) {
		case 'e':
			switch (hold[1]) {
				case 'x':
					switch (hold[2]) {
						case 'i':
							switch (hold[3]) {
								case 't':
									return 2;
									break;
								default:
									puts("\nWrong command");
									break;
							}
							break;
						default:
							puts("\nWrong command");
							break;
					}
					break;
				default:
					puts("\nWrong Command");
					break;	
			}
			break;
		case 'c':
			switch (hold[1]) {
				case 'l':
					switch (hold[2]) {
						case 'e':
							switch (hold[3]) {
								case 'a':
									switch (hold[4]) {
										case 'r':
											system("cls");
											break;
										default:
											puts("Wrong Command");
											break;
									}
									break;
								default:
									puts("Wrong Command");
									break;
							}
							break;
						case 's':
							system("cls");
							break;
						default:
							puts("Wrong Command");
							break;
					}
					break;
				default:
					puts("Wrong Command");
					break;
			}
			break;
		case 'h':
			switch (hold[1]) {
				case 'e':
					switch (hold[2]) {
						case 'l':
							switch (hold[3]) {
								case 'p':
									printf("%s%s", "\n Help List:\n", "1 == PEN UP\n2 == PEN DOWN\n3 == Turn right\n4 == Turn Left\n5,...== 5 is a move command. The number after comma is for steps to be taken"
									"\n6 == display\n7 == erase\n8 == Restart\n9 or exit == End of Line\n"
									"clear or cls == to clean the screen\nhelp == To see commands\n");
									break;
								default:
									puts("Wrong Command");
									break;
							}
							break;
						default:
							puts("Wrong Command");
							break;
					}
					break;
				default:
					puts("wrong Command");
					break;
			}
			break;
		case '1':
			pen = 1;
			break;
		case '2':
			pen = 2; // PEN DOWN
			break;
		case '3':
			turn = 1;
			break;
		case '4':
			turn = 2;
			break;
		case '5':
			switch (hold[1]) {
				case ',':
					switch(hold[2]) {
						case '1':
							switch(hold[3]) {
								case '0':
									move = 10;
									break;
								case '1':
									move = 11;
									break;
								case '2':
									move = 12;
									break;
								case '3':
									move = 13;
									break;
								case '4':
									move = 14;
									break;
								case '5':
									move = 15;
									break;
								case '6':
									move = 16;
									break;
								case '7':
									move = 17;
									break;
								case '8':
									move = 18;
									break;
								case '9':
									move = 19;
									break;
								default:
									move = 1;
									break;
							}
							break;
						case '2':
							switch(hold[3]) {
								case '0':
									move = 20;
									break;
								case '1':
									move = 21;
									break;
								case '2':
									move = 22;
									break;
								case '3':
									move = 23;
									break;
								case '4':
									move = 24;
									break;
								case '5':
									move = 25;
									break;
								case '6':
									move = 26;
									break;
								case '7':
									move = 27;
									break;
								case '8':
									move = 28;
									break;
								case '9':
									move = 29;
									break;
								default:
									move = 2;
									break;
							}
							break;
						case '3':
							switch(hold[3]) {
								case '0':
								move = 30;
								break;
							case '1':
								move = 31;
								break;
							case '2':
								move = 32;
								break;
							case '3':
								move = 33;
								break;
							case '4':
								move = 34;
								break;
							case '5':
								move = 35;
								break;
							case '6':
								move = 36;
								break;
							case '7':
								move = 37;
								break;
							case '8':
								move = 38;
								break;
							case '9':
								move = 39;
								break;
							default:
								move = 3;
								break;
						}
						break;
					case '4':
						switch(hold[3]) {
							case '0':
								move = 40;
								break;
							case '1':
								move = 41;
								break;
							case '2':
								move = 42;
								break;
							case '3':
								move = 43;
								break;
							case '4':
								move = 44;
								break;
							case '5':
								move = 45;
								break;
							case '6':
								move = 46;
								break;
							case '7':
								move = 47;
								break;
							case '8':
								move = 48;
								break;
							case '9':
								move = 49;
								break;
							default:
								move = 4;
								break;
						}
						break;
					case '5':
						switch(hold[3]) {
							case '0':
								move = 50;
								break;
							case '1':
							case '2':
							case '3':
							case '4':
							case '5':
							case '6':
							case '7':
							case '8':
							case '9':
								puts("\nSyntax Error: Number of steps doesn't go above 50");
								break;
							default:
								move = 5;
								break;
						}
						break;
					case '6':
						move = 6;
						break;
					case '7':
						move = 7;
						break;
					case '8':
						move = 8;
						break;
					case '9':
						move = 9;
						break;
					default:
						puts("\nSyntax Error: Number of steps must never be less than 0 or greater than 50");
						break;
				}
				break;
			default:
				puts("\nSyntax Error: comma(',') is missing after 5");
				break;	
			}
			break;
		case '6':
			printGraphicFloor(b, trackCenter(column_position, row_position));
			break;
		case '7':
			pen = 3; // eraser
			break;
		case '8':
			for (size_t i = 0; i < HEIGHT; ++i) { // restart
				for (size_t j = 0; j < WIDTH; ++j) {
					b[i][j] = 0;
				}
			}
			row_position = 0;
			column_position = 0;
			
			pen = 0;
			
			row = 1;
			column = 2;
			turn = 3;
			break;
		case '9':
			return 2;
			break;
		default:
			puts("\nSyntax Error: The command you entered, doesn't exist in my compiler and my computer language");
			printf("%s%s", "\n Help List:\n", "1 == PEN UP\n2 == PEN DOWN\n3 == Turn right\n4 == Turn Left\n5,...== 5 is a move command. The number after comma is for steps to be taken"
			"\n6 == display\n7 == erase\n8 == Restart\n9 or exit == End of Line\n"
			"clear or cls == to clean the screen\nhelp == To see commands\n");
			break;
	} /* end switch */


// executing the commands
/*	 Direction And Turning
	 Turning Right
	 Row || Column 1 == HOLD, 2 == FORWARD, 3 == REVERSE
	 Turn 1 == RIGHT, 2 == LEFT, 3 == NOT_TURNING */
	if (row == 1 && column == 2 && turn == 1) { 
		row = 2;
		column = 1;
		turn = 3;
	}
	if (row == 2 && column == 1 && turn == 1) {
		row = 1;
		column = 3;
		turn = 3;
	}
	if (row == 1 && column == 3 && turn == 1) {
		row = 3;
		column = 1;
		turn = 3;
	}
	if (row == 3 && column == 1 && turn == 1) {
		row = 1;
		column = 2;
		turn = 3;
	}
	
	// Turning Left
	// Row || Column 1 == HOLD, 2 == FORWARD, 3 == REVERSE
	// Turn 1 == RIGHT, 2 == LEFT, 3 == NOT_TURNING
	if (row == 1 && column == 2 && turn == 2) {
		row = 3;
		column = 1;
		turn = 3;
	}
	if (row == 3 && column == 1 && turn == 2) {
		row = 1;
		column = 3;
		turn = 3;
	}
	if (row == 1 && column == 3 && turn == 2) {
		row = 2;
		column = 1;
		turn = 3;
	}
	if (row == 2 && column == 1 && turn == 2) {
		row = 1;
		column = 2;
		turn = 3;
	}
			
	
	// trace the condition in direction and move
	if (move) {
		if (row == 1 && column == 2 && turn == 3) {
			column_position += move;
			move_flag_forward_col = 1;
			if (column_position > 49) {
				column_position = 49;
			}
		}
		if (row == 2 && column == 1 && turn == 3) {
			row_position += move;
			move_flag_forward_row = 1;
			if (row_position > 49) {
				row_position = 49;
			}
		}
		if (row == 1 && column == 3 && turn == 3) {
			column_position -= move; 
			move_flag_reverse_col = 1;
			if (column_position < 0) {
				column_position = 0;
			}
		}
		if (row == 3 && column == 1 && turn == 3) {
			row_position -= move;
			move_flag_reverse_row = 1;
			if (row_position < 0) {
				row_position = 0;
			}
		}
	}

	
	//FORWARD LOOPS
	// column forward loop 
	if (move_flag_forward_col) {
		size_t row = fro_row_position;
		if (row == fro_row_position) {
			for (size_t column = fro_column_position; column < column_position; ++column) {
				if (pen == 2) {
					b[row][column] = 1;
				}
				else if (pen == 3) {
					b[row][column + 1] = 0;
				}
			}
		}
	}
	// row forward loop
	if (move_flag_forward_row) {
		for (size_t row = fro_row_position; row < row_position; ++row) {
			size_t column = fro_column_position;
			if (column == fro_column_position) {
				if (pen == 2) {
					b[row][column] = 1;
				}
				else if (pen == 3) {
					b[row + 1][column] = 0;
				}
			}
		}
	}
	
	// REVERSE LOOPS
	// column reverse loop 
	if (move_flag_reverse_col) {
		size_t row = fro_row_position;
		if (row == fro_row_position) {
			for (size_t column = fro_column_position; column > column_position; --column) {
				if (pen == 2) {
					b[row][column] = 1;
				}
				else if (pen == 3) {
					b[row][column - 1] = 0;
				}
			}
		}
	}
	// row reverse loop
	if (move_flag_reverse_row) {
		for (size_t row = fro_row_position; row > row_position; --row) {
			size_t column = fro_column_position;
			if (column == fro_column_position) {
				if (pen == 2) {
					b[row][column] = 1;
				}
				else if (pen == 3) {
					b[row - 1][column] = 0;
				}
			}
		}
	}
	
	// Get the current position;
	
	fro_row_position = row_position;
	fro_column_position = column_position;
}

int trackCenter(int x, int y) { // row == y and column == x
	if (y >= 19 && y <= 30 && x >= 19 && x <= 30) {
		return 1;
	}
	else {
		return 0;
	}
}

void printGraphicFloor(const int b[][WIDTH], int center) {
	// control row
	for (size_t row = 0; row < HEIGHT; ++row) {
		// control column
		for (size_t column = 0; column < WIDTH; ++column) {
			if (b[row][column] == 1) {
				printf("%s", "*");
			}
			else if (center) {
				if (((column == 19 || column == 30) && row >= 19 && row <= 30) || b[row][column] == 1) {
					printf("%s", "*"); 
				}
				else if ((row == 19 || row == 30) && column >= 19 &&  column<= 30) {
					printf("%s", "*");
				}
				else {
					printf("%s", " ");
				}
			}
			else if (b[row][column] == 0) {
				printf("%s", " ");
			} 
		}
		puts("");
	}
}
