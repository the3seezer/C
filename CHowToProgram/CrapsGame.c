//theBitRiddler
//11-13-2022
//6:34am
//Game of Craps Modification
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status {
	WON, LOSE, CONTINUE
};
int rollDice(void);

int main(void){
	srand(time(NULL));
	
	enum Status gameStatus = CONTINUE;
	int sum = rollDice();
	int myPoint = 0;
	
	switch(sum){
		case 7:
		case 11:
			gameStatus = WON;
			break;
		case 2:
		case 3:
		case 12:
			gameStatus = LOSE;
			break;
		default:
			gameStatus = CONTINUE;
			myPoint = sum;
			printf("Point is %d\n",sum);
			break;
	}
	
	while(CONTINUE == gameStatus){
		sum = rollDice();
		if(myPoint == sum){
			gameStatus = WON;
		}
		if(7 == sum){
			gameStatus = LOSE;
		}
	}
	
	if(WON == gameStatus){
		printf("%s\n","Player wins");
	}
	else{
		printf("%s\n","Player loses");
	}
}

int rollDice(void){
	//srand(time(NULL));//Putting this in this Function it will have a constant value
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	printf("Played rolled %d and %d == %d\n",die1,die2,die1 + die2);
	return die1 + die2;
}
