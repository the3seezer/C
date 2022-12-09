#include <stdio.h>
int main(void){
	int N = 1;
	int counter = 1;
	printf_s("%s","N\t10*N\t100*N\t1000*N\n\n");
	while(counter <= 10){
		printf_s("%d\t%d\t%d\t%d\n",N,10 * N,100 * N,1000 * N);
		N++;
		counter++;
	}
}
