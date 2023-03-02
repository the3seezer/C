#include <stdio.h>
	struct student {
		int serialNo;
		char name[6];
		float gpa;
	};
int main(){
	struct student A1;
	struct student *ptr;
	ptr = &A1;
	//inputting the values
	printf_s("%s","Input serial number:\n");
	scanf_s("%d",&(*ptr).serialNo);
	
	printf_s("%s","Input GPA:\n");
	scanf("%f",&ptr->gpa);
	
	printf_s("%s","Input name:\n");//name is not working
	int i = 0;
	for(i = 0;i < 6;++i){
		scanf("%c",&ptr->name[i]);
	}
	//outputting
	printf("Serial Number;%d\nGPA;%f\n",(*ptr).serialNo,ptr->gpa);
	puts("Name: ");
	for(i = 0;i < 6;++i){
		printf("%c",A1.name[i]);
	}
}
