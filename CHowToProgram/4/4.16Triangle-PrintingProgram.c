#include <stdio.h>
int main(void){
	for(int i = 1;i <= 4;i++){
		if(i == 1){
			puts("(A)");
			for(int row = 1;row <= 10;row++){
				for(int column = 1;column <= row;column++){
					printf("%s","*");
				}
				puts("");
			}
		}
		if(i == 2){
			puts("(B)");
			for(int row = 1;row <= 10;row++){
				for(int column = 10;column >= row;column--){
					printf("%s","*");
				}
				puts("");
			}
		}
		if(i == 3){
			puts("(C)");
			for(int row = 1;row <= 10;row++){
				for(int blank = 1;blank <= row;blank++){
					if(blank == 1){
						continue;
					}
					printf("%s"," ");
				}
				for(int aster = 10;aster >= row;aster--){
					printf("%s","*");
				}
				puts("");
			}
		}
		if(i == 4){
			puts("(D)");
			for(int row = 1;row <= 10;row++){
				for(int blank = 10;blank >= row;blank--){
					if(blank == 10){
						continue;
					}
					printf("%s"," ");
				}
				for(int aster = 1;aster <= row;aster++){
					printf("%s","*");
				}
				puts("");
			}
		}
	}
}
