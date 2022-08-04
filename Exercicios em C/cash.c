#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    float dinheiro;
    int moeda25 = 0, moeda10 = 0, moeda5 = 0, moeda1 = 0;
    
    do{
        dinheiro = get_float("Informe o valor do  troco: ");
    }while(dinheiro<=0);
    
    int centavos = round(dinheiro*100);
    
    while(centavos > 25 || centavos == 25){
        centavos = centavos - 25;
        moeda25 ++;
    }
    while(centavos > 10 || centavos == 10){
        centavos = centavos - 10;
        moeda10 ++;
    }
    while(centavos > 5 || centavos == 5){
        centavos = centavos - 5;
        moeda5 ++;
    }
    while(centavos > 1 || centavos == 1){
        centavos = centavos - 1;
        moeda1 ++;
    }
    printf("Serao %i moedas de 25 centavos.\n",moeda25);
    printf("Serao %i moedas de 10 centavos.\n",moeda10);
    printf("Serao %i moedas de 5 centavos.\n",moeda5);
    printf("Serao %i moedas de 1 centavo.\n",moeda1);    
    printf("Serao %i necessarias moedas para o troco.\n",moeda25 + moeda10 + moeda5 + moeda1);
return 0;    
}