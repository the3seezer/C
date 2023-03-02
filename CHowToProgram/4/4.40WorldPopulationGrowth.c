#include <stdio.h>
int main(void){
	float population = 7971458254;
	float end_p = 0;//population at the end of the year
	float increased = 0;
	float rate = .0085;
	printf("%21s%21s%21s\n","Year","Population","Increased");
	for(int y = 1;y <= 95;y++){//75year to be written
		if(y == 1){
			printf("%21d",2021 + y);
			printf("%21.2f",population);
			printf("%21s\n","--");
		}
		end_p = population;
		printf("%21d",2021 + y);
		increased = population * rate;
		end_p += increased;
		printf("%21.2f",end_p);
		printf("%21.2f\n",increased);
		population = end_p;	
	}
	puts("\n");
	//Doubled population
	population = 7971458254;
	float p = population;
	end_p = 0;//population at the end of the year
	increased = 0;
	rate = .0085;
	printf("%21s%21s%21s\n","Year","Population","Increased");
	for(int y = 1;y <= 95;y++){//75year to be written
		end_p = population;
		if(population >= 2*p){
			puts("Doubled Population");
			printf("%21d",2021 + y);
			printf("%21.2f",end_p);
			printf("%21.2f\n",increased);
			break;
		}
		increased = population * rate;
		end_p += increased;
		population = end_p;	
	}
}
