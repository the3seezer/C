// theBitRiddler
// 12/6/2022
// 9:32am
/* Treating character arrays as strings.
 Demonstrating character arrays */
#include <stdio.h>
#define SIZE 20

int main(void){
	char string1[SIZE] = "";
	char string2[] = "string literal";
	
	puts("Enter a string (no longer than 19 characters)");
	scanf("%19s", string1);
	
	printf("String1 is: %s\nString2 is: %s\n", string1, string2);
	puts("String1 with spaces: ");
	for (size_t i = 0; i < SIZE && string1[i] != '\0'; ++i) {
		printf("%c ", string1[i]);
	}
}
