//theBitRiddler
//10-6-2022
//2:08pm
/* 
char *asctime(const struct tm *ptr);
day month date hours:minutes:seconds year\n\0

char *ctime(const time_t *time);
day month date hours:minutes:seconds year\n\0
*/
#include <stdio.h>
#include <time.h>
int main(void){
	time_t t;
	t = time(NULL);
	printf("%ld\n",ctime(&t));
	printf("%s\n",ctime(&t));
	puts(ctime(&t));
	
	puts(asctime(localtime(&t)));
	puts(asctime(gmtime(&t)));
}
