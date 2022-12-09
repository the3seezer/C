//theBitRiddler
//9-25-2022
//5:07
//Randomising n in ranges
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
	srand(time(NULL));
	puts("a");
	for(int n = 1;n <= 20;n++){
		printf("%d\t",1 + rand() % 2);
	}
	puts("\nb");
	for(int n = 1;n <= 20;n++){
		printf("%d\t",1 + rand() % 100);
	}
	puts("\nc");
	for(int n = 1;n <= 20;n++){
		printf("%d\t",0 + rand() % 9);
	}
	puts("\nd");
	for(int n = 1;n <= 40;n++){
		printf("%d\t",1000 + rand() % 1112);
	}
	puts("\ne");
	for(int n = 1;n <= 20;n++){
		printf("%d\t",-1 + rand() % 1);
	}
	puts("\nf");
	for(int n = 1;n <= 20;n++){
		printf("%d\t",-3 + rand() % 11);
	}
	puts("");
}
