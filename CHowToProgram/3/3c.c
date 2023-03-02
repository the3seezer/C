#include <stdio.h>
int main(){
	int grade = 0;
	puts("Enter your grade");
	scanf("%d",&grade);
	puts((grade >= 90) ? "A" : (grade >= 80)?"B":(grade >= 70)?"C":(grade >= 60)?"D":"F");
}
