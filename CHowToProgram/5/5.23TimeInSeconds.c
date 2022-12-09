//theBitRiddler
//10-8-2022
//11:20
//Time in seconds

#include <stdio.h>
#include <time.h>
int main(void){
	struct tm t,t2;
	time_t time,time2;
	t.tm_year = 2022 - 1900;
	t.tm_mon = 9;
	t.tm_mday = 8;
	t.tm_hour = 13;
	t.tm_min = 4;
	t.tm_sec = 48;
	t.tm_isdst = 0;
	
	t2.tm_year = 2022 - 1900;
	t2.tm_mon = 9;
	t2.tm_mday = 8;
	t2.tm_hour = 22;
	t2.tm_min = 20;
	t2.tm_sec = 20;
	t2.tm_isdst = 0;
	
	time = mktime(&t);
	time2 = mktime(&t2);
	puts(ctime(&time));
	puts(ctime(&time2));
	printf("The difference btn two times:%f",difftime(time2,time));	
}
