#include <stdio.h>
int main(void){
	int grade = 0;
	
	int aCount = 0;
	int bCount = 0;
	int cCount = 0;
	int dCount = 0;
	int fCount = 0;
	puts("Enter grades a,b,c,d,f or ctrl + z to end");
	while((grade = getchar()) != EOF){
		if(grade == 'a' || grade == 'A'){
			aCount++;
		}
		else if(grade == 'b' || grade == 'B'){
			bCount++;
		}
		else if(grade == 'c' || grade == 'C'){
			cCount++;
		}
		else if(grade == 'd' || grade == 'D'){
			dCount++;
		}
		else if(grade == 'f' || grade == 'F'){
			fCount++;
		}
		else if(grade == '\n' || grade == '\t' || grade == ' '){
			
		}
		else{
			puts("You Entered a wrong character");
			puts("Enter again");
		}
	}
	printf("there are %d A's ,%d B's ,%d C's,%d D's and %d F's",aCount,bCount,cCount,dCount,fCount);
}
