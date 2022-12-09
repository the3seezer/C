//theBitRiddler
//11-10-2022
//12:10pm
/* 
what does this program do?
It kinda does multiplication
*/
#include <stdio.h>
#include <math.h>

double mystery(int a, int b);

int main(void){
	printf("%s","Enter two positive integers: ");
	int x = 0;//first integer
	int y = 0;//second integer
	scanf("%d%d",&x, &y);
	
	printf("The result is %.2lf\n",mystery(x, y));
}

//Parameter b can be a negative integer
//infinite recursion problem is solved
double mystery(int a, int b){
	int flag = 0,y = 0;
	if(b < 0){
		flag = 1;
	}
	b = fabs(b);
	if(1 == b){//base case
		return a;
	}
	else{//recursive step
		if(flag == 1){
			y = a + mystery(a, b - 1);
			return -y;
		}
		else{
			return a + mystery(a, b - 1);
		}
	}
}
