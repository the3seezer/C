//theBitriddler
//11/21/2022
//12:01pm
//Computer-Assisted Instruction: Reducing Student Fatigue
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cai(void);
int responce(void);

int main(void){
	int ans = 0,total = cai();
	scanf("%d",&ans);
	while(ans != -1){
		if(ans == total){
			int resp = responce();
			switch(resp){
				case 1:
					puts("Very good!\n");
					break;
				case 2:
					puts("Excellent!\n");
					break;
				case 3:
					puts("Nice work!\n");
					break;
				case 4:
					puts("Keep up the good work!\n");
					break;
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
					break;
				case 2:
					puts("Wrong. Try once more.\n");
					break;
				case 3:
					puts("Don't give up!\n");
					break;
				case 4:
					puts("No. Keep trying.\n");
					break;
			}
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

int responce(void){
	srand(time(NULL));
	return 1 + rand() % 4;
}
