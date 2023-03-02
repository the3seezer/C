#include <stdio.h>
int main(){
	int sum = 0;
	int z = 100;
	
	while(z >= 0){
		sum += z;printf_s("%d\t",sum);
		z--;printf_s("%d\n",z);
	}//end while
	printf_s("The sum from 100 to 1: %d",sum);
}
