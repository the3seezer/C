//theBitRiddler
//11-10-2022
//11:59am
/* What does this program do? 
It holds the character input values of user in a variable;in a stack-like form FILO
AND it behaves like a loop (Its a main recursive)*/
#include <stdio.h>
int main(void){
	int c = '\0';//variable to hold character input by user
	
	if((c = getchar()) != EOF){
		main();
		printf("%c",c);
	}
}
