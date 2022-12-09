#include <stdio.h>
int main(void){
	int count = 1;
	while(count <= 10){//loop 10 times
	puts(count % 2 ? "****" : "++++++++");
	++count;//increment count
	}
}
