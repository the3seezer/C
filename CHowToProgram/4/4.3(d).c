#include <stdio.h>
int main(void){
    int x = 1;
    while(x <= 20){
        printf_s("%d\t",x);
        if(!(x % 5)){
            puts("");
        }
        ++x;
    }
}