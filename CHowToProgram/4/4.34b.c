#include <stdio.h>
int main(void){
	int total = 0;
	int n = 0;
	int grades = 0;
	puts("Enter the Grades, -1 to end\n");
	scanf("%d",&grades);
	while(grades != -1){
		total += grades;
		n++;
		puts("Enter the Grades, -1 to end\n");
		scanf("%d",&grades);
	}
	printf("The Average: %.2f",(float)total / n);
}
