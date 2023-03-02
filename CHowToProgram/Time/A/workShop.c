//theBitRiddler
//10-5-2022
//2:44pm
//time
#include <stdio.h>
#include <unistd.h>
#include <time.h>
int main(void){
	time_t now = time(NULL);
	printf("%ld\n",now);
//	sleep(10);
//	time_t new_time = time(NULL);
//	printf("%d\n",new_time);
//	printf("difference:%f\n",difftime(new_time,now));//difftime returning a double

	char *tim = ctime(&now);
	printf("%s\n",tim);
	
	struct tm *gm_t = gmtime(&now);
	printf("secs:%d\n",gm_t->tm_sec);
	printf("mins:%d\n",gm_t->tm_min);
	printf("hours:%d\n",gm_t->tm_hour);
	printf("month days:%d\n",gm_t->tm_mday);
	printf("year months:%d\n",gm_t->tm_mon);
	printf("years since 1900:%d\n",gm_t->tm_year);
	printf("week days:%d\n",gm_t->tm_wday);
	printf("year days:%d\n",gm_t->tm_yday);
	printf("daylight saving time flag:%d\n\n",gm_t->tm_isdst);
	
	struct tm *localT = localtime(&now);
	printf("secs:%d\n",localT->tm_sec);
	printf("mins:%d\n",localT->tm_min);
	printf("hours:%d\n",localT->tm_hour);
	printf("month days:%d\n",localT->tm_mday);
	printf("year months:%d\n",localT->tm_mon);
	printf("years since 1900:%d\n",localT->tm_year);
	printf("week days:%d\n",localT->tm_wday);
	printf("year days:%d\n",localT->tm_yday);
	printf("daylight saving time flag:%d\n\n",localT->tm_isdst);
	
	char *time_string = asctime(localT);
	printf("%s\n",time_string);
	
	localT->tm_hour = localT->tm_hour + 1;
	time_t new_time = mktime(localT);
	printf("now %ld\n",now);
	printf("new time %ld\n",new_time);
	
	char s[100];
	int strlen = strftime(s,100,"%A %B %d ", localT);
	printf("time:%s and string lenth:%d\n",localT,strlen);
	
	clock_t start,end;
	start = clock();
	for(int i = 1;i <= 100000000;i++){
	}
	end = clock();
	double total = (double) (end - start) / CLOCKS_PER_SEC;
	printf("Run time:%f\n",total);
}



