#include <stdio.h>
int main(void){
	int aCount = 0;
	int bCount = 0;
	int cCount = 0;
	int dCount = 0;
	int fCount = 0;
	
	//credits
	printf("%s","CREDITS:A = 5,B = 4,C = 3,D = 2 & F = 1\n");
	int a = 5; int A = 5;
	int b = 4; int B = 4;
	int c = 3; int C = 3;
	int d = 2; int D = 2;
	int f = 1; int F = 1;
	
	int grades = 0;
	printf("%s","Enter grades :\n");
	while((grades = getchar()) != EOF){
		switch(grades){
			case 'A':
			case 'a':
				aCount++;
				break;
			case 'B':
			case 'b':
				bCount++;
				break;
			case 'C':
			case 'c':
				cCount++;
				break;
			case 'D':
			case 'd':
				dCount++;
				break;
			case 'F':
			case 'f':
				fCount++;
				break;
			case '\n':
			case '\t':
			case ' ':
				break;
			default:
				puts("Entered a wrong character");
				puts("Enter a new character: ");
		}
	}
	int total_credit = a + b + c + d + f;printf("total credit %d\n",total_credit);
	int ct_cr_summation = aCount * a + bCount * b + cCount * c + dCount * d + fCount * f;printf("credit count summation %d\n",ct_cr_summation);
	printf("GPA: %f",(float)ct_cr_summation  /  total_credit);
	
}
