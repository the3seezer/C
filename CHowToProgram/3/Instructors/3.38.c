/*
 theBitRiddler
 3/26/2023
 11:51 AM
 print asterisks
*/
#include <stdio.h>
int main(void) {
	int count = 0;
	
	while (++count <= 100) 
	
		count % 10 ? printf("%s", "*") : printf("%s", "*\n");
	
	return 0;
}