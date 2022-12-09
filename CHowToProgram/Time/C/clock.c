//theBitRiddler
//10-7-2022
//8:21am
/*
clock(void);
CLOCKS_PER_SEC
*/
#include <stdio.h>
#include <conio.h>
#include <time.h>

void display(void){
	printf("Time elapsed:%f\n", (float) clock() / CLOCKS_PER_SEC);
}
int main(void){
	getch();
	display();
	
	getch();
	display();
}
