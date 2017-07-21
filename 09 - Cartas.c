#include <stdlib.h>
#include <stdio.h>
 enum Naipe {Paus, Copas, Ouros, Espadas };
 enum Face { As=1, Dois, Tres, Quatro, Cinco, Seis, Sete, Oito, Nove, Dez, Valete, Dama, Rei};
typedef struct carta
{
    enum Naipe naipe;
    enum Face face;
} Carta ;
void showCarta(Carta c);
void lerCarta(Carta *c);
int ComparaCartas(Carta c1, Carta c2);
int main(int argc, char *argv[])
{
    Carta c1,c2;
    int r;
    lerCarta(&c1);
    lerCarta(&c2);
    showCarta(c1);
    showCarta(c2);
    r = ComparaCartas(c1,c2);
    if(r==0) printf("Cartas iguais\n");
    else if(r>0) printf("Carta c1 eh maior\n");
    else printf("Carta c2 eh maior\n");
}
void showCarta(Carta c)
{
    char* faces[] = {"", "As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
    char* naipes[] = {"Paus","Copas", "Ouros","Espadas"};
    printf("%s de %s\n",faces[c.face],naipes[c.naipe]);
}
void lerCarta(Carta *c)
{
    printf("Definir carta:\n");
    printf("Digite o valor de face: ");
    scanf("%d",&c->face);
    printf("Digite o valor do naipe: ");
    scanf("%d",&c->naipe);
}
int ComparaCartas(Carta c1, Carta c2){
    int soma1=0, soma2=0;
    soma1 = c1.naipe + c1.face;
    soma2 = c2.naipe + c2.face;

    if(soma1>soma2)
        return 1;
    else
        if(soma2>soma1)
            return -1;
        else
            return 0;
}
