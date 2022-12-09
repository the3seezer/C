//theBitRiddler
//11/22/2022
//9:08am
//Computer-Assisted Instruction: Varying The Types Of Problems
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int cai(int);
long long int cai2(int);
long long int cai3(int);
long long int cai4(int);
int responce(void);
int chooseOp(void);

enum status { 
	CONTINUE, STOP
};

int main(void){
	char decide = ' ';
	enum status Pstatus = CONTINUE;
	long long int ans,total = 0;
	int count = 0,level = 1,pass = 0,fail = 0,op = 0;
	
	puts("Please select a level:1, 2, 3 or 4");
	scanf("%d",&level);
	printf("Level:%d\n",level);
	if(level == 1){//A switch can do the same thing
		op = chooseOp();
		total = cai(op);
	}
	if(level == 2){
		op = chooseOp();
		total = cai2(op);
	}
	if(level == 3){
		op = chooseOp();
		total = cai3(op);
	}
	if(level == 4){
		op = chooseOp();
		total = cai4(op);
	}
	
	scanf("%lld",&ans);
	while(Pstatus != STOP){
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
				total = cai(op);
			}
			if(level == 2){
				total = cai2(op);
			}
			if(level == 3){
				total = cai3(op);
			}
			if(level == 4){
				total = cai4(op);
			}
			
			scanf("%lld",&ans);
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
					//Pstatus = STOP;
					break;
				}
			}
			
			scanf("%lld",&ans);
		}	
	}
	
	puts("\nPlease let the other student try or take another level...\n\n");
	puts("Enter y to continue or n to stop");
	decide = getchar();
	scanf("%c",&decide);
	if(decide == 'y'){
		main();
	}
	else if(decide == 'n'){
		Pstatus == STOP;
	}
}

long long int cai(int op){
	srand(time(NULL));
	int a = 1 + rand() % 9;
	int b = 1 + rand() % 9;
	//int op = chooseOp();
	if(op == 1){//Your can turn it into a switch(the if else conditions
		printf("How is %d plus %d\n", a, b);
		return a + b;
	}
	if(op == 2){
		printf("How is %d minus %d\n", a, b);
		return a - b;
	}
	if(op == 3){
		printf("How is %d times %d\n", a, b);
		return a * b;
	}
	if(op == 4){
		srand(time(NULL));
		int opert = 1 + rand() % 3;
		switch(opert){
			case 1:
				printf("How is %d plus %d\n", a, b);
				return a + b;
				//break;
			case 2:
				printf("How is %d minus %d\n", a, b);
				return a - b;
				//break;
			case 3:
				printf("How is %d times %d\n", a, b);
				return a * b;
				//break;
		}
	}
}

long long int cai2(int op){
	srand(time(NULL));
	int a = 1 + rand() % 99;
	int b = 1 + rand() % 99;
	
	if(op == 1){//Your can turn it into a switch(the if else conditions
		printf("How is %d plus %d\n", a, b);
		return a + b;
	}
	if(op == 2){
		printf("How is %d minus %d\n", a, b);
		return a - b;
	}
	if(op == 3){
		printf("How is %d times %d\n", a, b);
		return a * b;
	}
	if(op == 4){
		srand(time(NULL));
		int opert = 1 + rand() % 3;
		switch(opert){
			case 1:
				printf("How is %d plus %d\n", a, b);
				return a + b;
				//break;
			case 2:
				printf("How is %d minus %d\n", a, b);
				return a - b;
				//break;
			case 3:
				printf("How is %d times %d\n", a, b);
				return a * b;
				//break;
		}
	}
}

long long int cai3(int op){
	srand(time(NULL));
	int a = 1 + rand() % 999;
	int b = 1 + rand() % 999;
	
	if(op == 1){//Your can turn it into a switch(the if else conditions
		printf("How is %d plus %d\n", a, b);
		return a + b;
	}
	if(op == 2){
		printf("How is %d minus %d\n", a, b);
		return a - b;
	}
	if(op == 3){
		printf("How is %d times %d\n", a, b);
		return a * b;
	}
	if(op == 4){
		srand(time(NULL));
		int opert = 1 + rand() % 3;
		switch(opert){
			case 1:
				printf("How is %d plus %d\n", a, b);
				return a + b;
				//break;
			case 2:
				printf("How is %d minus %d\n", a, b);
				return a - b;
				//break;
			case 3:
				printf("How is %d times %d\n", a, b);
				return a * b;
				//break;
		}
	}
}

long long int cai4(int op){
	srand(time(NULL));
	int a = 1 + rand() % 9999;
	int b = 1 + rand() % 9999;
	
	if(op == 1){//Your can turn it into a switch(the if else conditions
		printf("How is %d plus %d\n", a, b);
		return a + b;
	}
	if(op == 2){
		printf("How is %d minus %d\n", a, b);
		return a - b;
	}
	if(op == 3){
		printf("How is %d times %d\n", a, b);
		return a * b;
	}
	if(op == 4){
		srand(time(NULL));
		int opert = 1 + rand() % 3;
		switch(opert){
			case 1:
				printf("How is %d plus %d\n", a, b);
				return a + b;
				//break;
			case 2:
				printf("How is %d minus %d\n", a, b);
				return a - b;
				//break;
			case 3:
				printf("How is %d times %d\n", a, b);
				return a * b;
				//break;
		}
	}
}

int responce(void){
	srand(time(NULL));
	return 1 + rand() % 4;
}

int chooseOp(void){
	puts("Choose an operator: 1 == +, 2 == -, 3 == *, 4 Randomizing all");
	int opr = 0;
	scanf("%d",&opr);
	return opr;
}


