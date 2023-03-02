#include <stdio.h>
int main(void){
	int size = 0;
	puts("Enter the size of elements");
	scanf("%d",&size);
	int total = 0;
	for(int counter = 1;counter <= size;counter++){
		puts("Enter an element");
		int element = 0;
		scanf("%d",&element);
		total += element;
	}
	printf("TOTAL:%d\n",total);
}
