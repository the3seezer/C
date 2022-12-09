#include <stdio.h>
int main(void){
	int total = 0;
	int n = 0;
	int grade = 0;
	do{
		printf("%s%d or -1 to terminate\n","\nEnter the grade number: ",n + 1);
		scanf("%d",&grade);
		if(grade >= 1){
			total += grade;
		}
		n++;
	}while(grade != -1);
	printf("\nThe Average is :%.2f",(float)total / (n - 1));
}
