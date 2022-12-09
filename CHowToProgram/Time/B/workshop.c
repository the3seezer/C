//theBitRiddler
//10-5-2022
//11:08pm
/*
time()
localtime() and gmtime() */
#include <stdio.h>
#include <time.h>
int main(void){
	struct tm *local,*gm;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	printf("Hours:%d:%d:%d\n", local->tm_hour, local->tm_min, local->tm_sec);
	printf("Date:%d/%d/%d\n", local->tm_mon + 1, local->tm_mday, local->tm_year + 1900);
	printf("This is a %d day of this week and a %d of this year\n", local->tm_wday, local->tm_yday + 1);
	puts("");
	gm = gmtime(&t);
	printf("Hours:%d:%d:%d\n", gm->tm_hour, gm->tm_min, gm->tm_sec);
	printf("Date:%d/%d/%d\n", gm->tm_mon + 1, gm->tm_mday, gm->tm_year + 1900);
	printf("This is a %d day of this week and a %d of this year\n", gm->tm_wday, gm->tm_yday + 1);
}
