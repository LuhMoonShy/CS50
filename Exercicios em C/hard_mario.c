#include <stdio.h> 
#include <cs50.h>
void arvore (int altura);

int  main(void){
  int altura = 0;
  do{
    altura = get_int("Altura : ");
  }
  while (altura < 1 || altura > 8);
  arvore(altura);
  
  return 0;
}

void arvore(int altura){  
  for(int i = altura; i > 0; i--){
    for (int j = 1;j <= altura;j++){
      if(i > j){
        printf(" ");
      }
      else{
        printf("#");
      }
    }
    printf("  ");
    
    for(int k = altura; k > 0;k--){
      if(i < k || i == k){
        printf("#");
      }
    }
    printf("\n");
  }
}