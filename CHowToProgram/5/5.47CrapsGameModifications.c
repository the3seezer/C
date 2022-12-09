//theBitRiddler
//11-13-2022
//6:34am
//Game of Craps Modifications
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
	int sum = 0;//rollDice();
	int myPoint = 0;
	
	//mofications
	int bankBalance = 1000;
	int wager = 0;
	puts("Enter a wager");
	scanf("%d",&wager);
	if(wager > bankBalance){
		puts("Your wager is larger than your bank balance\n");
		main();
	}
	while(wager <= bankBalance && bankBalance > 0){
		sum = rollDice();
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
				bankBalance += wager;
				printf("Your balance:%d\n",bankBalance);
				if(bankBalance >= 1500){
					puts("You're up big. Now's the time to cash in your chips!");
				}
				
				puts("Enter 's' to stop and 'c' or any to continue");
				char decision = getchar();
				scanf("%c",&decision);
				if(decision == 's'){
					break;
				}
				
				puts("Enter a wager");
				scanf("%d",&wager);
				while(wager > bankBalance){
					puts("Your wager is larger than your bank balance");
					puts("Enter a wager");
					scanf("%d",&wager);
				}
				
			}
			else{
				printf("%s\n","Player loses");
				bankBalance -= wager;
				printf("Your balance:%d\n",bankBalance);
				
				if(bankBalance <= 0){
					puts("Sorry you busted!");
					break;
				}
				
				if(bankBalance < 500){
					puts("Aw cmon,take a chance!");
				}
				else if(bankBalance <= 200){
					printf("%s\n","Oh, you're going for broke, huh?");
				}
				
				puts("Enter 's' to stop and 'c' or any to continue");
				char decision = getchar();
				scanf("%c",&decision);
				if(decision == 's'){
					break;
				}
				
				puts("Enter a wager");
				scanf("%d",&wager);
				while(wager > bankBalance){
					puts("Your wager is larger than your bank balance");
					puts("Enter a wager");
					scanf("%d",&wager);
				}
			}
	}
}

int rollDice(void){
	//srand(time(NULL));//Putting this in this Function it will have a constant value
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	printf("Played rolled %d and %d == %d\n",die1,die2,die1 + die2);
	return die1 + die2;
}
