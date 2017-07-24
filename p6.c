#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<math.h>
#define pi 3.1415

typedef struct coordenadas
{
    int graus;
    int minutos;
    float segundos;
    char direcao;
} Coodenadas;
typedef struct localizacao
{
    Coodenadas latitude;
    Coodenadas longitude;
} Localizacao;
typedef struct cidade
{
    char nome[20];
    Localizacao local;
} Cidade;

void cadastrar(Cidade Ccidade[], int *n);
void mostrar(Cidade Ccidade[],int *n);
double distancia(Cidade CcidadeA, Cidade CcidadeB);
void tour(Cidade Ccidade[],int *n);

int main()
{
    int i=0,n=0,opcao;
    Cidade Ccidade[20];
    do
    {
        system("cls");
        printf("Menu Principal\n\n");
        printf("1 - Cadastrar localidade\n");
        printf("2 - Mostrar locais cadastrados\n");
        printf("3 - Definir Tour\n");
        printf("4 - SAIR");
        printf("\n\nDigite o numero correspondente o que deseja fazer: ");
        scanf("%d",&opcao);
        /*
        Ccidade[0].nome[0] = 'P';
        Ccidade[0].nome[1] = '\0';
        Ccidade[0].local.latitude.direcao = 'S';
        Ccidade[0].local.latitude.graus = 18;
        Ccidade[0].local.latitude.minutos = 54;
        Ccidade[0].local.latitude.segundos = 58.4;
        Ccidade[0].local.longitude.direcao = 'W';
        Ccidade[0].local.longitude.graus = 48;
        Ccidade[0].local.longitude.minutos = 16;
        Ccidade[0].local.longitude.segundos = 22.2;
        Ccidade[1].nome[0]= 'U';
        Ccidade[1].nome[1]= '\0';
        Ccidade[1].local.latitude.direcao = 'S';
        Ccidade[1].local.latitude.graus = 18;
        Ccidade[1].local.latitude.minutos = 56;
        Ccidade[1].local.latitude.segundos = 20.6;
        Ccidade[1].local.longitude.direcao = 'W';
        Ccidade[1].local.longitude.graus = 46;
        Ccidade[1].local.longitude.minutos = 59;
        Ccidade[1].local.longitude.segundos = 41.3;
        */
        switch(opcao)
        {
        case 1:
            cadastrar(Ccidade,&n);
            break;
        case 2:
            mostrar(Ccidade,&n);
            break;
        case 3:
            tour(Ccidade,&n);
            break;
        default:
            break;
        }
    }
    while(opcao!=4);
    return 0;
}
void mostrar(Cidade Ccidade[],int *n)
{
    int i;
    for(i=0; i<*n; i++)
    {
        printf("%d - ",i+1);
        printf("%s ",strupr(Ccidade[i].nome));
        printf("%d ",Ccidade[i].local.latitude.graus);
        printf("%d'",Ccidade[i].local.latitude.minutos);
        printf("%.1f\"",Ccidade[i].local.latitude.segundos);
        printf("%c",toupper(Ccidade[i].local.latitude.direcao));
        printf("  %d ",Ccidade[i].local.longitude.graus);
        printf("%d'",Ccidade[i].local.longitude.minutos);
        printf("%.1f\"",Ccidade[i].local.longitude.segundos);
        printf("%c",toupper(Ccidade[i].local.longitude.direcao));
        printf("\n");
    }
    if(*n==0)printf("Nenhuma cidade cadastrada\n");
    printf("\nTecle ENTER para continuar...");
    getchar();
    getchar();
}
void cadastrar(Cidade Ccidade[], int *n)
{
    *n+=1;
    printf("Digite o nome da cidade que deseja cadastrar: ");
    scanf("%s",Ccidade[*n-1].nome);
    printf("Digite a Latitude da cidade. Ex:22 51 18 S:\n");
    scanf("%d",&Ccidade[*n-1].local.latitude.graus);
    scanf("%d",&Ccidade[*n-1].local.latitude.minutos);
    scanf("%f",&Ccidade[*n-1].local.latitude.segundos);
    getchar();
    scanf("%c",&Ccidade[*n-1].local.latitude.direcao);
    printf("Digite a Longitude da cidade. Ex:58 24 43 W:\n");
    scanf("%d",&Ccidade[*n-1].local.longitude.graus);
    scanf("%d",&Ccidade[*n-1].local.longitude.minutos);
    scanf("%f",&Ccidade[*n-1].local.longitude.segundos);
    getchar();
    scanf("%c",&Ccidade[*n-1].local.longitude.direcao);
}
double distancia(Cidade CcidadeA, Cidade CcidadeB)
{
    double dist,r=6372.795477598,latA,latB,lonA,lonB;
    latA=((((CcidadeA.local.latitude.segundos/60+CcidadeA.local.latitude.minutos)/60)+CcidadeA.local.latitude.graus)*pi)/180;
    latB=((((CcidadeB.local.latitude.segundos/60+CcidadeB.local.latitude.minutos)/60)+CcidadeB.local.latitude.graus)*pi)/180;
    lonA=((((CcidadeA.local.longitude.segundos/60+CcidadeA.local.longitude.minutos)/60)+CcidadeA.local.longitude.graus)*pi)/180;
    lonB=((((CcidadeB.local.longitude.segundos/60+CcidadeB.local.longitude.minutos)/60)+CcidadeB.local.longitude.graus)*pi)/180;
    dist = (r*acos(sin(latA)*sin(latB)+cos(latA)*cos(latB)*cos(lonA-lonB)));
    return dist;
}
void tour(Cidade Ccidade[],int *n)
{
    int n1,n2,ant,cont=0;
    double dist=0;
    mostrar(Ccidade,n);
    if(*n>=2)
    {
        printf("Digite os numeros correspondentes as cidades na ordem em que deseja passar por elas(separados por espaco).\nOBS: O algarismo 0 indica o final do tour.\n");
        do
        {
            scanf("%d",&n1);
            if(n1!=0)
            {
                if(cont==0)
                {
                    ant=n1;
                    cont++;
                }
                else
                {
                    printf("Ant: %d\tdist: %d\n",ant,n1);
                    dist+=distancia(Ccidade[ant-1],Ccidade[n1-1]);
                    ant=n1;
                }
            }
        }
        while(n1!=0);
        printf("O tour pelas cidades totaliza %.1lf km",dist);
        printf("\nTecle ENTER para continuar...");
        getchar();
        getchar();
    }
    else
    {
        printf("Quantidade insuficiente de cidades cadastradas\nTecle ENTER para continuar...");
        getchar();
    }
}
