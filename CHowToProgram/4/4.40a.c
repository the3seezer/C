#include <stdio.h>
int main(void){
    int population = 0;
    int presentGrowth = 7951000;//printf_s("%d",presentGrowth);
    float rate = 1.05;
   // int growthRate = rate * presentGrowth;//	printf_s("%d",growthRate);
    printf("%s","Year\tPopulation\tIncrease\n");
    for(int years = 1;years <= 100;years++){
    	printf("%d\t%d",years,presentGrowth);
        population = rate * presentGrowth;
        printf(" \t%d\n",population - presentGrowth);
        presentGrowth = population;
    }
}
