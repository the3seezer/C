//theBitRiddler
//10-14-2022
//5:22pm
/*
Integer lenth
*/
#include <stdio.h>

int intlen(int);

int main(void){
	int y = 0;
	puts("Enter any integer value to determine its lenth");
	scanf("%d",&y);
	printf("The lenth of an integer:%d",intlen(y));
}

int intlen(int x){
	int i = 0;
	while(x){
		x /= 10;
		i++;
	}
	return i;
}
