#include <stdio.h>
int main(void){
	int one = 1;
	for(int row = 1;row <= 19;row+=2){
		for(int blank = 19;blank >= one;blank-=2){
			printf("%s"," ");
		}
		for(int ast = 1;ast <= row;ast++){
			printf("%s","*");
		}
		puts("");
		one+=2;
	}
	int three = 3;
	one = 1;//or variable 'row' can be used
	for(int row = 1;row <= 17;row+=2){
		for(int blank = 1;blank <= three;blank+=2){
			printf("%s"," ");
		}
		for(int ast = 17;ast >= one;ast--){
			printf("%s","*");
		}
		puts("");
		three+=2;
		one+=2;
	}
}
