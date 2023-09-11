/*
theBitRiddler
1:49 PM 
9/7/2023
Finding Errors
*/
#include <stdio.h>
int main(void) {
    /* (a)
    int *number;
    printf_s( "%d", *number );
     a pointer hasn't been asigned to the variable yet: warning 
     pointer has not been assigned to point to a location in memory.*/
    int number = 5;
    int *numberPtr;
    numberPtr = &number;
    printf_s( "%d\n", *numberPtr );

    /* (b) 
    float *realPtr;
    long *integerPtr;
    integerPtr = realPtr;
     incompatible pointer types. data types
     A pointer cannot be assigned to a different type, other than void *.*/
    float *realPtr;
    float *integerPtr;
    integerPtr = realPtr;

     /* (c)
     int *x, y;
     x = y;
      a pointer is asigned to a variable
       There are two possible solutions. 1) The indirection operator (*) is not distributive and would be required for y,
        which would result in a valid pointer assignment. 2) y as it is defined is a valid integer variable, and would require the
        address operator (&) in the pointer assignment statement.*/
      
    int * x, y;
     x = &y;
    
    /* (d)
    char s[] = "this is a character array";;
    int count;
    for ( ; *s != '\0'; s++ ) {
        printf_s( "%c", *s );
    }
     a constant pointers address can't be changed
      s should be defined as char *, a constant pointer cannot be moved.  */
    char s[] = "this is a character array\n";
    int count = 0;
    for ( ; *( s + count ) != '\0'; count++ ) {
        printf_s( "%c", * ( s + count ) );
    }
    /* (e)
    short *numPtr, result;
    void * genericPtr = numPtr;
    result = *genericPtr + 7;
     void pointer cant be indirected
      A void * pointer cannot be dereferenced. */
    short *numPtr, result;
    void * genericPtr = numPtr;
    result = *( ( short* ) genericPtr ) + 7; 
    // genericPtr = &result; numPtr = (short* ) genericPtr;

    /* (f)
    float z = 19.34;
    float zPtr = &z;
    printf_s( "%f\n", zPtr );
     a pointer is not direferenced
      zPtr is not defined as a pointer so it should be dereferenced as well. */

    float z = 19.34;
    float *zPtr = &z;
    printf_s( "%f\n", *zPtr );

    /* (g)
    char *t;
    printf_s( "%s\n", t );
     s has not been assigned a value, it does not point to anything. */
    char b[] = "Bachu";
    char *t = b;
    printf( "%c\n", *t ); // a pointer just points to the first element
} /* end main*/