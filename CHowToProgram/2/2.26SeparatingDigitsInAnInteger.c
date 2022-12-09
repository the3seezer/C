#include <stdio.h>
int main(){
	printf("%s","Enter a five digit enteger: \n");
	int f = 0;
	scanf("%d",&f);	
	
	int fifth = f % 10;//getting the lowest significant digit
	f = f / 10;//removing the lowest significant figure

	int fourth = f % 10;
	f = f / 10;
	
	int third = f % 10;
	f = f / 10;
	
	int second = f % 10;
	f = f / 10;
	
	int first = f % 10;
	f = f / 10;	
	printf("%d\t%d\t%d\t%d\t%d",first,second,third,fourth,fifth);
	
}
