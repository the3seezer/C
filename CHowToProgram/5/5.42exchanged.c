//theBitRiddler
//11-10-2022
//11:59am
/* What does this program do? 
It behaves like a while loop(It's a Main Recursive)*/
#include <stdio.h>
int main(void){
	int c = '\0';//variable to hold character input by user
	
	if((c = getchar()) != EOF){
		printf("%c",c);
		main();
	}
}
