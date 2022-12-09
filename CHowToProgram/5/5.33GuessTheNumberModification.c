//theBitRiddler
//10-15-2022
//2:05pm
/*
Guess the number Modification*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myNumber(void);

enum status {CONTINUE, STOP}; 

int main(void){
	int guess = 0;
	puts("I have a number between 1 and 1000.Can you guess my number?\nPlease Enter your first guess\n");
	scanf("%d",&guess);
	enum status gameStatus = CONTINUE;
	int numb = myNumber();
	int count = 0;
	
	while(CONTINUE == gameStatus){
		if(numb == guess){
			if(count <= 10){
				puts("Either you know the secret or You got luck!");
			}
			else if(count == 10){
					puts("Aha!You know The secret!");
			}
			else if(count > 10){
				puts("You should be able to do better!\" Why should it take no more than 10 guess? \nWell, with each good guess the player should be able to eliminate half of the numbers.\n Now show why any number 1 to 1000 can be guessed in 10 or fewer tries");
			}	
			puts("Excellent! you guessed the number!\nWould you like to play again (n or y)?");
			int yn = getchar();	
			scanf("%c",&yn);//This prevents the puts output from repeating itself
			if(yn == 'y'){
				puts("I have a number between 1 and 1000.Can you guess my number?\nPlease Enter your guess\n");
				scanf("%d",&guess);
				numb = myNumber();
				count = 0;
			}
			else if(yn == 'n'){
				gameStatus = STOP;
			}
		}
		else if(guess > numb){
			count++;
			puts("Too High,Try again\n");
			scanf("%d",&guess);
			gameStatus = CONTINUE;	
		}
		else if(guess < numb){
			count++;
			puts("Too Low,Try again\n");
			scanf("%d",&guess);
			gameStatus = CONTINUE;
		}
	}
}

int myNumber(void){
	srand(time(NULL));
	int numb = 1 + rand() % 1000;
}
