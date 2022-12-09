//theBitRiddler
//11-10-2022
//8:50am
/* Recursive Main */
#include <stdio.h>

static int local = 1;

int main(int n){
	if(local == 20){//Base
		//return 10;//either writting Ten or The variable 'local' The output is the same
		printf("%d \n",local);
	}
	else{
		printf("%d \n",local);//Recursive Step	
		return main(local++);
	}
}
