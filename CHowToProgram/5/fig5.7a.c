#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status {CONTINUE , WON , LOST };
int rollDice(void);

int main(void){
	srand(time(NULL));
	
	enum Status gameStatus = CONTINUE;
	int myPoint = 0;
	int sum = rollDice();
	
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
			printf("Your points: %d\n",myPoint);
			break;
	}
	
	while(CONTINUE == gameStatus){
		sum = rollDice();
		if(sum == myPoint){
			gameStatus = WON;
		}
		else if(7 == sum){
			gameStatus = LOST;
		}
	}
	
	if(gameStatus == WON){
		printf("Player wins\n");
	}
	else if(gameStatus == LOST){
		printf("Player loses\n");
	}
}

int rollDice(void){
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	printf("You rolled:  %d + %d = %d\n",die1,die2,die1 + die2);
	return die1 + die2;
}
