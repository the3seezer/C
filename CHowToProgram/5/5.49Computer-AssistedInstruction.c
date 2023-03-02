//theBitRiddler
//11/21/2022
//11:25AM
//Computer-Assisted Instruction
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cai();

int main(void){
	int ans = 0,total = cai();
	scanf("%d",&ans);
	while(ans != -1){
		if(ans == total){
			puts("Very Good!");
			total = cai();
			scanf("%d",&ans);
			if(ans == -1){
				break;
			}
		}
		if(ans != total){
			puts("No. Please try again.");
			scanf("%d",&ans);
		}
	}
}

int cai(void){
	srand(time(NULL));
	int a = 1 + rand() % 9;
	int b = 1 + rand() % 9;
	printf("How is %d times %d\n", a, b);
	return a * b;
}
