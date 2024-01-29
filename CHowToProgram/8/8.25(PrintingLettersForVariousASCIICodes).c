/*
    theBitRiddler
    1/27/2024
    3:58 PM
    Numeric code representation
    ASCII Character Set
     0    1    2    3    4    5    6    7    8    9
0   nul  soh  stx  etx  eot  enq  ack  bel   bs   ht
1    lf   vt   ff   cr   so   si  dle  dc1  dc2  dc3
2   dc4  nak  syn  etb  can   em  sub  esc   fs   gs
3    rs   us   sp   !    "    #    $    %    &    ‘
4    (    )    *    +    ,    -    .    /    0    1
5    2    3    4    5    6    7    8    9    :    ;
6    <    =    >    ?    @    A    B    C    D    E
7    F    G    H    I    J    K    L    M    N    O
8    P    Q    R    S    T    U    V    W    X    Y
9    Z    [    \    ]    ^    _    ’    a    b    c
10   d    e    f    g    h    i    j    k    l    m
11   n    o    p    q    r    s    t    u    v    w
12   x    y    z    {    |    }    ~   del
*/
#include <stdio.h>
int main( void ) {
    int code = 0;       // code input by user

    // Enter a code to see the it's character
    printf( "%s\n", "ASCII codes\n"
    "     0    1    2    3    4    5    6    7    8    9\n"
    "0   nul  soh  stx  etx  eot  enq  ack  bel   bs   ht\n"
    "1    lf   vt   ff   cr   so   si  dle  dc1  dc2  dc3\n"
    "2   dc4  nak  syn  etb  can   em  sub  esc   fs   gs\n"
    "3    rs   us   sp   !   \"     #    $    \%    &    \'\n"
    "4    (    )    *    +    ,    -    .    /    0    1\n"
    "5    2    3    4    5    6    7    8    9    :    ;\n"
    "6    <    =    >    ?    @    A    B    C    D    E\n"
    "7    F    G    H    I    J    K    L    M    N    O\n"
    "8    P    Q    R    S    T    U    V    W    X    Y\n"
    "9    Z    [    \\    ]    ^    _   \'    a    b    c\n"
    "10   d    e    f    g    h    i    j    k    l    m\n"
    "11   n    o    p    q    r    s    t    u    v    w\n"
    "12   x    y    z    {    |    }    ~   del\n" );

    printf( "%s", "Enter ASCII code ( EOF to end ): " );

    while ( scanf( "%d", &code ) != EOF ) {

        if ( code >= 0 && code <= 255 )
            printf( "The character: '%c'\n", code );
        else
            printf( "%s\n", "Invalid character code! " );

        printf( "%s", "Enter ASCII code ( EOF to end ): " );
    } // end while
    
    return 0; // indicate termination successful
}