//theBitRiddler
//10-6-2022
//2:49pm
//Timing
#include <stdio.h>
#include <time.h>
int main(void){
	for(int i = 1;i <= 1000000;i++);
	
	int ticks = clock();
	printf("%lf\n",(double) ticks / CLOCKS_PER_SEC);
}
