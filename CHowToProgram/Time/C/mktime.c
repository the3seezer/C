//theBitRiddler
//10-7-2022
//9:31am
/*
time_t mktime(struct tm *time);
*/
#include <stdio.h>
#include <time.h>
int main(void){
	struct tm t;
	time_t timeinc;
	
	t.tm_year = 2022 - 1900;//year starts with 1900
	t.tm_mon = 9;
	t.tm_mday = 7;
	
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;
	t.tm_isdst = 0;
	
	timeinc = mktime(&t);
	printf(ctime(&timeinc));
}
