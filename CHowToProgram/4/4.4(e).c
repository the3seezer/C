#include <stdio.h>
int main(void){
    for(int x = 1;x <= 20;++x){
        printf_s("%d\t",x);
        if(!(x % 5)){
            puts("");
        }
    }
}