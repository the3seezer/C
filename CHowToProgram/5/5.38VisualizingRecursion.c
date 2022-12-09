//TheBitRiddler
//11-5-2022
//2:06
//visualing Recursion
#include <stdio.h>

unsigned long long int recursion(int);

int main(void){
	for(int i = 1;i <= 21;i++){
		printf("%d!",i);
		for(int j = 1;j <= i;j++){
			printf("%s"," ");
		}
		printf("Factorial:%llu\n",recursion(i));
		puts("");
	}
	//int y = recursion(n);	
}

unsigned long long int recursion(int n){
	if(n == 1){
		return 1;
	}
	else{
		unsigned long long int y = n * recursion(n - 1);
		printf(" %llu ",y);
		return y;
	}
}

