#include <stdio.h>
int main(void){
    int sum = 0;
    for (int count = 1; count <= 99; ++count){
        if(count % 2){
            sum += count;
        }
    }
    printf_s("Sum of odd integers: %d",sum);
}