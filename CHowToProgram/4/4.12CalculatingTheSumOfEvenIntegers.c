#include <stdio.h>
int main(void){
	int sum = 0;
	for(int even = 2;even <= 30;even += 2){
		sum += even;
	}
	printf("SUM:%d",sum);
}
