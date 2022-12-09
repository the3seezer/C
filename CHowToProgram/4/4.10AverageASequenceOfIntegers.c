#include <stdio.h>
int main(void){
	int num = 0;
	int total = 0;
	int element = 0;
	puts("Enter an element or 9999 to end");
	scanf("%d",&element);
	while(element != 9999){
		total += element;
		puts("Enter an element or 9999 to end");
		scanf("%d",&element);
		num++;
	}
	printf("Average:%d\n",total / num);
}
