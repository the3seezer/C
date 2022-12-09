#include <stdio.h>
int main(void){
	int sum = 0;
	for(int odd = 1;odd <= 15;odd += 2){
		sum += odd;
	}
	printf("SUM:%d\n",sum);
}
