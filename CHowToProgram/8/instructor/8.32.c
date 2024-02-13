/*
    theBitRiddler
    2/2/2024
    10:41 PM
    functions in Fig. 8.30 for manipulating blocks of memory.
*/
#include <stdio.h>
void *memCpy( void *, const void *, size_t );
void *memMove( void *, const void *, size_t );
int memCmp( const void *, const void *, size_t );
void *memChr( const void *, int , size_t );
void *memSet( void *, int, size_t );
int main( void ) {
    char s[] = "";
    char *s1 = "Bachu Ally";
    char *s2 = "Ally Chamani";
    int s3[10] = { 0 };
    int s4[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    float s5[10] = { 0.0 };
    float s6[10] = { 1, 2.2, 3, 4.4, 5, 6.6, 7, 8.8, 9, 10.1 };
    double s7[10] = { 0.0 };
    double s8[10] = { 1, 2.2, 3, 4.4, 5, 6.6, 7, 8.8, 9, 10.1 };
    printf( "The strings: s \"%s\"", s );
    printf( " and s1 \"%s\"\nThe resulting object \"%s\"\n\n", s1, (char *) memCpy( s, s1, 7 ) );
    
    return 0; // indicate termination successful
} /* end main */
void *memCpy( void * s1, const void * s2, size_t n ) {
    char *s3 = s1;
    char *s4 = s2;
    // copy s2 to s1 n bytes of memory
    for ( size_t i = 0; i < n; i++ ) { 
        *s3++ = *s4++;
    } // end for
    return s1;
} /* end function memCpy */
void *memMove( void * s1, const void * s2, size_t n ) {

} /* end function memMove */
int memCmp( const void * s1, const void * s2, size_t n ) {

} /* end function memCmp */
void *memChr( const void * s1, int c, size_t n ) {

} /* end function memChr */
void *memSet( void * s1, int c, size_t n ) {

} /* end function memSet */