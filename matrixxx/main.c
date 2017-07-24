#include <stdio.h>
#include <stdlib.h>

typedef struct matriz
{
    int *elem;
    int lin;
    int col;
    char nome[20];
} Matriz;

Matriz *criar_matriz(int m, int n);
void liberar_matriz (Matriz *ma);
void ler_matriz( Matriz *ma);
void print_matriz(Matriz *ma);
void mul_matriz(Matriz *a, Matriz *b);
void soma_matriz(Matriz *a, Matriz *b);

void liberar_matriz (Matriz *ma)
{
    free(ma-> elem);
    free(ma);
}

Matriz *criar_matriz(int m, int n)
{
    Matriz* ma= (Matriz*)malloc(sizeof(Matriz));

    if (ma== NULL)
    {
        printf("ERROR.");
        exit(1);
    }

    ma-> lin = m;
    ma-> col= n;

    ma->elem= (int*)malloc(m*n*sizeof(int));

    return (ma);

}

void ler_matriz( Matriz *ma)
{
    int m,n,i,j, contador=0, v=0,r;

    m = ma->lin;
    n= ma->col;

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            if (i != 0)
            {
                printf("Digite o valor do termo %i%i: \n", i,j);
                scanf("%i", &v);
                ma-> elem[j]= v;
                contador++;


            }

            else
            {
                printf("Digite o valor do termo %i%i: \n", i,j);
                scanf("%i", &v);
                ma-> elem[j + contador] = v;
                r = contador;
                contador += r;

            }
        }
    }

}

void soma_matriz(Matriz *a, Matriz *b)
{
    int i1,j1,i2,j2,k,l,contador = 0,r;
    Matriz *c;

    c= (Matriz*)malloc(sizeof(Matriz));

    i1 = a->lin;
    j1 = a-> col;
    i2= b-> lin;
    j2= b -> col;

    if ((i1 != i2) || (j1 != j2))
    {
        printf("ERROR.");
        exit (1);

    }

    c-> elem = (int*)malloc(i1*j1*sizeof(int));

    for (k=0; k<i1; k++)
    {
        for (l=0; l<j1; l++)
        {
            if (k==0)
            {
                c-> elem[l] = a-> elem[l] + b->elem[l];
                contador++;
            }

            else
            {
                c-> elem [l + contador] = a-> elem[l + contador] + b->elem[l + contador];
                r = contador;
                contador += r;
            }
        }

    }



}

void mul_matriz(Matriz *a, Matriz *b)
{
    int aux,i1,j1,i2,j2,k,l,contador = 0;
    Matriz *c;

    c= (Matriz*)malloc(sizeof(Matriz));

    i1 = a->lin;
    j1 = a-> col;
    i2= b-> lin;
    j2= b -> col;

    if (j1 != i2)
    {
        printf("ERROR.");
        exit (1);

    }

    c-> elem = (int*)malloc(i1*j1*sizeof(int));

    for (k=0; k<i1; k++)
    {
        for (l=0; l<j2; l++)
        {
            aux = 0;

            for (contador = 0; contador < j1; contador++)
            {
                aux += aux + a->elem[k + contador] * b->elem[k+ contador];
            }

            c-> elem[k + l] = aux;
        }
    }


}

void print_matriz(Matriz *ma)
{
    int m,n,i,j;

    m = ma-> lin;
    n= ma-> col;

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("%i", ma-> elem[i+j]);
        }
        printf("\n");
    }

    printf("Linha: %i \n", m);
    printf("Colunas: %i \n", n);
}




int main()
{
    int i1,j1,i2,j2, conta1,conta2;

    Matriz *a, *b;

    do {
        printf("1- Liberar matriz\n");
        printf("2- Criar matriz \n");
        printf("3- Ler matriz \n");
        printf("4- Somar matriz\n");
        printf("5- Multiplicar matriz\n");
        printf("6- Printar matriz\n");
        printf("7- Sair\n");

        scanf("%i", &conta1);

        if (conta1 == 1){
            liberar_matriz (a);
            liberar_matriz (b);
        }

        if (conta1 == 2){
            printf ("Digite a quantidade de linhas da matriz 1: ");
            scanf("%i", &i1);

            printf ("Digite a quantidade de colunas da matriz 1: ");
            scanf("%i", &j1);

            a= criar_matriz(i1,j1);

            printf ("Digite a quantidade de linhas da matriz 1: ");
            scanf("%i", &i2);

            printf ("Digite a quantidade de colunas da matriz 1: ");
            scanf("%i", &j2);

            b= criar_matriz(i2,j2);

        }

        if (conta1== 3){
            do {
                printf("Qual matriz voce quer ler? Digite 1 para matriz a ou 2 para matriz b");
                scanf("%i", &conta2);
            } while ((conta2 != 1) && (conta2!= 2));

            if (conta2== 1){
                ler_matriz(a);
            }

            if (conta2== 2){
                ler_matriz(b);
            }
        }

        if (conta1== 4){
        soma_matriz(a,b);
        }

        if (conta1== 5){
        mul_matriz(a,b);
        }

        if (conta1== 6){
            do{
            printf("Qual matriz voce quer printar? Digite 1 para matriz a ou 2 para matriz b" );
            scanf("%i", &conta2);
            } while ((conta2 != 1) && (conta2 != 2));

            if (conta2== 1){
                print_matriz(a);
            }

            if (conta2== 2){
                print_matriz(b);
            }
        }

    } while (conta1!= 7);

    return 0;
}
