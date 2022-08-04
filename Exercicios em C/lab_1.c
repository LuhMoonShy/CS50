#include <cs50.h>
#include <stdio.h>

int main(void){
    int ti, tf;
    int anos = 0;
    do{
        ti = get_int("Tamanho inicial: ");
    }
    while (ti < 9);
    do{
        tf = get_int("Tamanho final: ");
    }
    while (tf < ti);
    while (ti < tf){
        ti += (ti / 3 - ti / 4);
        anos++;
        if (ti >= tf){
            break;
        }
    }
    printf("Years: %i\n", anos);
return 0 ;
}