#include <stdio.h>
int main(void){
	int pre = 4;
	int post = 4;
	printf_s("pre %d\n",--pre);
	printf_s("post %d\n",post--);
	
	int numb = 0;
	while(numb <= 10){
		printf_s("%d   ",numb++);
	}
}
