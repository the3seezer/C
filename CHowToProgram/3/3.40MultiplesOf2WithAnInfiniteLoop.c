#include <stdio.h>
int main(void){
	int counter = 1;
	while(counter != -1){//This is an infinite loop
		counter % 2 == 0 ? printf_s("%d",counter) : printf_s("\n");
		counter++;//printf("%d",counter);
	}
}
