#include <stdio.h>
#include <math.h>
int main(void){
    double p = 1000.0;
    double r = .05;
    printf("%4s%21s\n","Year","Amount on deposit");
    for(int year = 1;year <= 10;++year){
        double amount = p * pow(1 + r,year);
        printf("%4d%21.2f\n",year,amount);
    }
}
