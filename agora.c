#include <stdio.h>
#include <time.h>

int main (){
time_t tempo;
struct tm* local;

tempo=time(NULL);
local=localtime(&tempo);
printf(" hoje eh :%02d/%02d/%4d\n\n",local->tm_mday,(local->tm_mon)+1,(local->tm_year)+1900);
printf("horario-> %d:%d",local->tm_hour,local->tm_min);


return 0;}
