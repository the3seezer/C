//theBitRiddler
//10-4-2022
//10:19pm
//time_t,time(NULL)
#include <stdio.h>
#include <time.h>

int main(void){
	time_t now = time(NULL);//time(NULL)returns number of seconds since. Jan 1, 1970 midnight and time_t has a long int(%ld)
	printf("%ld\n",now);
	
	char *string_now = ctime(&now);//*string_now is a pointer and ctime function converts to string works with time_t variable type
	printf("%s\n",string_now);
	
	struct tm *gm_time = gmtime(&now);//gm_time is a pointer ...connecting to the variable now
	printf("tm_sec;seconds after the minute: %d\n",gm_time->tm_sec);
	printf("tm_min;minutes after the hour: %d\n",gm_time->tm_min);
	printf("tm_hour;hours since midnight: %d\n",gm_time->tm_hour);
	printf("tm_mday;day of the month: %d\n",gm_time->tm_mday);
	printf("tm_mon;months since Jan: %d\n",gm_time->tm_mon);
	printf("tm_year;years since 1900: %d\n",gm_time->tm_year);
	printf("tm_wday;days since sunday: %d\n",gm_time->tm_wday);
	printf("tm_yday;days since Jan 1: %d\n",gm_time->tm_yday);
	printf("tm_isdst;daylight Saving Time Flag: %d\n",gm_time->tm_isdst);
	puts("\n");
	struct tm *cur_time = localtime(&now);
	printf("tm_sec;seconds after the minute: %d\n",cur_time->tm_sec);
	printf("tm_min;minutes after the hour: %d\n",cur_time->tm_min);
	printf("tm_hour;hours since midnight: %d\n",cur_time->tm_hour);
	printf("tm_mday;day of the month: %d\n",cur_time->tm_mday);
	printf("tm_mon;months since Jan: %d\n",cur_time->tm_mon);
	printf("tm_year;years since 1900: %d\n",cur_time->tm_year);
	printf("tm_wday;days since sunday: %d\n",cur_time->tm_wday);
	printf("tm_yday;days since Jan 1: %d\n",cur_time->tm_yday);
	printf("tm_isdst;daylight Saving Time Flag: %d\n\n",cur_time->tm_isdst);
	
	char *other_string = asctime(cur_time);//to convert the struct tm back to the string ;works with struct tm type
	printf("%s\n\n",other_string);
	
	cur_time->tm_min = cur_time->tm_min + 1;
	time_t new_time = mktime(cur_time);//convert struct tm back to secs in time_t
	printf("now: %ld\n",now);
	printf("new time: %ld\n\n",new_time);
	
	char s[100];
	int len = strftime(s,100,"%B : %d : %A", cur_time);//working with struct tm into a string returns string lenth
	printf("%s \nstring lenth:%d\n\n",s,len);
	
	clock_t start,end;//to measure the time taken btn the two variables assigned to a value to be returned by clock() function
	start = clock();
	for(int i = 0;i < 1000000000;i++){}
	end = clock();
	double total = (double) (end - start) / CLOCKS_PER_SEC;
	printf("Time :%fs\n",total);
}
