#include <stdio.h>
int main(void){
	int x = 1;
	for(;x <= 10;x++){
		if(x != 5){//continue statement
			printf("%d\t",x);
		}
	}
}
