#include <stdio.h>
int main(void){
	int x = 0;//(a)
	int y = 0;
	scanf_s("%d%d",&x,&y);
	if(x < 10)
	if(y > 10)
	puts("*****");
	else
	puts("#####");
	puts("$$$$$");
	//(b)
//	int x = 0;
//	int y = 0;
	scanf_s("%d%d",&x,&y);
	if(x < 10){
	if(y > 10)
	puts("*****");
	}
	else{
	puts("#####");
	puts("&&&&&");
	}
}
