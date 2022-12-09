//theBitRiddler
//10-15-2022
//10:45am
/*
toQualityPoints()
a program that gives 4 at 90-100,3 at 80-89,2 at 70-79,1 at 60-69
and 0 below 60 */
#include <stdio.h>

int toQualityPoints(int);

int main(void){
	int grade = 0;
	puts("Enter a grade from 1 to 100");
	scanf("%d",&grade);
	printf("Quality Grade:%d",toQualityPoints(grade));
}

int toQualityPoints(int x){
	if(x >= 90 && x <= 100){
		return 4;
	}
	else if(x >= 80 && x <= 89){
		return 3;
	}
	else if(x >= 70 && x <= 79){
		return 2;
	}
	else if(x >= 60 && x <= 69){
		return 3;
	}
	else if(x < 60){
		return 0;
	}
	else{
		puts("You Entered a wrong grade");
	}
}


