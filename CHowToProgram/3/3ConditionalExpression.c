#include <stdio.h>
int main(){
	int grade = 0;
	puts("Enter your grade");
	scanf("%d",&grade);
	//Conditional Expression
	//conditional operator(?:) C's only tenary operator-it takes three operands
	// a conditional operator + its three operands = CONDITIONAL EXPRESSION
	//very similar to if...else but can work as expressions and arguments to functions;where if...else cannot
	puts((grade >= 60) ? "Passed!" : "Failed!");//as an argument to a function
	grade >= 60 ? printf("%s","Passed") : puts("Failed");//as an if...else statement
	//use expressions of the same type for the second and third operands of the conditional operator(?:) to avoid subtle errors	
}
