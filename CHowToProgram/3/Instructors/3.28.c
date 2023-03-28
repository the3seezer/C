/*
 theBitRiddler
 3/23/2023
 11:53 AM
 passes and failures
*/
#include <stdio.h>
int main(void) {
	int passes = 0;
	int failures = 0;
	int student = 1;
	int result = 0;
	
	while (student <= 10) {
		printf("%s", "Enter result (1=pass and 2=fail): ");
		scanf("%d", &result);
		
		while (result != 1 && result != 2) {
			printf("%s", "Invalid result\nEnter result (1=pass and 2=fail): ");
			scanf("%d", &result);
		} /* end while */
		
		if (result == 1) {
			passes++;
		}
		else {
			failures++;
		}
		
		student++;
	} /* end while */
	
	printf("Passed %d\nFailed %d\n", passes, failures);
	
	if (passes >= 8) {
		printf("%s", "Raise Tuition\n");
	}
}
