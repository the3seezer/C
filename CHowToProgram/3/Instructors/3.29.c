/*
 theBitRiddler
 3/23/2023
 12:11 PM
 What does it do?
*/
#include <stdio.h>
int main(void) {
	int count = 1;
	
	while (count <= 10) {
		printf("%s\n", count % 2 ? "****" : "++++++++");
		++count;
	}
}
