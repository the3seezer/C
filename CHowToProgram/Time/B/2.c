//theBitRiddler
//10-5-2022
//11:52pm
//setdate(),getdate(),...
#include <stdio.h>
#include <time.h>
int main(void){
	time_t t;
	t = time(NULL);
	struct tm *local = localtime(&t);
	printf("Time:%s\n",asctime(local));
	printf("Time:%d\n",ctime(&t));
}
