#include <stdio.h>

int main(void){
    double p = 1000;
    double r = .05;
    double a = 0;
    double t_i = 1;//total annual interest
    double i = 1 + r;//The interest bracket(1 + r)
    printf("%4s%21s\n","Year","Amount on deposit");
    for (int n = 1;n <= 10;++n){//the number of years
        t_i *= i;
        a = p * t_i;
        printf("%4d%21.2f\n",n, a);
    }
    
    
}
