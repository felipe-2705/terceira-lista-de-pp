#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y;
} Ponto;

typedef struct{
    Ponto *v;
    int n;
} Poligono;


float perimetro(Poligono p);
Ponto centroG(Poligono p);
float area(Poligono p);

int main()
{
    int i, n;
    Poligono p;
    printf("Quantos vertices possui o poligono? ");
    scanf("%d", &n);
    p.v = (Ponto*) calloc(n, sizeof(Ponto));
    p.n = n;
    for(i = 0; i < n; i++)
    {

        printf("Vertice %d\nx: ", i+1);
        scanf("%f", &p.v[i].x);
        printf("y: ");
        scanf("%f", &p.v[i].y);
    }
    printf("\n* Perimetro do poligono: %.2f\n",perimetro(p));
    printf("* Centro geometrico: %.2f,%.2f\n", centroG(p).x, centroG(p).y);
    printf("Area: %.2f", area(p));
    free(p.v);
    return 0;
}

float perimetro(Poligono p)
{
    int i;
    float tPerimetro = 0, aresta, deltaX, deltaY;

    for(i = 0; i < p.n-1; i++)
    {
        deltaX = p.v[i+1].x - p.v[i].x;
        deltaY = p.v[i+1].y - p.v[i].y;
        aresta = sqrt((deltaX*deltaX)+(deltaY*deltaY));
        tPerimetro += aresta;
    }
    if(i == p.n-1)
    {
        deltaX = p.v[i].x - p.v[0].x;
        deltaY = p.v[i].y - p.v[0].y;
        aresta = sqrt((deltaX*deltaX)+(deltaY*deltaY));
        tPerimetro += aresta;
    }
    return tPerimetro;
}

Ponto centroG(Poligono p)
{
    Ponto res;
    int i;
    float xcg = 0, ycg = 0;

    for(i = 0; i < p.n; i++)
    {
        xcg += p.v[i].x;
    }
    xcg /= p.n;

    for(i = 0; i < p.n; i++) {
        ycg += p.v[i].y;
    }
    ycg /= p.n;

    res.x = xcg;
    res.y = ycg;

    return res;
}

float area(Poligono p)
{
    int i;
    float area = 0;

    for(i = 0; i < p.n-1; i++)
    {
        area += ((p.v[i+1].x - p.v[i].x) * (p.v[i+1].y + p.v[i].y))/2;
    }
    return abs(area);
}
