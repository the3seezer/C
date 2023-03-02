#include <stdio.h>
int main(void){
	for(int i = 1;i <= 30;++i){
		for(int j = 1;j <= i;j++){
			printf("%s","*");
		}
		puts("");
	}
}
