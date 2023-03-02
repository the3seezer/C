//theBitRiddler
//10-21-2022
//10:55am
//limits
#include <stdio.h>
#include <limits.h>
int main(void){
	int a = 4;
	int b = 7;
	printf("a:%d b:%d\n",a,b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a:%d b:%d\n",a,b);
}
