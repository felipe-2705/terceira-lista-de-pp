#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int p;
    int q;
} Racional;

int mdc (int dividendo, int divisor);
Racional simplifica(int a, int b);

int mdc (int dividendo, int divisor)
{
    int z,mdc;

    while ( z !=0 )
    {
        z = dividendo % divisor;
        dividendo = divisor;
        divisor = z;
    };

    mdc = dividendo;

    return(mdc);
}
Racional simplifica(int a, int b){
    int mdc1;
    Racional r1;
    mdc1 = mdc(4,12);

    r1.p= 4/mdc1;
    r1.q= 12/mdc1;

    return(r1);
}

int main(int argc, char *argv[])
{
    Racional r;
    r = simplifica(4,12);
    printf("%d/%d\n",r.p,r.q);

    return 0;
}
