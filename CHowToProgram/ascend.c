#include <stdio.h>
int main(){
	puts("input the array size 15");
	int n = 0;
	scanf_s("%d",&n);
	
	int array[n];
	int i = 0;
	int j = 0;
	int temp = 0;
	
	//input the elements
	puts("Input the elements: ");
	for(i = 0;i < n;++i){
		scanf_s("%d",&array[i]);
	}
	//processing
	for(i = 0;i < n;++i){
		for(j = i + 1;j < n;++j){
			if(array[i] > array[j]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp; 
			}
		}
		printf_s("%d\t",array[i]);
	}
	//outputting
	//puts("In ascending order: ");
	//for(i = 0;i < n;++i){
	//	printf_s("%d\n",array[i]);
	//}
}
