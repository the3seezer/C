#include <stdio.h>
int main(void){
    int value = 0;
    printf_s("%s\n", "Enter either value");
    printf_s("%s\n", "enter -1 to end");
    while (scanf_s("%d", &value) != -1){
        switch(value % 2){
            case 0:
            printf_s("%s\n","Even number");
            break;
            case 1:
            printf_s("%s\n","Odd number");
            break;
        }
    }
}