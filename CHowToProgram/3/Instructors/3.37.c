/*
 theBitRiddler
 3/26/2023
 11:21 AM
 How fast is your computer
*/
#include <stdio.h>
int main(void) {
	long int count = 1;
	
	while (count <= 300000000) {
		
		if (count % 100000000 == 0) {
			printf("The multiple is %d\n", count / 100000000);
		}
		
		++count;
	}
}