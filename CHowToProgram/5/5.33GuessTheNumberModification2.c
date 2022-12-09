#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status {CONTINUE , END
};

int guess (void);

int main(void){
	enum Status gameStatus = CONTINUE;
	printf("%s\n%s\n%s\n","I have a number between 1 and 1000.","Can you guess my number?","Please type your first guess.");
	
	int sum = guess();
	int match = 0;
	int count = 1;
	char ans = 0;
	scanf("%d",&match);
	while(CONTINUE == gameStatus){
		if (match < sum){
			puts("Too low. Try again.");
			gameStatus = CONTINUE; 
			++count;
			scanf("%d",&match);
		}
		else if(match > sum){
			puts("Too high. Try again.");
			gameStatus = CONTINUE;
			++count;
			scanf("%d",&match);
		}
		else if(match == sum){
			printf("%s\n%s\n","Excellent! You guessed the number!","Would you like to play again (y or n)?");
			ans = getchar();
			scanf("%c",&ans);
			
			switch (ans){
				case 'y':
					gameStatus = CONTINUE;
					printf("%s\n%s\n%s\n","I have a number between 1 and 1000.","Can you guess my number?","Please type your first guess.");
					sum = guess();
					count = 0;
					scanf("%d",&match);
					break;
					
				case 'n':
					gameStatus = END;
					break;
			}
		}
	}
	
	if (count == 10){
		puts("Aha! You know the secret!");
	}
	else if ( count <= 10){
		puts("Either you know the secret or you got lucky!");
	}
	else if (count > 10){
		puts("You should be able to do better.");
	}
}

int guess (void){
	srand(time(NULL));
	return 1 + rand()% 1000;
}
