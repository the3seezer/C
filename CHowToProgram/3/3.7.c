#include <stdio.h>
int main(){
	//3.7
	int result = 1;
	puts("Input variable x");
	int x = 0;
	scanf_s("%d",&x);
	puts("Input variable y");
	int y = 0;
	scanf_s("%d",&y);
	int i = 1;
	while(i <= y){
		result = result * x;//result *= x;
		i = i + 1;
	}//end while
	printf_s("x raised to the y power: %d",result);
}
