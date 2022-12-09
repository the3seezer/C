#include <stdio.h>
int main(void){
    for(int i = 1;i <= 10;++i){
        if(i == 5){
            continue;
        }
        printf_s("%d   ",i);
    }
    puts("\nUsed continue to skip the value of 5");
}