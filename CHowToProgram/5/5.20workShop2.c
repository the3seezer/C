#include <stdio.h>

int character(int,char);

int main(void){
	puts("Enter a character and a number to specify size to build a square");
	char fill = ' ';
	scanf("%c",&fill);
	int size = 0;
	scanf("%d",&size);
	character(size,fill);
}

int character(int v,char x){
	for(int i = 1;i <= v;i++){
		for(int j = 1;j <= v;j++){
			printf("%c",x);
		}
		puts("");
	}
}
