// theBitRiddler
// 1/1/2023
// 5:11 PM
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 43

enum Status {
	WON, LOST, CONTINUE
};

int craps(void);
int roll(void);

int main(void) {
	srand(time(NULL));
	int chance[SIZE] = {0};
	int total_wins = 0; // get total wins and total loses
	clock_t start,end;
	
	start = clock();
	for (int i = 0; i < 1000000; ++i) {
		printf("game: %d\n", i + 1);
		++chance[craps()];
	}
	end = clock();
	
	double length = (double) (end - start) / CLOCKS_PER_SEC;
	for (int rating = 1; rating <= 42; ++rating) {
		if (rating <= 21) {
			total_wins += chance[rating];
			if (rating == 1) {
				puts("\n\n  Wins");
				printf("first roll (%d) == wins %d\n", rating, chance[rating]);
			}
			else if (rating == 2) {
				printf("second roll (%d) == wins %d\n", rating, chance[rating]);
			}
			else if (rating == 3) {
				printf("Third roll (%d) == wins %d\n", rating, chance[rating]);
			}
			else if (rating > 3 && rating < 20) {
				printf("%dth roll  == wins %d\n", rating, chance[rating]);
			}
			else if (rating == 20) {
				printf("Twentieth Roll %d == wins %d\n", rating, chance[rating]);
			}
			else if (rating == 21){
				printf("Rolls after the twentieth roll == wins %d\n", chance[rating]);	
			}
		}
		else {
			if (rating == 22) {
				puts("\n\n  Loses");
				printf("first roll (%d) == loses %d\n", rating - 21, chance[rating]);
			}
			else if (rating == 23) {
				printf("second roll (%d) == loses %d\n", rating - 21, chance[rating]);
			}
			else if (rating == 24) {
				printf("Third roll (%d) == loses %d\n", rating - 21, chance[rating]);
			}
			else if (rating > 24 && rating < 41) {
				printf("%dth roll  == loses %d\n", rating - 21, chance[rating]);
			}
			else if (rating == 41) {
				printf("Twentieth Roll %d == loses %d\n", rating - 21, chance[rating]);
			}
			else if (rating == 42){
				printf("Rolls after the twentieth == loses %d\n", chance[rating]);	
			}
		}
	}
	printf("\nwins %d\nloses %d\nLength:%fs\nAverage lenth of a game: %.10fs\n", total_wins, 1000000 - total_wins, length, length / 1000000); // 6.20(c) & 6.20(d)
	puts("Do the chances of winning improve with the length of the game?");	
}

int craps(void) {
	int myRolls = 0; // sum the number of rolls
	int sum = roll();
	++myRolls;
	enum Status gameStatus = CONTINUE;
	int myPoint = 0;
	
	switch(sum){
		case 7:
		case 11:
			gameStatus = WON;
			break;
		case 2:
		case 3:
		case 12:
			gameStatus = LOST;
			break;
		default:
			gameStatus = CONTINUE;
			myPoint = sum;
			printf("Your point is: %d\n", myPoint);
			break;
	}
	
	while (CONTINUE == gameStatus) {
		sum = roll();
		++myRolls;
		if (myPoint == sum) {
			gameStatus = WON;
		}
		else if (7 == sum) {
			gameStatus = LOST;
		}
	}
	
	if (gameStatus == WON) {
		puts("Player wins!");
		if (myRolls > 20) {
			myRolls = 21;
		}
		return myRolls;
	}
	else if (gameStatus == LOST){
		puts("Player loses");
		if (myRolls > 20) {
			myRolls = 21;
		}
		return 21 + myRolls;
	}
}

int roll(void) {
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	return die1 + die2;
}
