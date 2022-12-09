#include <stdio.h>
int main(void){
	int nine = 9;
	for(int row = 1;row <= 9;row+=2){
		for(int blank = nine;blank >= 1;blank-=2){
			printf("%s"," ");	
		}
		for(int ast = 1;ast <= row;ast++){
			printf("%s","*");
		}
		puts("");
		nine -= 2;
	}
	int three = 3;
	for(int row = 1;row <= 7;row+=2){
		for(int blank = 1;blank <= three;blank+=2){
			printf("%s"," ");
		}
		for(int ast = 7;ast >= row;ast--){
			printf("%s","*");
		}
		puts("");
		three += 2;
	}
}
