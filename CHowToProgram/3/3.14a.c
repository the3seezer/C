#include <stdio.h>
int main(void){
	int a = 0;
	int b = 0;
	puts("Input two numbers");
	scanf_s("%d%d",&a,&b);
	printf_s("The sum %d\n",a + b);
	//(b)
	if(a > b){
		printf_s("%d is larger than %d\n",a,b);
	}//end if
	else{
		printf_s("%d is larger than %d\n",b,a);
	}//end else
	//(c)
	int total = 0;
	int counter = 0;
	
	printf_s("Enter the numbers.-1 to terminate\n");
	int numbers = 0;
	scanf_s("%d",&numbers);
	while(numbers != -1){
		total += numbers;
		counter++;
		scanf_s("%d",&numbers);
	}
	printf_s("The sum is: %d\n",total);
}
