//theBitRiddler
//10-4-2022
//10:19pm
//time_t,time(NULL)
#include <stdio.h>
#include <unistd.h>//to sleep the program
#include <time.h>

int main(void){
	time_t now = time(NULL);//time(NULL)returns number of seconds since. Jan 1, 1970 midnight and time_t has a long int(%ld)
	printf("%ld\n",now);
	sleep(2);
	time_t two_secs = time(NULL);
	printf("%ld\n",two_secs); 
	double diff = difftime(two_secs,now);
	printf("difference: %f\n",diff);
}
