//theBitRiddler
//10-4-2022
//10:19pm
//time_t,time(NULL)
#include <stdio.h>
#include <time.h>

int main(void){
	time_t now = time(NULL);//time(NULL)returns number of seconds since. Jan 1, 1970 midnight and time_t has a long int(%ld)
	printf("%ld\n",now);
}
