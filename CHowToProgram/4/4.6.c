#include <stdio.h>
int main(void){
    int counter = 1;

    do{
        printf_s("%d   ",counter);
    }
    while(++counter <= 5);
}