//theBitRiddler
//18-9-2022
//11:11
//fig05_08
//Scopping
#include <stdio.h>

void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);

int x = 1;//file scope

int main(void){
	//printf("x Global before declaration in main is one == %d\n",x);
	int x = 5;//outer block scope
	printf("Local x main outer scope is %d\n",x);
	
	{
		int x = 7;//inner block scope
		printf("Local x main inner scope is %d\n",x);
	}
	
	useLocal();
	useStaticLocal();
	useGlobal();
	puts("\n");
	useLocal();
	useStaticLocal();
	useGlobal();
	puts("\n");
	printf("Local x main outer scope is %d\n",x);
}

void useLocal(void){
	int x = 25;
	printf("x after enterintg uselocal %d\n",x);
	x++;
	printf("x before leaving uselocal %d\n",x);
}

void useStaticLocal(void){
	static int x = 50;
	printf("x after entering useStaticLocal %d\n",x);
	x++;
	printf("x before leaving useStaticLocal %d\n",x);
}

void useGlobal(void){
	printf("x after entering useGlobal %d\n",x);
	x *= 10;
	printf("x before leaving useGlobal %d\n",x);
}
