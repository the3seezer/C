#include <stdio.h>
int main(){
	int total = 0;
	int counter = 0;
	
	puts("Enter the grades: -1 terminates/to end ");
	int grades = 0;
	scanf("%d",&grades);
	
	while(grades != -1){
		total = total + grades;
		counter = counter + 1;
		scanf("%d",&grades);
	}
	if(counter != 0){
		double average = (double) total / counter;//to avoid truncation(that's lost)using the unary CAST OPERATOR
		printf("The average is %.2f",average);
	}//NOTE (double) to create temporary floating-point copy of its operand,total;exiplicit conversion
	else{
		puts("There is no input!.");
	}//unary operator;it takes only one operand
}
