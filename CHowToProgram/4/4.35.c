#include <stdio.h>
int main(void){
	int x = 1;
	for(;x <= 10;x++){
		if(!(x >= 5)){//break statement
			printf("%d\t",x);
		}
		else if(x == 5){
			puts("Break statement took over");
		}
	}
}
