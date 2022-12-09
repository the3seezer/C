#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//randomising without entering the seed everytime

int main(void){
	srand(time(NULL));
	for(int i = 1;i <= 10;i++){
		printf("%d\t",1 + rand() % 6);
	}
}
