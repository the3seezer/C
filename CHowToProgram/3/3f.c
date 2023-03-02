#include <stdio.h>
int main(){
	int total = 0;
	int counter = 0;
	
	puts("Enter the values");
	int grades = 0;
	scanf("%d",&grades);
	
	while(grades != -1){
		total = total + grades;
		
		counter = counter + 1;
		scanf("%d",&grades);
	}//end while
	
	if(counter != 0){
		int average = total / counter;
		printf("The average is %d",average);
	}//end if
	else{
		puts("There is no inputs");
	}//end else
}
