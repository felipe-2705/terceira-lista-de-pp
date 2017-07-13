#include <stdio.h>
#include<stdlib.h>
#include<math.h>

//declaração do tipo Complexo
typedef struct Complexo{
    float x;
    float y;
    float i;

} complexo;

//declaraçao das funçoes
//funçao de soma de dois complexos.
complexo complex_ad(complexo ,complexo );

//funçao de subtraçao de dois complexos
complexo complex_sub(complexo ,complexo );

//funçao de multiplicaçao de dois complexos.
complexo complex_mult(complexo ,complexo);

//função de divisao de dois complexos
complexo complex_div(complexo,complexo);

//funçao modulo
float modulo(complexo);

//funçao de menu.
int menu();

int main ()
{
    complexo C[2];
    float mod;
    int op=0,count;
//declarando o valor de i.
    C[0].i=sqrt(-1);
    C[1].i=sqrt(-1);
    while(op!=6)
    {

        op=menu();
        switch (op)
        {

        case(1):
            system ("cls");
            count=0;
            while(count<2)
            {
                printf("digite o %d numero complexo\n",count+1);
                printf("digite x:");
                scanf("%f",&C[count].x);
                printf("digite y:");
                scanf("%f",&C[count].y);
                ++count;
            }
            C[2]=complex_ad(C[0],C[1]);
            printf("soma=%.2f + %.2f*i\n",C[2].x,C[2].y);
            system("pause");
            break;
        case(2):
            system ("cls");
            count=0;
            while(count<2)
            {
                printf("digite o %d numero complexo\n",count+1);
                printf("digite x:");
                scanf("%f",&C[count].x);
                printf("digite y:");
                scanf("%f",&C[count].y);
                ++count;
            }
            C[2]=complex_sub(C[0],C[1]);
            printf("subtacao = %.2f + %.2f*i\n",C[2].x,C[2].y);
            system("pause");
            break;
        case(3):
             system ("cls");
            count=0;
            while(count<2)
            {
                printf("digite o %d numero complexo\n",count+1);
                printf("digite x:");
                scanf("%f",&C[count].x);
                printf("digite y:");
                scanf("%f",&C[count].y);
                ++count;
            }
            C[2]=complex_mult(C[0],C[1]);
            printf("multiplicacao=%.2f + %.2f*i\n",C[2].x,C[2].y);
            system("pause");
            break;
        case(4):
             system ("cls");
            count=0;
            while(count<2)
            {
                printf("digite o %d numero complexo\n",count+1);
                printf("digite x:");
                scanf("%f",&C[count].x);
                printf("digite y:");
                scanf("%f",&C[count].y);
                ++count;
            }
            C[2]=complex_div(C[0],C[1]);
            printf("divisao = %.2f + %.2f*i\n",C[2].x,C[2].y);
            system("pause");
            break;
        case(5):
             system ("cls");
            printf("digite o numero complexo \n");
            printf("digite o valor x:");
            scanf("%f",&C[0].x);
            printf("digite o valor y:");
            scanf("%f",&C[0].y);
            mod=modulo(C[0]);
            printf("modulo=%.2f\n",mod);
            system("pause");
            break;
            case(6):break;
        default:
            system ("cls");
            printf("Operacao desconhecida...\n");
            system ("pause");
            break;

        }


    }

    return 0;
}
//Corpo das funções
//fuçao de menu
int menu()
{
    int op;
    system("cls");
    printf("numero complexo do tipo C=x+y*i.\n\n");

    printf("Menu de Operacoes com numeros complexos:\n");
    printf("adicao[1]\n");
    printf("subtracao[2]\n");
    printf("multiplicacao[3]\n");
    printf("divisao[4]\n");
    printf("modulo[5]\n");
    printf("sair[6]\n\n");
    printf("Escolha uma operacao->");
    fflush(stdin);
    scanf("%d",&op);
    return op;
}

//funçao de soma corpo

 complexo complex_ad(complexo C1,complexo C2)
{
complexo resp;
resp.x=C1.x+C2.x;
resp.y=C1.y+C2.y;
resp.i=sqrt(-1);
return resp;
}

//funçao de subtraçao corpo

complexo complex_sub(complexo C1,complexo C2){
complexo resp ;
resp.x=C1.x-C2.x;
resp.y=C1.y-C2.y;
resp.i=sqrt(-1);
return resp;
}

//funçao de multiplicaçao corpo

 complexo complex_mult(complexo C1,complexo C2){
complexo resp;
resp.x=(C1.x*C2.x)-(C1.y*C2.y);
resp.y=(C1.x*C2.y)+(C1.y*C2.x);
resp.i=sqrt(-1);
return resp;
}
//funçao de divisao corpo

complexo complex_div(complexo C1,complexo C2){
complexo resp;
resp.x=((C1.x*C2.x)+(C1.y*C2.y))/(C2.x*C2.x+C2.y*C2.y);
resp.y=((C1.y*C2.x)-(C1.x*C2.y))/(C2.x*C2.x+C2.y*C2.y);
resp.i=sqrt(-1);
return resp;
}

//funçao modulo

float modulo(complexo C){
float resp;
resp=sqrt(C.x*C.x+C.y*C.y);
return resp;
}
