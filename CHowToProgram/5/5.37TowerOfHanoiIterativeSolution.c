//theBitRiddler
//11-3-2022
//5:36pm
//tower of Hanoi Iterative Solution
#include <stdio.h>
#include <math.h>

void Tower_Hanoi(int ,int ,int ,int);

int main(void){
	puts("Enter number of disks: ");
	int disks = 0;
	scanf("%d",&disks);
	int s = 1,a = 2,d = 3;
	Tower_Hanoi(disks,s,a,d);
}

void Tower_Hanoi(int n,int s,int a,int d){
	int move = 0;//Couts each move
	int ThreeMoves = 1;//couts after every three moves:After every 'i%3 == 0'
	int EvenThreeMoves = 0;//Couts when 'ThreeMoves' is even: "ThreeMoves % 2 == 0"
	/* then look for odd 'EvenThreeMoves' and even 'EvenThreeMoves'...
	So when its odd swap 'i%3 == 2' and 'i%3 == 0'
	and when its even swap 'i%3 == 1' and 'i%3 == 2' */
	for(int i = 1;i <= (pow(2,n) - 1);i++){
		if(n%2){//Odd
			if(i%3 == 1){
				if(EvenThreeMoves % 2 == 0 && ThreeMoves % 2 == 0){
					s = s + d;
					d = s - d;
					s = s - d;
				}
				printf("%d -> %d\n",s,d);
				if(EvenThreeMoves % 2 == 0 && ThreeMoves % 2 == 0){
					s = s + d;
					d = s - d;
					s = s - d;
				}
			}
			if(i%3 == 2){
				if(EvenThreeMoves % 2 == 0 && ThreeMoves % 2 == 0){
					s = s + a;
					a = s - a;
					s = s - a;
				}
				if(EvenThreeMoves % 2 == 1 && ThreeMoves % 2 == 0){
					s = s + a;
					a = s - a;
					s = s - a;
				}
				printf("%d -> %d\n",s,a);
				if(EvenThreeMoves % 2 == 0 && ThreeMoves % 2 == 0){
					s = s + a;
					a = s - a;
					s = s - a;
				}
				if(EvenThreeMoves % 2 == 1 && ThreeMoves % 2 == 0){
					s = s + a;
					a = s - a;
					s = s - a;
				}
			}
			if(i%3 == 0){
				if(EvenThreeMoves % 2 == 1 && ThreeMoves % 2 == 0){
					d = d + a;
					a = d - a;
					d = d - a;
				}
				printf("%d -> %d\n",d,a);
				if(EvenThreeMoves % 2 == 1 && ThreeMoves % 2 == 0){
					d = d + a;
					a = d - a;
					d = d - a;
				}
				++ThreeMoves;
				if(ThreeMoves % 2 == 0){
					++EvenThreeMoves;
				}
			}
		}
		else{//even
			if(i%3 == 1){
				if(EvenThreeMoves % 2 == 0 && ThreeMoves % 2 == 0){
					s = s + a;
					a = s - a;
					s = s - a;
				}
				printf("%d -> %d\n",s,a);
				if(EvenThreeMoves % 2 == 0 && ThreeMoves % 2 == 0){
					s = s + a;
					a = s - a;
					s = s - a;
				}
			}
			if(i%3 == 2){
				if(EvenThreeMoves % 2 == 0 && ThreeMoves % 2 == 0){
					s = s + d;
					d = s - d;
					s = s - d;
				}
				if(EvenThreeMoves % 2 == 1 && ThreeMoves % 2 == 0){
					s = s + d;
					d = s - d;
					s = s - d;
				}
				printf("%d -> %d\n",s,d);
				if(EvenThreeMoves % 2 == 0 && ThreeMoves % 2 == 0){
					s = s + d;
					d = s - d;
					s = s - d;
				}
				if(EvenThreeMoves % 2 == 1 && ThreeMoves % 2 == 0){
					s = s + d;
					d = s - d;
					s = s - d;
				}
			}
			if(i%3 == 0){
				if(EvenThreeMoves % 2 == 1 && ThreeMoves % 2 == 0){
					a = a + d;
					d = a - d;
					a = a - d;
				}
				printf("%d -> %d\n",a,d);
				if(EvenThreeMoves % 2 == 1 && ThreeMoves % 2 == 0){
					a = a + d;
					d = a - d;
					a = a - d;
				}
				++ThreeMoves;
				if(ThreeMoves % 2 == 0){
					++EvenThreeMoves;
				}
			}
		}
	}
}
