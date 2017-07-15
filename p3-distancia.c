#include <stdio.h>
#include <math.h>

// definiçao do tipo struct
typedef struct Ponto{
float x;
float y;

}ponto;

//declaraçao da funçao distancia euclidiana.

float distan(ponto,ponto);

int main (){
ponto p1,p2;

printf("Distancia Euclidiana \n\n");
printf("digite dois pontos do plano cartesiano:\n");
printf("ponto 1:\n");
printf("digite x:");
scanf("%f",&p1.x);
printf("digite y:");
scanf("%f",&p1.y);
printf("ponto 2:\n");
printf("digite x:");
scanf("%f",&p2.x);
printf("digitey:");
scanf("%f",&p2.y);

system ("cls");

printf("a distancia entre os pontos (%.2f,%.2f) e (%.2f,%.2f):\n",p1.x,p1.y,p2.x,p2.y);

printf("distancia :%.2f",distan(p1,p2));

return 0;}
//corpa da funçao distancia

float distan(ponto p1,ponto p2){
float dist;
dist=sqrt(((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
return dist;
}
