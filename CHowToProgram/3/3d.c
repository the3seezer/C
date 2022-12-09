#include <stdio.h>
int main(){
	//the first power of 3 Greater than 100
	int product = 3;
	while(product <= 100){
		product = 3 * product;
	}
	printf("%d\n",product);
	/*product = 3;
	while(product <= 100){
		product = product * 3;
	}
	printf("%d",product);*/
}
