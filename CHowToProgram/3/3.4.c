#include <stdio.h>
int main(){
	int x = 1;
	int sum = 0;
	sum = x + sum;
	printf_s("The sum is: %d\n",sum);
	//3.5 counter-controlled iteration
	sum = 0;
	x = 1;
	puts("count up:");
	while(x <= 10){
		sum = sum + 1;
		x = x + 1;
		printf_s("%d\t",sum);
	}//end while
	puts("\n");
	//3.6
	puts("Input variable x");
	x = 0;
	scanf_s("%d",&x);
	puts("Input variable y");
	int y = 0;
	scanf_s("%d",&y);
	int i = 1;puts("i equals one");
	int power = 1;
	power = x * power;	
	i++;
	while(i <= y){
		printf_s("i is less or to y\n");
		y = 0;
	}
	printf_s("Power : %d\n",power);
}
