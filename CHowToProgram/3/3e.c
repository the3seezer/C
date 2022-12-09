#include <stdio.h>
int main(){
	//initilization phase	
	int total = 0;//initialize total grade to zero
	int counter = 1;//the next number of grade to be entered
	
	//prossessing phase
	while(counter <= 10){//loop for ten times
		printf("%s","Enter the grade: ");//prompting the user to enter grades
		int grade = 0;//initilizing the grades to zero
		scanf("%d",&grade);//iniputing grades
		total = total + grade;//adding grades to total
		counter = counter + 1;//increment counter
	}//end while
	
	
	float average = total / 10;//average
	printf("Class average is %f",average);//printing average
}//end function main
