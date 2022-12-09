//theBitRiddler
//11/18/2022
//3:47pm
/*Write a function that takes inputs n and m and outputs a number of unique paths
from the top left corner to the bottom right corner of a n * m grid
Constraints:you can only move down or right one unit at a time;
*/
#include <stdio.h>

int grid_path(int ,int);

int main(void){
	puts("Enter the number of boxes in the grid from ");
	int n = 0,m = 0;
	puts("Top to bottom");
	scanf("%d",&n);
	puts("Left to right");
	scanf("%d",&m);
	printf("The number of pathes: %d\n",grid_path(n,m));
}

int grid_path(int n,int m){
	if(n == 1 || m == 1){
		return 1;
	}
	else{
		return grid_path(n,m - 1) + grid_path(n - 1,m);
	}
}
