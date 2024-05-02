/* 
 theBitRiddler
 3/25/2023
 8:11 AM
 Another Dangling else Problem
*/
#include <stdio.h>
int main(void) {
	int x = 5;
	int y = 5;
	
	if (y == 8)
	if (x == 5)
	printf("%s", "@@@@@\n");
	else
	printf("%s", "#####\n");
	printf("%s", "$$$$$\n");
	printf("%s", "&&&&&\n");
	
}