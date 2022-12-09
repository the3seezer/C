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
		if(grade == 'b' || grade == 'B'){
			bCount++;
		}
		if(grade == 'c' || grade == 'C'){
			cCount++;
		}
		if(grade == 'd' || grade == 'D'){
			dCount++;
		}
		if(grade == 'f' || grade == 'F'){
			fCount++;
		}
		if(grade == '\n' || grade == '\t' || grade == ' '){
			
		}
		if(!(grade == 'a' || grade == 'A' || grade == 'b' || grade == 'B' || grade == 'c' || grade == 'C' || grade == 'd' || grade == 'D' || grade == 'f' || grade == 'F' || grade == '\n' || grade == '\t' || grade == ' ')){
			puts("You Entered a wrong character");
			puts("Enter again");
		}
	}
	printf("there are %d A's ,%d B's ,%d C's,%d D's and %d F's",aCount,bCount,cCount,dCount,fCount);
}
