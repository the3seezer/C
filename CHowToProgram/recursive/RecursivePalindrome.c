//theBitRiddler
//11/20/2022
//6:50am
//Recursive Palindrome check
#include <stdio.h>

int palindrome(int);
int reverse(int);

int main(void){
	puts("Enter a number to find whether its a palindrome or not");
	int num = 0;
	scanf("%d",&num);
	palindrome(num);
}

int palindrome(int m){
	if(reverse(m) == m){
		printf("%s\n","This is a palindrome");
	}
	else{
		printf("%s\n","This is not a palindrome");
	}
}

int reverse(int n){
	static int sum = 0;
	
	if(n != 0){
		int rem = n % 10;
		sum = sum * 10 + rem;
		reverse(n / 10);  
	}
	return sum;
}
