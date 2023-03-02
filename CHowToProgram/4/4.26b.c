#include <stdio.h>
int main(void){
	double n = 4;//The PIE 
	double odd = 3;
	double pi = 3.1415;
	int nth = 0;
	int size = 0;
	printf("%s","Specify the number of terms to be used\n");
	scanf("%d",&size);
	printf("%21s%21s\n","Terms","Values");
	int i = 1;
	while(i <= size){
		if(i == 1){
			//leaving it does nothing but continue jumps the process
		}
		else if(!(i % 2)){
			n = n - (4 / odd);
			odd += 2;
		}
		else if(i % 2){
			n = n + (4 / odd);
			odd += 2;
		}
		printf("%21d%21lf\n",i,n);
		
		int m = (int)10000 * n;
		int o = (int)10000 * pi;
		if(m == o){
			nth = i;
			break;
		}
		i++;
	}
	printf("The %dth term of value:%lf\n",nth,pi);
}
