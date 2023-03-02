#include <stdio.h>
int main(void){
	int side = 0;
	int width = 1;//side counter
	scanf_s("%d",&side);
	if(side <= 20){
		while(width <= side){
			int height = 1;
	 		while(height <= side){
	 			printf_s("%s", "*"  );
	 			height++;
			}
			width++;
			puts("");
		}
	}	
}
