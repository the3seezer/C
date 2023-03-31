/* 
 theBitRiddler
 3/25/2023
 7:57 AM
 The Dangling else problem
*/
#include <stdio.h>
int main(void) {
	int x = 9;
	int y = 9;
	
	if (x > 10) 
	if (y < 10)
	printf("%s", "*****\n");
	else 
	printf("%s", "&&&&&\n");
	printf("%s", "$$$$$\n");
}
