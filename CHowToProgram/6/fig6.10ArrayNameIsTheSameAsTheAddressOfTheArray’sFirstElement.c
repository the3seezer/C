// theBitRiddler
// 12/6/2022
// 11:02am
/* Showing that an Array Name is an Address
Array name is the same as the address of the array’s first element. 
*/
#include <stdio.h>
#define SIZE 5
int main(void) {
	char array[SIZE] = "";
	
	printf("    array = %p\n   &array = %p\n&array[0] = %p", array, &array, &array[0]);
}
