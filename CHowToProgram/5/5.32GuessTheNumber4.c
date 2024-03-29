//theBitRiddler
//10-15-2022
//2:05pm
/*
Guess the number */
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
	
	while(CONTINUE == gameStatus){
		if(numb == guess){
			puts("Excellent! you guessed the number!\nWould you like to play again (n or y)?");
			int yn = getchar();//if I put a data type 'int' to yn;redeclare it.It brings out twice the output of puts() function
			scanf("%c",&yn);
			if(yn == 'y'){
				puts("I have a number between 1 and 1000.Can you guess my number?\nPlease Enter your guess\n");
				scanf("%d",&guess);
				numb = myNumber();
			}
			else if(yn == 'n'){
				gameStatus = STOP;
			}
		}
		else if(guess > numb){
			puts("Too High,Try again\n");
			scanf("%d",&guess);
			gameStatus = CONTINUE;	
		}
		else if(guess < numb){
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
