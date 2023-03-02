//theBitRiddler
//11/20/2022
//7:15am
//Recursive Palindrome
#include <stdio.h>

int reverse(int ,int);

int main(void){
	int num = 0;
	puts("Enter a number to check if its a palindrome");
	scanf("%d",&num);
	if(num == reverse(num,0)){
		printf("Its a palindrome");
	}
	else{
		printf("Its not a palindrome");
	}	
}

int reverse(int num1,int num2){
	if(num1 == 0){
		return num2;
	}
	num2 *= 10;
	num2 += (num1 % 10);
	num1 /= 10;
	reverse(num1,num2);
}
