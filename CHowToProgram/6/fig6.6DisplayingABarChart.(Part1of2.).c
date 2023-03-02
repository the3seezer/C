// theBitRiddler
// 11/30/2022
// 9:38am
/* Graphing Array Element values with bar charts
*/
#include <stdio.h>

#define SIZE 5

int main(void){
	int n[SIZE] = {19, 5, 22, 8, 11};
	
	printf("%s%13s%17s\n", "Elements", "Values", "Bar Chart");
	for (size_t i = 0; i < SIZE; i++){
		printf("%8zu%13d%8s", i, n[i], "");
		for (int j = 1; j <= n[i]; ++j) {
			printf("%c", '*');
		}
		puts("");
	}
}
