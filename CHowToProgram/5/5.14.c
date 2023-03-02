//theBitRiddler
//9-25-2022
//5:32pm
//Randomizing some specific integers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
	srand(time(NULL));
	puts("a");
	for(int i = 1;i <= 15;i++){//2,4,6,8,10
		int y = 2 + rand() % 10;
		y % 2 == 0 ? printf("%d ",y) : printf("%s",""); 
	}
	puts("\nb");
	for(int i = 1;i <= 100;i++){//3,5,7,9,11
		int y = 3 + rand() % 9;
		y % 2 ? printf("%d ",y) : printf("%s",""); 
	}
	puts("\nc");
	for(int i = 1;i <= 100;i++){//6,10,14,18,22
		int y = 6 + rand() % 20;
		y == 6 || (y - 6) % 4 == 0 ? printf("%d ",y) : printf("%s",""); 
	}
	puts("");
}
