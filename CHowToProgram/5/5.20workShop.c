#include <stdio.h>

int character(char);

int main(void){
	char fill = ' ';
	scanf("%c",&fill);
	character(fill);
}

int character(char x){
	return printf("%c",x);
}
