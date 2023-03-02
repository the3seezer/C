#include <stdio.h>
int main(void){
    int population = 0;
    int presentGrowth = 7951000;//printf_s("%d",presentGrowth);
    int difference = 0;
    float rate = 1.05;
    int years = 1;
    printf("%s","Year\tPopulation\tIncrease\n");
    while(years <= 100){
    	printf("%d\t%d",years,presentGrowth);
        population = rate * presentGrowth;
        difference = population - presentGrowth;
        printf(" \t%d\n",difference);
        years++;
        presentGrowth = population;
    }
    puts("\n");
    //The doubled population
    population = 0;
    presentGrowth = 7951000;//printf_s("%d",presentGrowth);
    int present = presentGrowth;
    difference = 0;
    rate = 1.05;
    years = 1;
    printf("%s","Year\tPopulation\tIncrease\n");
    while(years <= 100){
        population = rate * presentGrowth;
        difference = population - presentGrowth;
        if(presentGrowth >= 2*present){
    		puts("Doubled");
    		printf("%d\t%d",years,presentGrowth);
    		printf("\t%d\n",difference);
        	break;
		}
        presentGrowth = population;
        years++;
    }
    puts("\n");
    //The quadrupled
    population = 0;
    presentGrowth = 7951000;//printf_s("%d",presentGrowth);
    present = presentGrowth;
    difference = 0;
    rate = 1.05;
    years = 1;
    printf("%s","Year\tPopulation\tIncrease\n");
    while(years <= 100){
        population = rate * presentGrowth;
        difference = population - presentGrowth;
        if(presentGrowth >= 4*present){
    		puts("Quadrupled");
    		printf("%d\t%d",years,presentGrowth);
    		printf("\t%d\n",difference);
        	break;
		}
        presentGrowth = population;
        years++;
    }
}
