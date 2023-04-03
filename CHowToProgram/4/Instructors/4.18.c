/*
 theBitRiddler
 02/04/2023
 11:30
 histogram
*/
#include <stdio.h>
int main(void) {
	int j = 0; /* outer counter */
	int i = 0; /* inner counter */
	int number = 0;
	
	printf("%s", "Enter five numbers between 1 to 30 ");
	
	for (j = 1; j <= 5; ++j) {
		scanf("%d", &number);
		
		for (i = 1; i <= number; ++i) {
			printf("%s", "*");
		}
		printf("%s", "\n");
	}
}
