#include <stdio.h>
int main(void){
    int population = 0;
    int presentGrowth = 7951000;//printf_s("%d",presentGrowth);
    float rate = 1.05;
    int years = 1;
    printf_s("%s","Year\tPopulation\tIncrease\n");
    while(years <= 100){
    	printf_s("%d\t%d",years,presentGrowth);
        population = rate * presentGrowth;
        printf_s(" \t%d\n",population - presentGrowth);
        years++;
        presentGrowth = population;
    }
}
