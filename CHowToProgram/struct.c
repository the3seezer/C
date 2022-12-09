#include <stdio.h>
	struct student {
		int serialNo;
		char name[30];
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
	gets(ptr->name);
	//outputting
	printf("The student:\nName;%s\nSerial Number;%d\nGPA;%f\n",ptr->name,(*ptr).serialNo,ptr->gpa);
}
