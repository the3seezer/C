#include <stdio.h>
int main(void){
	printf_s("Enter two numbers\n");//(a)
	int x = 0;//(b)
	int y = 0;
	scanf_s("%d%d",&x,&y);

	int z = 2;
	int p = x + y + z;
	int m = x;
	int v = y;
	if(m > 2 * v);
		printf_s("%d is greaster than 2 x %d\n",m,v);
	
	printf_s("s:%d r:%d t:%d",'s','r','t');
}
