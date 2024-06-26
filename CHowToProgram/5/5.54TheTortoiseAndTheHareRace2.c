//theBitRiddler
//11/22/2022
//8:57pm
//The Tortoise and the Hare Race
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int start(void);
void end(int, int);
int hare(void);
int tortoise(void);
enum Status {
	CONTINUE, STOP
};

int main(void){
	srand(time(NULL));
	enum Status RaceStatus = CONTINUE;
	int T = 0,H = 0;//T for Tortoise and H for Hare
	puts("The Hare and The Tortoise Race\nH for Hare \nT for Tortoise");
	start();
	while(RaceStatus == CONTINUE){
		int line = 1;
		int t = tortoise();
		//printf("tortoise: %d ",t);
		
		T += t;
		int h = hare();
		//printf("hare: %d\n",h);
		H += h;
		system("cls");
//		puts("The Hare and The Tortoise Race\nH for Hare \nT for Tortoise");
		if(H > 70){
			H = 70;
		}
		if(T > 70){
			T = 70;
		}
		while(line <= 70){//One line incident
			if(T < 1){
				T = 1;
			}
			if(H < 1){
				H = 1;
			}
		
			if(line != H && line < H){//line before H
				if(line != T){
					printf("%s","_");
				}
				if(line == T){
					printf("%s","T");
				}
			}
		//	printf("%s","_");
			if(line == H){//The H
				if(H == T){
					if(H >= 70 && T >= 70){
						printf("%s"," ");
					}
					else{
						printf("%s","OUCH!");
					}
				}
				else{
					printf("%s","H");
				}	
			}
			
			if(line > H){//line after H
				if(line != T){
					printf("%s","_");
				}
				if(line == T){
					printf("%s","T");
				}
			}
			line++;	
		}
		
		printf("%s","\n");
		sleep(1);
		if(T >= 70 || H >= 70){
			if(T > 70){
				T = 70;
			}
			if(H > 70){
				H = 70;
			}
			end(H,T);
			RaceStatus = STOP;
		}
	}
}

int tortoise(void){
	int p = 1 + rand() % 10;//p = position
	switch(p){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			return 3;//fast plod:three squares forward
			break;
		case 6:
		case 7:
			return -6;//Slip:six squares backward
			break;
		case 8:
		case 9:
		case 10:
			return 1;//slow plod:one square forward
			break;	
	}
}

int hare(void){
	int p = 1 + rand() % 10;
	switch(p){
		case 1:
		case 2:
			return 0;//sleep;no move at all
			break;
		case 3:
		case 4:
			return 9;//Big hop;9 squares forward
			break;
		case 5:
			return -12;//Big sleep;12 squares backward
			break;
		case 6:
		case 7:
		case 8:
			return 1;//small hop:1 square forward
			break;
		case 9:
		case 10:
			return -2;//Small slip;2 squares backward
			break;	
	}
}

int start(void){
	int i = 1;
	while(i <= 6){
		if(i == 1){
			puts("ON YOUR MARK, GET SET");
		}
		if(i == 4){
			puts("BANG             !!!!");
			sleep(2);
			puts("AND THEY'RE OFF  !!!!");
		}
		if(i == 6){
			system("cls");
		}
		sleep(1);
		i++;
	}
}

void end(int H,int T){
	if(H == T && H == 70 && T == 70){
		int i = 1 + rand() % 2;
		switch(i){
			case 2:
				printf("%s","Turtle,the underdog won!");
				break;
			case 1:
				printf("%s","It's a tie\n");
				puts("Race Begins again");
				main();
				break;
		}	
	}
	else if(T == 70){
		printf("%s","TORTOISE WINS!!! YAY!!!");
	}
	else if(H == 70){
		printf("%s","Hare wins. Yuch.");
	}
}
