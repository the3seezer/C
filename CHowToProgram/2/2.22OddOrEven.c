#include <stdio.h>
int main(){
	//odd or even
	puts("Enter any number  :");
	int n = 0;
	scanf("%d",&n);
	float w = n % 2;
	if(w == 0){
		printf("%d is an even number",n);
	}
	if(w != 0){
		printf("%d is not an even number",n);
	}
}
