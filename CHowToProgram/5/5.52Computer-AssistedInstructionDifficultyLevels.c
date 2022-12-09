//theBitRiddler
//11/21/2022
//5:28pm
//Computer-Assisted Instruction: Difficulty levels
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int cai(void);
long long int cai2(void);
long long int cai3(void);
long long int cai4(void);
int responce(void);

int main(void){
	long long int ans,total = 0;
	int count = 0,level = 1,pass = 0,fail = 0;
	
	puts("Please select a level:1, 2, 3 or 4");
	scanf("%d",&level);
	printf("Level:%d\n",level);
	if(level == 1){
		total = cai();
	}
	if(level == 2){
		total = cai2();
	}
	if(level == 3){
		total = cai3();
	}
	if(level == 4){
		total = cai4();
	}
	
	scanf("%lld",&ans);
	while(ans != -1){
		if(ans == total){
			pass++;
			int resp = responce();
			switch(resp){
				case 1:
					puts("Very good!\n");
					count++;
					break;
				case 2:
					puts("Excellent!\n");
					count++;
					break;
				case 3:
					puts("Nice work!\n");
					count++;
					break;
				case 4:
					puts("Keep up the good work!\n");
					count++;
					break;
			}
			
			if(count == 10){
				double ten = 10,hundred = 100,sevFiv = 75;
				double percent = (double) pass / ten;
				if((percent * hundred) >= sevFiv){
					puts("Congratulations, You are ready to go to next level!");
					break;
				}
			}
			
			if(level == 1){
				total = cai();
			}
			if(level == 2){
				total = cai2();
			}
			if(level == 3){
				total = cai3();
			}
			if(level == 4){
				total = cai4();
			}
			
			scanf("%lld",&ans);
			if(ans == -1){
				break;
			}
		}
		
		if(ans != total){
			//fail++;
			int resp = responce();
			switch(resp){
				case 1:
					puts("No. Please try again.\n");
					count++;
					break;
				case 2:
					puts("Wrong. Try once more.\n");
					count++;
					break;
				case 3:
					puts("Don't give up!\n");
					count++;
					break;
				case 4:
					puts("No. Keep trying.\n");
					count++;
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
					break;
				}
			}
			
			scanf("%lld",&ans);
		}	
	}
	
	if(ans != -1){
		puts("\nPlease let the other student try or take another level...\n\n");
		main();
	}
}

long long int cai(void){
	srand(time(NULL));
	int a = 1 + rand() % 9;
	int b = 1 + rand() % 9;
	printf("How is %d times %d\n", a, b);
	return a * b;
}

long long int cai2(void){
	srand(time(NULL));
	int a = 1 + rand() % 99;
	int b = 1 + rand() % 99;
	printf("How is %d times %d\n", a, b);
	return a * b;
}

long long int cai3(void){
	srand(time(NULL));
	int a = 1 + rand() % 999;
	int b = 1 + rand() % 999;
	printf("How is %d times %d\n", a, b);
	return a * b;
}

long long int cai4(void){
	srand(time(NULL));
	int a = 1 + rand() % 9999;
	int b = 1 + rand() % 9999;
	printf("How is %d times %d\n", a, b);
	return a * b;
}

int responce(void){
	srand(time(NULL));
	return 1 + rand() % 4;
}
