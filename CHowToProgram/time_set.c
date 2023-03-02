//theBitRiddler
//11/24/2022
//12:02am
/*struct tm *localtime(const time_t *time);
struct tm *gmtime(const time_t *time);
when setting time...
Note:minus 'one/the value' to every desired set time for every variable that begins with zero
int tm_sec; Seconds: 0-59 (K&R says 0-61?)
int tm_min; Minutes: 0-59
int tm_hour; Hours Since midnight: 0-23
int tm_mday; Day of the month: 1-31 (write it as it was, because it begins that way/begins with one)
int tm_mon;  Months *since* january: 0-11
int tm_year; Years since 1900
int tm_wday; Days since Sunday (0-6)
int tm_yday; Days since Jan. 1: 0-365
int tm_isdst; +1 Daylight Savings Time, 0 No DST,
				-1 don't know
				
time_t mktime(struct tm *time);
*/
#include <stdio.h>
#include <time.h>
int main(void){
	time_t t;
	struct tm set;
	set.tm_year = 2022 - 1900;
	set.tm_mon = 12 - 1;//December |'one/the value' to every desired set time for every variable that begins with zero
	set.tm_mday = 24;//(write it as it was, because it begins that way/begins with one)
	
	set.tm_hour = 0;
	set.tm_min = 0;
	set.tm_sec = 0;
	set.tm_isdst = 0;
	
	t = mktime(&set);
	puts(ctime(&t));
	
}
