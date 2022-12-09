#include <stdio.h>
int main(void){
	int size = 0;
	puts("Enter the size of elements");
	scanf("%d",&size);
	int smallest = 0;
	int a = 0;
	puts("Enter an element");
	scanf("%d",&a);
	int b = 0;
	for(int c = 1;c < size;c++){
		if(a < b){
			smallest = a;
		}
		puts("Enter an element");
		scanf("%d",&b);
		if(b < a){
			smallest = b;
		}
	}
	printf("SMALLEST:%d",smallest);
}
