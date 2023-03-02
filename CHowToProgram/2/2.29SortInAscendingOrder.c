#include <stdio.h>
int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	printf("Enter three digits\n");
	scanf("%d%d%d",&a,&b,&c);
	if(a < b && a < c){
		if(b < c){
			printf("%d\t%d\t%d",a,b,c);
		}
		if(c < b){
			printf("%d\t%d\t%d",a,c,b);
		}
	}
	if(b < a && b < c){
		if(a < c){
			printf("%d\t%d\t%d",b,a,c);
		}
		if(c < a){
			printf("%d\t%d\t%d",b,c,a);
		}
	}
	if(c < a && c < b){
		if(a < b){
			printf("%d\t%d\t%d",c,a,b);
		}
		if(b < a){
			printf("%d\t%d\t%d",c,b,a);
		}
	}
}
