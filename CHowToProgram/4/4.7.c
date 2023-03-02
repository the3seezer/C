#include <stdio.h>
int main(void){
    int i = 1;

    for(;i <= 10;++i){
        if(i == 5){
            break;
        }
        printf_s("%d   ",i);
    }
    printf_s("\nBroke out of loop at i == %d\n",i);
}