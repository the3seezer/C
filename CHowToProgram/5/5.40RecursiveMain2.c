//theBitRiddler
//11-10-2022
//8:50am
/* Recursive Main */
#include <stdio.h>

static int local = 1;

int main(int n){
	if(local == 20){//Base
		printf("%d \n",local);//either writting Ten or The variable 'local' The output is the same
	}
	else{
		printf("%d \n",local);//Recursive Step	
		main(local = local + 1);//main(local + 1) it won't increment
	}
}
