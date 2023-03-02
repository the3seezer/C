//time
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
	printf("local_day: %d\n",local->tm_mday);
	printf("local_monthday: %d\n",local->tm_mon + 1);
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
}
