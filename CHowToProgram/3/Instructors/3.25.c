/* 
 theBitRiddler
 3/22/2023
 3:52 PM
 utelizing the loop
*/
#include <stdio.h>
int main(void) {
	int n = 0;
	
	printf("%s", "\tN\t\tN * 10\t\tN * 100\t\tN * 1000\n");
	while (++n <= 10) {
		printf("\t%-2d\t\t%-5d\t\t%-7d\t\t%-9d\n", n, n * 10, n * 100, n * 1000);
	}
}