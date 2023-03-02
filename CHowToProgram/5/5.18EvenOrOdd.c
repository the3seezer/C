//theBitRiddler
//10-1-2022
//3:47pm
//Even or Odd
#include <stdio.h>

int isEven(int);

int main(void){
	int a = 0;
	puts("Enter any number to determine whether its even or odd and -1 to end");
	scanf("%d",&a);
	while(a != -1){
		printf("%d\n",isEven(a));
		puts("Enter any number to determine whether its even or odd and -1 to end");
		scanf("%d",&a);
	}
}

int isEven(int x){
	return !(x % 2) ? 1 : 0 ;
}
