#include <stdio.h>
int main(){
	//A program whitch stores values of students
	int a[25];
	int i = 0;
	for(i = 0;i < 25;i = i + 1){
		scanf("%d",&a[i]);
	}
	for(i = 0;i < 25;i++){
		printf("%d\t",a[i]);
	}
	
}
