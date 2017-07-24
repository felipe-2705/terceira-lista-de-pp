#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

int main()
{
    typedef struct palavras
    {
        char car[30];
        int n;
    } Palavra;
    char texto[1000];
    int k=0,i=0,j=0,l=0,maior;
    Palavra a[200];
    printf("Digite uma frase: ");
    scanf("%[^\n]s",texto);
    texto[strlen(texto)]='\0';
    for(j=0; k<strlen(texto); j++)
    {
        if (texto[k]==' ')
        {
            k++;
        }
        else
        {
            do
            {
                a[j].car[i]=texto[k];
                k++;
                i++;
            }
            while(texto[k]!=' '&&k<strlen(texto));
        }
        k++;
        a[j].car[i]='\0';
        i=0;
    }
    for(i=0; i<j; i++)
    {
        for(k=i; k<j; k++)
        {
            if(strcmp(a[i].car,a[k].car)==0)
            {
                a[i].n+=1;
            }
        }
    }
    for(i=j; i>=0; i--)
    {
        for(k=i-1; k>=0; k--)
        {
            if(strcmp(a[i].car,a[k].car)==0)a[i].n=0;
        }
    }
    for(i=0,maior=a[i].n; i<j; i++)
    {
        if (a[i].n>maior)maior=a[i].n;
    }
    printf("\nO maior numero de aparicoes de uma mesma palavra foi: %d\n",maior);
    printf("\nFoi encontrado com maior frequencia: ");
    for(i=0; i<j; i++)
    {
        if(a[i].n==maior)printf("'%s' ",a[i].car);
    }
    printf("\n");
    return 0;
}
