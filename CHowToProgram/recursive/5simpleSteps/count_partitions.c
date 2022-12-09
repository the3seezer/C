//theBitRiddler
//11/18/2022
//4:46pm
/* 
write a function that counts the number of ways you can partition n objects using parts
up to m (assuming m >= 0)
*/
#include <stdio.h>

int partitions(int ,int);

int main(void){
	puts("Enter a number of objects to be partioned");
	int b = 0;
	scanf("%d",&b);
	puts("Enter a limitation of size of groups");
	int g = 0;
	scanf("%d",&g);
	printf("Number of ways to partiton a number of object: %d\n",partitions(b,g));
}

int partitions(int n,int m){
	if(n == 0){
		return 1;
	}
	else if(m == 0 || n < 0){
		return 0;
	}
	else{
		return partitions(n - m,m) + partitions(n,m - 1);
	}
}
