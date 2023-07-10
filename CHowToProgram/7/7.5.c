/*
theBitRiddler
7/10/2023
11:20
7.5
*/
#include <stdio.h>
int main( void ) {
    /*(a)
    void exchange( float * x, float * y )
    */

    /*(b)*/
    void exchange( float * x, float * y );

    /*(c)
    int evaluate( int x, int (*polyPtr)(int) )
    */
    
    /*(d)*/
    int evaluate( int x, int (*polyPtr)(int) );

}

/* (b)*/ //function definition
void exchange( float *x , float *y ) {
    int hold = *x;
    * x = * y;
    * y = hold;
}

/* (d)*/ //function definition
int evaluate( int x, int (*polyPtr)(int)) {

   return (*polyPtr)(x);

}

int poly( int a ) {
    return a;
}
