//theBitRiddler
//10-5-2022
//10:15pm
/* 
time_t time(time_t *time);
struct tm *localtime(const time_t *time);
struct tm *gmtime(const time_t *time);
*/
#include <stdio.h>
#include <conio.h>
#include <time.h>

int main(void){
	struct tm *local,*gm;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	puts("local time and date using localtime function");
	printf("time:%d hours %d minutes %d seconds\n", local->tm_hour, local->tm_min, local->tm_sec);
	printf("Date:%d / %d / %d\n", local->tm_mon + 1, local->tm_mday, local->tm_year + 1900);
	printf("This is the %d day of this week\n", local->tm_wday);
	printf("This is the %d day of this year\n", local->tm_yday + 1);
	puts("");
	gm = gmtime(&t);
	puts("UTC time and date using gmtime function");
	printf("time:%d hours %d minutes %d seconds\n", gm->tm_hour, gm->tm_min, gm->tm_sec);
	printf("Date:%d / %d / %d\n", gm->tm_mon + 1, gm->tm_mday, gm->tm_year + 1900);
	printf("This is the %d day of this week\n", gm->tm_wday);
	printf("This is the %d day of this year\n", gm->tm_yday + 1);
}
