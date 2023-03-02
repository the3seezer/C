//theBitRiddler
//10-27-2022
//10:33AM
/*
Towers of Hanoi
s as a source ,a as auxiliary and d as destination
*/
#include <stdio.h>

void towerOH(int ,int ,int ,int);

int main(void){
	puts("Enter number of disks");
	int disks = 0;
	scanf("%d",&disks);
	int s = 1,a = 2,d = 3;
	towerOH(disks,s,a,d);
}

void towerOH(int n,int s,int a,int d){
	if(n == 1){
		printf("%d -> %d\n",s,d);
	}
	else{
		towerOH(n - 1,s,d,a);
		towerOH(1,s,a,d);
		towerOH(n - 1,a,s,d);
	}
}
