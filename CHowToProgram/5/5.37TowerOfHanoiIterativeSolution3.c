//theBitRiddler
//11-3-2022
//5:36pm
//tower of Hanoi Iterative Solution
#include <stdio.h>
#include <math.h>

void Tower_Hanoi(int ,int ,int ,int);

int main(void){
	puts("Enter number of disks: ");
	int disks = 0;
	scanf("%d",&disks);
	int s = 1,a = 2,d = 3;
	Tower_Hanoi(disks,s,a,d);
}

void Tower_Hanoi(int n,int s,int a,int d){
	for(int i = 1;i <= (pow(2,n) - 1);i++){
		int fro = ((i&(i-1))%3) + 1;
		int to = (((i | (i-1)) + 1)%3) + 1;
		printf("%d -> %d\n",fro,to);
	}
}
