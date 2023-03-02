#include <stdio.h>
int main(){
	//reading two intergers
	int a = 0;
	int b = 0;
	puts("And two integers");
	scanf("%d%d",&a,&b);
	if((a % b) == 0){
		printf("%d is a multiple of %d",a,b);
	}
	if((a % b) != 0){
		printf("%d is not a multiple of %d",a,b);
	}
	/*if((b % a) == 0){
		printf("%d is a multiple of %d",b,a);
	}
	if((b % a) != 0){
		printf("%d is not a multiple of %d",b,a);
	}*/
}
