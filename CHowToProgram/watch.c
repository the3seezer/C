//watch
#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main(void){
	time_t t = 1;
	while(t){
		t = time(NULL);//time in secs since 1972 Jan 1 midnight
		struct tm *local = localtime(&t);
		printf("Time %d : %d : %d\n",local->tm_hour,local->tm_min,local->tm_sec);
		sleep(1);
	}
}
