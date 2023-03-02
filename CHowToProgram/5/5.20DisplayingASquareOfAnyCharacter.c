//theBitRiddler
//10-1-2022
//5:22pm
//Displaying a Square of any Character
#include <stdio.h>

int fillCharacter(int ,char );

int main(void){
	puts("Enter any character to create a square with");
	char y = ' ';//begin to declare characters first
	scanf("%c",&y);
	puts("Enter any number to create a size of a square");
	int x = 0;
	scanf("%d",&x);
	fillCharacter(x,y);
}

int fillCharacter(int x,char y){
	for(int row = 1;row <= x;row++){
		for(int col = 1;col <= x;col++){
			printf("%c",y);//return stops a program
		}
		puts("");
	}
}
