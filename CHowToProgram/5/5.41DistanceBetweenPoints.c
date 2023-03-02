//theBitRiddler
//11-10-2022
//11:19am
//Distance Between Points
#include <stdio.h>
#include <math.h>

double distance(int ,int ,int ,int);

int main(void){
	puts("Enter values of two points");
	int x1 = 0,y1 = 0,x2 = 0,y2 = 0;
	puts("Point One");
	scanf("%d%d",&x1,&y1);
	puts("Point Two");
	scanf("%d%d",&x2,&y2);
	printf("Distance:%.2lf\n",distance(x1,y1,x2,y2));
}

double distance(int x1,int y1,int x2,int y2){
	return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
}
