//theBitRiddler
//9-30-2022
//3:07pm
//Multiples
#include <stdio.h>

int isMultiple(int ,int );

int main(void){
	puts("Enter 'a' and 'b' to determine whether 'b' is a multiple of 'a' or Enter -1 to end");
	int a = 0;
	scanf("%d",&a);
	int b = 0;
	while(a != -1){
		scanf("%d",&b);
		printf("%d\n",isMultiple(a,b));
		puts("Enter 'a' and 'b' to determine whether 'b' is a multiple of 'a' or Enter -1 to end");
		a = 0;
		scanf("%d",&a);
	}
}

int isMultiple(int x,int y){
	if(x % y == 0){
		return 1;
	}
	else{
		return 0;
	}
}
