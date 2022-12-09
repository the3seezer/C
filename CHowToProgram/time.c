//theBitRiddler
//11/23/2022
//6:10pm
/*
time_t time(time_t *time);

struct tm *localtime(const time_t *time);
struct tm *gmtime(const time_t *time);
when getting time...
int tm_sec; Seconds: 0-59 (K&R says 0-61?)
int tm_min; Minutes: 0-59
int tm_hour; Hours Since midnight: 0-23
int tm_mday; Day of the month: 1-31(just add one to it when getting time)
int tm_mon;  Months *since* january: 0-11
int tm_year; Years since 1900(just add 1900 to it when getting time)
int tm_wday; Days since Sunday (0-6)
int tm_yday; Days since Jan. 1: 0-365
int tm_isdst; +1 Daylight Savings Time, 0 No DST,
				-1 don't know

char *asctime(const struct tm *ptr);
day month date hours:minutes:seconds year\n\0

char *ctime(const time_t *time);
day month date hours:minutes:seconds year\n\0

double difftime(time_t time2, time_t time1); 

clock_t clock(void);
CLOCKS_PER_SEC

time_t mktime(struct tm *time);

size_t strftime(char *str, size_t maxsize, const char *fmt, const struct tm *time);
%A full weekday name
%B full monthday name
%c standard date and time string
%H hour(0-23)
%I hour(1-12)
%p Locale's equivalent of AM or PM
%M minutes as decimal (0-59)
%S seconds as decimal (1-60)
%X standard time string
%Z Time zone name
NOTE:be careful with the format specifiers or you won't get output even for a single mistake
 */
#include <stdio.h>
#include <unistd.h>
#include <time.h>
int main(void){
	time_t n = time(NULL);
	printf("Present in secs since 1972 Jan 1 midnight: %ld\n",n);
	sleep(1);
	time_t t = time(NULL);
	printf("The other time: %ld\n",t);
	double diff = difftime(t,n);
	printf("The difference: %f\n",diff);
	
	char *str_n = ctime(&n);
	printf("Present in ctime: %s\n",str_n);
	
	struct tm *local = localtime(&n);
	printf("local_sec: %d\n",local->tm_sec);
	printf("local_min: %d\n",local->tm_min);
	printf("local_hour: %d\n",local->tm_hour);
	printf("local_monthday: %d\n",local->tm_mday);
	printf("local_month: %d\n",local->tm_mon + 1);
	printf("local_year: %d\n",local->tm_year + 1900);
	printf("local_weekday: %d\n",local->tm_wday);
	printf("local_yearday: %d\n",local->tm_yday);
	printf("is local day light saving time: %d\n",local->tm_isdst);
	
	char *str_local = asctime(local);
	printf("Local in string: %s\n",str_local);
	
	struct tm *gm = gmtime(&n);
	printf("gm_sec: %d\n",gm->tm_sec);
	printf("gm_min: %d\n",gm->tm_min);
	printf("gm_hour: %d\n",gm->tm_hour);
	printf("gm_day: %d\n",gm->tm_mday);
	printf("gm_monthDay: %d\n",gm->tm_mon + 1);
	printf("gm_year: %d\n",gm->tm_year + 1900);
	printf("gm_weekday: %d\n",gm->tm_wday);
	printf("gm_yearday: %d\n",gm->tm_yday);
	printf("is gm day light saving time: %d\n",gm->tm_isdst);
	char *str_gm = asctime(gm);
	printf("gm is string: %s\n",str_gm);
	
	puts("local time manipulations");
	local->tm_wday = 7;
	local->tm_min = local->tm_min + 1;
	time_t new_time  = mktime(local);
	printf("Present: %ld\n",n);
	printf("new time: %ld\n",new_time);  
	
	puts("\nString Format");
	char s[100];
	int strlen = strftime(s,100,"%I %M %p and %S seconds\n", local);//It always lets me down,Don't know why!
	printf("time by strftime: %s\n", s);//Now I know, it was the format specifiers: so be careful with
	printf("Its string length: %d\n\n",strlen);//*
	
	puts("Timing");
	clock_t start,end;
	start = clock();
	for(int i = 1;i <= 10000000;i++);
	end = clock();
	double total = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Time Spent for the loop statement: %fs\n",total);
}
