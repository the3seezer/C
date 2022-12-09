//theBitRiddler
//11-14-2022
//5:18pm
//Recursive
#include <stdio.h>

int print(int);

int main(void){
	puts("Enter a number to find the results");
	int num = 0;
	scanf("%d",&num);
	print(num);
}

int print(int n){
	if(n < 0){
		return 0;
	}
	printf("%d ", n + print(n - 1));
	n--;
	return n;
}
