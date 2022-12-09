#include <stdio.h>
#include <stdlib.h>

//randomising
 
int main(void){
	int seed = 0;\
	printf("%s","Enter seed   ");
	scanf("%d",&seed);
	srand(seed);
	
	for(int i = 1;i <= 10;i++){
		printf("%d\t",1 + rand() % 6);
	}
}
