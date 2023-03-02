#include <stdio.h>
int main(void){//Pythagorus Theorem
	int a = 0;
	int b = 0;
	int c = 0;
	printf_s("%s","Add three values: \n");
	scanf_s("%d%d%d",&a,&b,&c);
	if(a * a + b * b == c * c){
		printf_s("This is a right angled Triangle\n");
	}
}
