//theBitRiddler
//10-6-2022
//5:30pm
/* double difftime(time_t time2, time_t time1);
clock_t clock(void);
 */
#include <stdio.h>
#include <conio.h>//for getch functions
#include <time.h>
int main(void){
	time_t start,end;
	start = time(NULL);
	getch();
	end = time(NULL);
	printf("Difference:%f\n",difftime(end, start));
}
