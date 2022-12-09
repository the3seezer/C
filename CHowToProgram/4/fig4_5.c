#include <stdio.h>
int main(void){
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;
    int dCount = 0;
    int eCount = 0;
    int fCount = 0;
    
    puts("Enter letter to find grade");
    puts("Enter EOF character to end the process");

    int grade = 0;
    while ((grade = getchar()) != EOF){
    	
        switch(grade){
            case 'A':
            case 'a':
            ++aCount;
            break;
            case 'B':
            case 'b':
            ++bCount;
            break;
            case 'C':
            case 'c':
            ++cCount;
            break;
            case 'D':
            case 'd':
            ++dCount;
            break;
            case 'E':
            case 'e':
            ++eCount;
            break;
            case 'F':
            case 'f':
            ++fCount;
            break;
            case '\n':
            case '\t':
            case  ' ':
            break;
            default:
            printf("%s","Incorrect letter grade entered");
            puts("Enter a new grade!");
            break;
        }
    }
    puts("\n totals of each grade are:");
    printf("A: %d\n",aCount);
    printf("B: %d\n",bCount);
    printf("C: %d\n",cCount);
    printf("D: %d\n",dCount);
    printf("E: %d\n",eCount);
    printf("F: %d\n",fCount);
}
