//theBitRiddler
//10-7-2022
//2:54pm
/*
size_t strftime(char *str, size_t maxsize, const char *fmt, const struct tm *time);

%A Full weekday name
%B Full month name
%c Standard date and time string
%H Hour (0-23)
%I Hour (1-12)
%p Locale's equivalent of AM or PM
%M Minute as decimal (0-59)
%S Second as decimal (0-60)
%X Standard time string
%Z Time zone name
*/
#include <stdio.h>
#include <time.h>
int main(void){
	struct tm *ptr;
	time_t t;
	
	t = time(NULL);
	
	ptr = localtime(&t);
	char str[100];
	strftime(str,100,"It's at %I %p %M minutes and %S seconds\nThe Time zone is %Z\n",ptr);
	puts(str);
}

