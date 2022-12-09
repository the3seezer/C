#include <stdio.h>
int main(){
	int a[3][3] = {12,34,56,32,89,23,44,67,99};
	int i,j;
	for(i = 0;i < 3;i++){
		for(j = 0;j < 3;j++){
			printf("%d\n",a[i][j]);
		}
	}
}
