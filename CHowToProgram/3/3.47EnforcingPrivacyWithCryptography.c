#include <stdio.h>
int main(void){
    int counter = 1;
    int fourd = 0;//the four digit
    int encripted = 0;
    int remainder = 0;
    printf_s("%s","Add a four digit integer\n");
    scanf("%d",&fourd);
    while(counter <= 4){
       remainder = fourd % 10;
       int addtoseven = remainder + 7;
       int remainderedr = addtoseven % 10;//printf_s("encripted: %d\n",remainderedr);
	   //to swap one with three and two with four
	   if(counter == 1){
	   	 encripted = encripted + remainderedr * 100;
	   }
	    if(counter == 2){
	   	 encripted = encripted + remainderedr * 1000;
	   }
	   if(counter == 3){
	   	 encripted = encripted + remainderedr;
	   }
	   if(counter == 4){
	   	 encripted = encripted + remainderedr * 10;
	   }
      // counter == 1 ? newfourd = newfourd  + remainderedr * 100 : counter == 2 ?  newfourd + remainderedr * 1000  : counter == 3 ? newfourd = newfourd + remainderedr  * 1 : counter == 4 ? newfourd = newfourd + remainderedr * 10 : newfourd ;
       //newfourd = newfourd * 10 + remainderedr; printf_s("%d\n",newfourd);
       fourd = fourd / 10;//printf_s("%d\n",fourd);//take off the last digit
       counter++;
    }
    printf_s("Encryption: %d\n",encripted);
}
