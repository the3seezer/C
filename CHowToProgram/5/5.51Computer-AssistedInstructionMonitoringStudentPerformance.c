//theBitRiddler
//11/21/2022
//4:46pm
//Computer-Assisted Instruction:Monitoring Student Performance
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cai(void);
int responce(void);

int main(void){
	int ans = 0,total = cai(),count = 0,fail = 0,pass = 0;
	scanf("%d",&ans);
	while(ans != -1){
		if(ans == total){
			int resp = responce();
			switch(resp){
				case 1:
					puts("Very good!\n");
					count++;
					pass++;
					break;
				case 2:
					puts("Excellent!\n");
					count++;
					pass++;
					break;
				case 3:
					puts("Nice work!\n");
					count++;
					pass++;
					break;
				case 4:
					puts("Keep up the good work!\n");
					count++;
					pass++;
					break;
			}
			
			if(count == 10){
				double ten = 10,hundred = 100,sevFiv = 75;
				double percent = (double) pass / ten;
				if((percent * hundred) >= sevFiv){
					puts("Congratulations, You are ready to go to next level!");
					count = 0;
					break;
				}
			}
			
			total = cai();
			scanf("%d",&ans);
			if(ans == -1){
				break;
			}
		}
		
		
		if(ans != total){
			int resp = responce();
			switch(resp){
				case 1:
					puts("No. Please try again.\n");
					count++;
					//fail++;
					break;
				case 2:
					puts("Wrong. Try once more.\n");
					count++;
					//fail++;
					break;
				case 3:
					puts("Don't give up!\n");
					count++;
					//fail++;
					break;
				case 4:
					puts("No. Keep trying.\n");
					count++;
					//fail++;
					break;
			}
			
			if(count == 10){
				if(pass == 0){
					pass = 1;
				}
				double ten = 10,hundred = 100,sevFiv = 75;
				double percent = (double) pass / ten;
				if((percent * hundred) < sevFiv){
					puts("Please ask your teacher for extra help.");
					count = 0;
					break;
				}
			}
			
			scanf("%d",&ans);
		}	
	}
	
	if(ans != -1){
		puts("\nPlease let the other student try...\n\n");
		main();
	}
}

int cai(void){
	srand(time(NULL));
	int a = 1 + rand() % 9;
	int b = 1 + rand() % 9;
	printf("How is %d times %d\n", a, b);
	return a * b;
}

int responce(void){
	srand(time(NULL));
	return 1 + rand() % 4;
}
