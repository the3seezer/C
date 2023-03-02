//theBitRiddler
//24/9/2022
//11:02
//Car charges per hour and receits
#include <stdio.h>

double calculateCharges(float hour);

int main(void){
	float hr1 = 0;
	float t_hr1 = 0;//total hours of car one
	float hr2 = 0;
	float t_hr2 = 0;
	float hr3 = 0;
	float t_hr3 = 0;
	float hr = 0;//total hours
	double ch1 = 0;
	double ch2 = 0;
	double ch3 = 0;
	double ch = 0;//total charge
	int a = 0;int b = 0;int c = 0;//total number of receits
	int car = 0;
	puts("Enter the car labels:1,2,3 or -1 to end");
	scanf("%d",&car);
	while(car != -1){
		switch(car){
			case 1:
				puts("Enter the hours car one spent");
				scanf("%f",&hr1);
				t_hr1 += hr1;// printf("%f",hr1); //total hours
				ch1 = calculateCharges(t_hr1);
				a++;//total number of receits
				break;
			case 2:
				puts("Enter the hours car two spent");
				scanf("%f",&hr2);
				t_hr2 += hr2;
				ch2 = calculateCharges(t_hr2);
				b++;
				break;
			case 3:
				puts("Enter the hours car three spent");
				scanf("%f",&hr3);
				t_hr3 += hr3;
				ch3 = calculateCharges(t_hr3);
				c++;
				break;
			default:
				puts("You entered a wrong number ");
				break;
		}
		puts("Enter the car labels:1,2,3 or -1 to end");
		scanf("%d",&car);
	}
	printf("%s%15s%15s\n","Car","Hours","Charge");
	printf("1%15.1f%15.2f\n",t_hr1,ch1);
	printf("2%15.1f%15.2f\n",t_hr2,ch2);
	printf("3%15.1f%15.2f\n",t_hr3,ch3);
	printf("TOTAL%11.1f%15.2f\n",t_hr1 + t_hr2 + t_hr3,ch1 + ch2 + ch3);
}

double calculateCharges(float h){//printf("%f\n",h);
	float ch = 0;
	if(h < 24){
		if(h <= 3){
			ch = 2;
		}
		else{
			ch = 2;
			h -= 3;
			while(h){
				ch += .5;
				h--;
			}
		}
		return ch;
	}
	else{
		ch = 10;
		return ch;
	}
}

