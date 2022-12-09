#include <stdio.h>
#include <stdlib.h>

//dice rolling program

int main(void){
	for(int x = 1;x <= 10;x++){
		printf("%d\t",1 + (rand() % 6));
	}
}
