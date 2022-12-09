//theBitRiddler
//10-1-2022
//7:48pm
//A wide range of shapes
#include <stdio.h>

int fillCharacter(int ,char );

int main(void){
	puts("Enter any character to create a square with");
	char y = ' ';//begin to declare characters first
	scanf("%c",&y);
	puts("Enter any number to create a size of square");
	int x = 0;
	scanf("%d",&x);
	puts("Enter a number of shapes");
	int shapes = 0;
	scanf("%d",&shapes);
	for(int i = 1;i <= shapes;i++){
		fillCharacter(x,y);
	}
}

int fillCharacter(int x,char y){
	for(int row = 1;row <= x;row++){
		for(int col = 1;col <= x;col++){
			printf("%c",y);//return stops a program
		}
		puts("");
	}
	puts("");
}

