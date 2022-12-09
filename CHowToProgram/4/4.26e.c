#include <stdio.h>
int main(void){
	double n = 4;//The PIE 
	double odd = 3;
	double pi = 3.14159;
	int nth = 0;
	printf("%21s%21s\n","Terms","Values");
	int i = 1;
	int m = 0;
	int o = 1;
	while(m != o){
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
		m = (int)100000 * n;
		o = (int)100000 * pi;
		if(m == o){
			nth = i;
		}
		printf("%21d%21lf\n",i,n);
		i++;
	}
	printf("The %dth term of value:%lf\n",nth,pi);
}
