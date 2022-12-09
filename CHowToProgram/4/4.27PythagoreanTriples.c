#include <stdio.h>
int main(void){
	puts("The Pythagorean Triples");
	for (int i = 1;i <= 500;i++){
		for(int j = 1;j <= 500;j++){
			for(int k = 1;k <= 500;k++){
				if(i*i + j*j == k*k){
					printf("%d\t%d\t%d\n",i,j,k);
				}
				if(i*i == j*j + k*k){
					printf("%d\t%d\t%d\n",i,j,k);
				}
				if(j*j == i*i + k*k){
					printf("%d\t%d\t%d\n",i,j,k);
				}
			}
		}
	}
}
