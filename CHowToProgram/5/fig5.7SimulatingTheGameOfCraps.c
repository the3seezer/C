//Dice game of craps

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { CONTINUE , WON ,LOST };
int rollDice(void);

int main(void){
	srand(time(NULL));
	
	int myPoints = 0;
	enum Status gameStatus = CONTINUE;
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
			myPoints = sum;
			printf("You're points %d\n",myPoints);
			break;
	}
	
	while(CONTINUE == gameStatus){
		sum = rollDice();
		if(myPoints == sum){
			gameStatus = WON;
		}
		else if(7 == sum){
			gameStatus = LOST;
		}
	}
	
	if(WON == gameStatus){
		printf("%s\n","You won!");
	}
	else if(LOST == gameStatus){
		printf("%s\n","You lost!");
	}
	
}

int rollDice(void){
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	printf("You rolled %d + %d = %d\n",die1,die2,die1 + die2);
	return die1 + die2;
}
