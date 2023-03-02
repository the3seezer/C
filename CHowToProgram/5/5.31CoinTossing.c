//theBitRiddler
//10-15-2022
//11:22am
/* (Coin Tossing) Write a program that simulates coin tossing. For each toss, display Heads or Tails. Let the program toss the coin 100 times, and count the number
of heads and tails. Display the results. The program should call a function flip that
takes no arguments and returns 0 for tails and 1 for heads. If the program realistically
236 Chapter 5 Functions
simulates the coin tossing, then each side of the coin should appear approximately
half the time for a total of approximately 50 heads and 50 tails.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int flip(void);

int main(void){
	flip();
}

int flip(void){
	int heads = 0;
	int tails = 0;
	srand(time(NULL));
	for(int i = 1;i <= 100;i++){
		int f = 0 + rand() % 2;
		printf("%d\n",f);
		switch(f){
			case 1:
				heads++;
				break;
			case 0:
				tails++;
				break;
		}
	}
	printf("Heads:%d\nTails:%d\n",heads,tails);
}
